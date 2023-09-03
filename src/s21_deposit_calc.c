#include "s21_smart_calc.h"

static int days_before_month[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR,  BEFORE_JANUARY,   BEFORE_FEBRUARY, BEFORE_MARCH,
    BEFORE_APRIL,   BEFORE_MAY,       BEFORE_JUNE,     BEFORE_JULY,
    BEFORE_AUGUST,  BEFORE_SEPTEMBER, BEFORE_OCTOBER,  BEFORE_NOVEMBER,
    BEFORE_DECEMBER};

static int month_capacity[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

deposit_result *
s21_deposit_calc(double deposit_amount, double term, double interest_rate,
                 double tax_rate, int payout_frequency,
                 int interest_capitalization, withdrawals *replenishment_list,
                 withdrawals *part_withdrawal_list, datum *start_date) {
  //   deposit *deposit_data = calloc(UNO, sizeof(deposit));
  deposit_result *outcome = NULL;
  int current_year_type = FALSE;
  int remaining_days = FALSE;
  int extra_day_from_leap_year = FALSE;
  int temp_date = FALSE;
  int period_start = FALSE;

  while (term > FALSE) {
    if (!current_year_type) {
      is_leap_year(start_date->year) ? current_year_type = LEAP_YEAR
                                     : (current_year_type = NOT_LEAP_YEAR);
    }
    switch (payout_frequency) {
    case PER_DAY:
      per_day_calculate(start_date, &current_year_type,
                        &extra_day_from_leap_year, interest_rate,
                        &remaining_days, &term, &deposit_amount);
      break;
    case PER_WEEK:
      per_week_calculate(start_date, &current_year_type,
                         &extra_day_from_leap_year, interest_rate,
                         &remaining_days, &term, &deposit_amount,
                         &payout_frequency);
      break;
    case PER_MONTH:
      per_month_calculate(start_date, &term, &deposit_amount,
                          &current_year_type, interest_rate,
                          &extra_day_from_leap_year, &temp_date, &period_start,
                          &payout_frequency, &remaining_days, FALSE);
      break;
    case PER_QUOTER:
      per_quoter_calculate(start_date, &term, &deposit_amount,
                           &current_year_type, interest_rate,
                           &extra_day_from_leap_year, &temp_date, &period_start,
                           &payout_frequency, &remaining_days, PER_QUOTER);
      break;
    case PER_YEAR:
      //   per_year_calulate();
      break;
    case AT_THE_END_OF_TERM:
      //   end_of_term_calculate();
      break;
    }
  }

  printf("\n\n%lf\n\n", deposit_amount);

  return outcome;
}

void per_day_calculate(datum *start_date, int *current_year_type,
                       int *extra_day_from_leap_year, double interest_rate,
                       int *remaining_days, double *term,
                       double *deposit_amount) {
  double payment_of_period = FALSE;
  double day_period_interest_rate = FALSE;
  int residue_period = FALSE;
  double residue_period_interest = FALSE;

  residue_period = calculate_remain_days_from_biggets_periods(
      start_date, remaining_days, term, current_year_type);

  if (!residue_period) {
    plus_day_period(start_date, current_year_type);
    day_period_interest_rate =
        calculate_period_interest_rate(interest_rate, *current_year_type, UNO);
    payment_of_period =
        floor_pyament(*deposit_amount * day_period_interest_rate);
    *deposit_amount += payment_of_period;
    *term -= UNO;
  } else {
    while (residue_period) {
      plus_day_period(start_date, current_year_type);
      day_period_interest_rate = calculate_period_interest_rate(
          interest_rate, *current_year_type, UNO);
      residue_period_interest += day_period_interest_rate;
      residue_period--;
      if (*term == FALSE) {
        *term = *extra_day_from_leap_year;
        *extra_day_from_leap_year = FALSE;
      }
    }

    payment_of_period =
        floor_pyament(*deposit_amount * residue_period_interest);
    *deposit_amount += payment_of_period;
  }
}

void per_week_calculate(datum *start_date, int *current_year_type,
                        int *extra_day_from_leap_year, double interest_rate,
                        int *remaining_days, double *term,
                        double *deposit_amount, int *payout_frequency) {
  double week_interest = FALSE;
  double result = FALSE; /* удалить и все что с ней связано, вычеркнуть из
                            жизни, исключить, техническая переменная */
  int week = PER_WEEK;

  if (*term >= week) {
    *term = *term - PER_WEEK;
    week_interest = plus_week_period(start_date, current_year_type,
                                     interest_rate, extra_day_from_leap_year);
    if (week_interest < s21_epsilon) {
      week_interest = calculate_period_interest_rate(
          interest_rate, *current_year_type, UNO * week);
    }
    result = floor_pyament(*deposit_amount * week_interest);
    *deposit_amount += result;
  } else {
    *payout_frequency = PER_DAY;
    *remaining_days = TRUE;
  }
}

void per_month_calculate(datum *start_date, double *term,
                         double *deposit_amount, int *current_year_type,
                         double interest_rate, int *extra_day_from_leap_year,
                         int *temp_date, int *period_start,
                         int *payout_frequency, int *remaining_days,
                         int quoter) {
  double month_interest = FALSE;
  int period_end = FALSE;
  double result = FALSE; /* удалить и все что с ней связано, вычеркнуть из
                            жизни, исключить, техническая переменная */
  int condition_res = conditions_check_month_and_quoter(
      start_date, current_year_type, temp_date, quoter);

  if (*term >= (condition_res == BEFORE_DECEMBER ? THIRTY_ONE_DAY_MONTH
                                                 : condition_res)) {
    !*period_start
        ? *period_start = calculate_days_from_christmas_to_date(start_date)
        : *period_start;

    condition_res == BEFORE_DECEMBER ? *term -= THIRTY_ONE_DAY_MONTH
                                     : (*term -= condition_res);
    month_interest = plus_month_or_quoter_period(
        start_date, current_year_type, interest_rate, extra_day_from_leap_year,
        temp_date, condition_res, FALSE);
    period_end = calculate_days_from_christmas_to_date(start_date);
    check_not_ended_leap_year(term, current_year_type, &period_end);

    month_interest < s21_epsilon
        ? month_interest = calculate_period_interest_rate(
              interest_rate, *current_year_type, period_end - *period_start)
        : month_interest;

    *period_start = period_end;
    result = floor_pyament(*deposit_amount * month_interest);
    *deposit_amount += result;
  } else {
    *payout_frequency = PER_DAY;
    *remaining_days = TRUE;
    if (*extra_day_from_leap_year && *current_year_type == LEAP_YEAR &&
        start_date->month > 2 &&
        (condition_res < BEFORE_DECEMBER ||
         (condition_res == BEFORE_DECEMBER &&
          start_date->date + (int)*term < THIRTY_ONE_DAY_MONTH))) {
      *term = *term - UNO;
    }
  }
}

void per_quoter_calculate(datum *start_date, double *term,
                          double *deposit_amount, int *current_year_type,
                          double interest_rate, int *extra_day_from_leap_year,
                          int *temp_date, int *period_start,
                          int *payout_frequency, int *remaining_days,
                          int qouter) {
  double quoter_interest = FALSE;
  int period_end = FALSE;
  double result = FALSE; /* удалить и все что с ней связано, вычеркнуть из
                            жизни, исключить, техническая переменная */
  int quoter_capacity = definition_quoter_capacity(start_date);
  int condition_res = conditions_check_month_and_quoter(
      start_date, current_year_type, temp_date, qouter);

  if (*term >= quoter_capacity) {
    !*period_start
        ? *period_start = calculate_days_from_christmas_to_date(start_date)
        : *period_start;
    *term -= quoter_capacity;
    quoter_interest = plus_month_or_quoter_period(
        start_date, current_year_type, interest_rate, extra_day_from_leap_year,
        temp_date, condition_res, qouter);
    period_end = calculate_days_from_christmas_to_date(start_date);
    quoter_interest < s21_epsilon
        ? quoter_interest = calculate_period_interest_rate(
              interest_rate, *current_year_type, period_end - *period_start)
        : quoter_interest;
    *period_start = period_end;
    result = floor_pyament(*deposit_amount * quoter_interest);
    *deposit_amount += result;
  } else {
    // if (*term >= 28)
    //   *payout_frequency = PER_MONTH;
    // else {
    *payout_frequency = PER_DAY;
    *remaining_days = TRUE;
    // }
  }
}

void plus_day_period(datum *start_date, int *current_year_type) {
  int condition = conditions_check_day(start_date, current_year_type);

  switch (condition) {
  case FEBRUARY_NL:
    start_date->date = 1;
    start_date->month++;
    break;
  case FEBRUARY_L:
    start_date->date = 1;
    start_date->month++;
    break;
  case THIRTY_DAY_MONTH:
    start_date->date = 1;
    start_date->month++;
    break;
  case BEFORE_DECEMBER:
    start_date->date += PER_DAY - THIRTY_ONE_DAY_MONTH;
    start_date->month = MONTHS_IN_YEAR - 11;
    start_date->year++;
    is_leap_year(start_date->year) ? *current_year_type = LEAP_YEAR
                                   : (*current_year_type = NOT_LEAP_YEAR);
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = 1;
    start_date->month += 1;
    break;
  default:
    start_date->date++;
    break;
  }
}

int conditions_check_day(datum *start_date, int *current_year_type) {
  int result = FALSE;
  if (start_date->date == FEBRUARY_NL &&
      month_capacity[start_date->month] == FEBRUARY_NL &&
      *current_year_type == NOT_LEAP_YEAR)
    result = FEBRUARY_NL;
  else if (start_date->date == FEBRUARY_L &&
           month_capacity[start_date->month] == FEBRUARY_NL &&
           *current_year_type == LEAP_YEAR)
    result = FEBRUARY_L;
  else if (start_date->date == THIRTY_DAY_MONTH &&
           (month_capacity[start_date->month] == THIRTY_DAY_MONTH))
    result = THIRTY_DAY_MONTH;
  else if (start_date->date == THIRTY_ONE_DAY_MONTH &&
           start_date->month == MONTHS_IN_YEAR)
    result = BEFORE_DECEMBER;
  else if (start_date->date == THIRTY_ONE_DAY_MONTH &&
           (month_capacity[start_date->month] == THIRTY_ONE_DAY_MONTH))
    result = THIRTY_ONE_DAY_MONTH;

  return result;
}

double plus_week_period(datum *start_date, int *current_year_type,
                        double interest_rate, int *extra_day_from_leap_year) {
  double result = FALSE;
  int condition = conditions_check_week(start_date, current_year_type,
                                        extra_day_from_leap_year);
  switch (condition) {
  case MORE_THAN_FABRUARY_NOT_LEAP:
    start_date->date = start_date->date + PER_WEEK - FEBRUARY_NL;
    start_date->month++;
    break;
  case MORE_THAN_FABRUARY_LEAP:
    start_date->date = start_date->date + PER_WEEK - FEBRUARY_L;
    start_date->month++;
    *extra_day_from_leap_year += UNO;
    break;
  case MORE_THEN_THRTY_DAY_MONTH:
    start_date->date = start_date->date + PER_WEEK - THIRTY_DAY_MONTH;
    start_date->month++;
    break;
  case MORE_THAN_DECEMBER:
    result = leap_and_not_leap_periods(start_date, interest_rate,
                                       current_year_type, PER_WEEK);
    start_date->date = start_date->date + PER_WEEK - THIRTY_ONE_DAY_MONTH;
    start_date->month = MONTHS_IN_YEAR - 11;
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = start_date->date + PER_WEEK - THIRTY_ONE_DAY_MONTH;
    start_date->month++;
    break;
  default:
    start_date->date = start_date->date + PER_WEEK;
    break;
  }

  return result;
}

double conditions_check_week(datum *start_date, int *current_year_type,
                             int *extra_day_from_leap_year) {
  double result = FALSE;

  if (start_date->date + PER_WEEK > FEBRUARY_NL &&
      month_capacity[start_date->month] == FEBRUARY_NL &&
      *current_year_type == NOT_LEAP_YEAR)
    result = MORE_THAN_FABRUARY_NOT_LEAP;
  else if (start_date->date + PER_WEEK > FEBRUARY_L &&
           month_capacity[start_date->month] == FEBRUARY_NL &&
           *current_year_type == LEAP_YEAR)
    result = MORE_THAN_FABRUARY_LEAP;
  else if (start_date->date + PER_WEEK > THIRTY_DAY_MONTH &&
           (month_capacity[start_date->month] == THIRTY_DAY_MONTH))
    result = MORE_THEN_THRTY_DAY_MONTH;
  else if (start_date->date + PER_WEEK > THIRTY_ONE_DAY_MONTH &&
           start_date->month == MONTHS_IN_YEAR)
    result = MORE_THAN_DECEMBER;
  else if (start_date->date + PER_WEEK > THIRTY_ONE_DAY_MONTH &&
           month_capacity[start_date->month] == THIRTY_ONE_DAY_MONTH)
    result = THIRTY_ONE_DAY_MONTH;

  return result;
}

double plus_month_or_quoter_period(datum *start_date, int *current_year_type,
                                   double interest_rate,
                                   int *extra_day_from_leap_year,
                                   int *temp_date, int condition_res,
                                   int quoter) {
  double result = FALSE;
  int is_quoter = FALSE;
  !*temp_date ? *temp_date = start_date->date : *temp_date;
  quoter ? is_quoter = quoter - UNO : is_quoter;

  switch (condition_res) {
  case FEBRUARY_NL:
    start_date->date = FEBRUARY_NL;
    start_date->month = start_date->month + UNO + is_quoter;
    break;
  case FEBRUARY_L:
    start_date->date = FEBRUARY_L;
    start_date->month = start_date->month + UNO + is_quoter;
    *extra_day_from_leap_year += UNO;
    break;
  case THIRTY_DAY_MONTH:
    start_date->date = THIRTY_DAY_MONTH;
    start_date->month = start_date->month + UNO + is_quoter;
    break;
  case BEFORE_DECEMBER:
    start_date->date = *temp_date;
    start_date->month = MONTHS_IN_YEAR - MONTHS_IN_YEAR + UNO + is_quoter;
    if (is_quoter)
      result = leap_and_not_leap_periods(
          start_date, interest_rate, current_year_type,
          is_leap_year(start_date->year + UNO) ? BEFORE_APRIL + UNO
                                               : BEFORE_APRIL);
    else
      result = leap_and_not_leap_periods(start_date, interest_rate,
                                         current_year_type, PER_MONTH);
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = *temp_date;
    start_date->month = start_date->month + UNO + is_quoter;
    break;
  default:
    start_date->date = *temp_date;
    start_date->month = start_date->month + UNO + is_quoter;
    break;
  }

  return result;
}

int conditions_check_month_and_quoter(datum *start_date, int *current_year_type,
                                      int *temp_date, int quoter) {
  int result = FALSE;
  int is_quoter = FALSE;

  quoter ? is_quoter = quoter : is_quoter;

  if (*temp_date > FEBRUARY_NL &&
      start_date->month + is_quoter == JANUARY_MONTH &&
      *current_year_type == NOT_LEAP_YEAR)
    result = FEBRUARY_NL;
  else if (*temp_date > FEBRUARY_L &&
           start_date->month + is_quoter == JANUARY_MONTH &&
           *current_year_type == LEAP_YEAR)
    result = FEBRUARY_L;
  else if (*temp_date > THIRTY_DAY_MONTH &&
           (month_capacity[start_date->month + is_quoter] == THIRTY_DAY_MONTH))
    result = THIRTY_ONE_DAY_MONTH;
  else if (start_date->month == MONTHS_IN_YEAR)
    result = BEFORE_DECEMBER;
  else if (month_capacity[start_date->month + is_quoter] ==
               THIRTY_ONE_DAY_MONTH &&
           start_date->month + is_quoter != 7)
    result = THIRTY_DAY_MONTH;
  else if (start_date->month + is_quoter == 7)
    result = THIRTY_ONE_DAY_MONTH;
  else {
    is_quoter == 3 ? is_quoter-- : is_quoter;
    result = month_capacity[start_date->month + UNO + is_quoter];
  }

  return result;
}

double leap_and_not_leap_periods(datum *start_date, double interest_rate,
                                 int *current_year_type,
                                 int count_days_in_period) {
  int days_in_previous_period = END_DATE - start_date->date;
  int days_in_current_period = count_days_in_period - days_in_previous_period;
  int previous_year_type = FALSE;
  double result = FALSE;

  previous_year_type = *current_year_type;
  start_date->year++;

  is_leap_year(start_date->year) ? *current_year_type = LEAP_YEAR
                                 : (*current_year_type = NOT_LEAP_YEAR);

  if (start_date->date < END_DATE && *current_year_type != previous_year_type) {
    result = calculate_period_interest_rate(interest_rate, previous_year_type,
                                            days_in_previous_period);
    result += calculate_period_interest_rate(interest_rate, *current_year_type,
                                             days_in_current_period);
  }
  return result;
}

int calculate_remain_days_from_biggets_periods(datum *start_date,
                                               int *remaining_days,
                                               double *term,
                                               int *current_year_type) {
  if (*remaining_days) {
    *remaining_days = FALSE;
    *remaining_days += fabs(*term);
    *term = FALSE;
  }

  return *remaining_days;
}

void check_not_ended_leap_year(double *term, int *current_year_type,
                               int *period_end) {
  if (*term <= FALSE && *current_year_type == LEAP_YEAR) {
    *period_end -= UNO;
  }
}

int definition_quoter_capacity(datum *start_date) {
  int result = LONG_QUOTER;

  if (start_date->month == 4 || start_date->month == 9)
    result = MEDIUN_QUOTER;
  else if (start_date->month == 1)
    is_leap_year(start_date->year) ? result = MEDIUN_QUOTER
                                   : (result = SHORT_QUOTER);
  else if (start_date->month == 2)
    is_leap_year(start_date->year) ? result = SHORT_QUOTER
                                   : (result = SHORT_QUOTER_NL);
  else if (start_date->month == 12 ||
           (start_date->month == 11 && start_date->date > 28))
    is_leap_year(start_date->year + UNO) ? result = MEDIUN_QUOTER
                                         : (result = SHORT_QUOTER);

  return result;
}

int calculate_days_from_christmas_to_date(datum *start_date) {
  int result = FALSE;
  int temp_year = start_date->year - UNO;

  result += start_date->date;
  result += days_before_month[start_date->month];
  result += (is_leap_year(start_date->year) && start_date->month > 2);
  result += temp_year * 365;
  result += temp_year / 4;
  result -= temp_year / 100;
  result += temp_year / 400;

  return result;
}

int is_leap_year(int number_of_year) {
  int result = FALSE;

  if (number_of_year % 4 == 0 &&
      (number_of_year % 100 != 0 || number_of_year % 400 == 0))
    result = TRUE;

  return result;
}

double calculate_period_interest_rate(double interest_rate,
                                      int days_in_current_year,
                                      int days_for_count_interest) {
  double result = FALSE;

  result = interest_rate / 100 / days_in_current_year * days_for_count_interest;
  result *= 1e+19;
  result = floor_pyament(result) / 1e+19;

  return result;
}
