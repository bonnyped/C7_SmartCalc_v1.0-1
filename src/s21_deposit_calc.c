#include "s21_smart_calc.h"

static int days_before_month[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR, JANUARY, FEBRUARY,  MARCH,   APRIL,    MAY,     JUNE,
    JULY,          AUGUST,  SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

static int month_capacity[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR, C_JANUARY,  C_FEBRUARY, C_MARCH,  C_APRIL,
    C_MAY,         C_JUNE,     C_JULY,     C_AUGUST, C_SEPTEMBER,
    C_OCTOBER,     C_NOVEMBER, C_DECEMBER};

deposit_result *
s21_deposit_calc(double deposit_amount, double term, double interest_rate,
                 double tax_rate, int payout_frequency,
                 int interest_capitalization, withdrawals *replenishment_list,
                 withdrawals *part_withdrawal_list, datum *start_date) {
  //   deposit *deposit_data = calloc(UNO, sizeof(deposit));
  deposit_result *outcome = NULL;
  int current_year_type = FALSE;
  double day_period_interest_rate = FALSE;
  int remaining_days = TRUE;
  int extra_day_from_leap_year = FALSE;

  while (term >= FALSE) {
    if (!current_year_type) {
      is_leap_year(start_date->year) ? current_year_type = LEAP_YEAR
                                     : (current_year_type = NOT_LEAP_YEAR);
      day_period_interest_rate =
          calculate_period_interest_rate(interest_rate, current_year_type, UNO);
    }
    switch (payout_frequency) {
    case PER_DAY:
      per_day_calculate(start_date, &current_year_type,
                        &extra_day_from_leap_year, interest_rate,
                        &remaining_days, &term, &day_period_interest_rate,
                        &deposit_amount);
      break;
    case PER_WEEK:
      per_week_calculate(start_date, &current_year_type,
                         &extra_day_from_leap_year, interest_rate,
                         &remaining_days, &term, &day_period_interest_rate,
                         &deposit_amount, &payout_frequency);
      break;
    case PER_MONTH:
      //   per_month_calculate(start_date, &term, &deposit_amount,
      //                       &current_year_type, interest_rate,
      //                       &extra_day_from_leap_year);
      break;
    case PER_QUOTER:
      //   per_quoter_calculate();
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
                       double *day_period_interest_rate,
                       double *deposit_amount) {
  double payment_of_period = FALSE;

  plus_day_period(start_date, current_year_type, extra_day_from_leap_year);
  *day_period_interest_rate =
      calculate_period_interest_rate(interest_rate, *current_year_type, UNO);
  calculate_remain_days_from_biggets_periods(remaining_days, term,
                                             day_period_interest_rate);
  payment_of_period =
      floor_pyament(*deposit_amount * (*day_period_interest_rate));
  *deposit_amount += payment_of_period;
  *term -= UNO;
}

void per_week_calculate(datum *start_date, int *current_year_type,
                        int *extra_day_from_leap_year, double interest_rate,
                        int *remaining_days, double *term,
                        double *day_period_interest_rate,
                        double *deposit_amount, int *payout_frequency) {
  double week_interest = FALSE;
  double payment_of_period = FALSE;
  if (*term > PER_WEEK) {
    week_interest = plus_week_period(start_date, current_year_type,
                                     interest_rate, extra_day_from_leap_year);
    if (week_interest < s21_epsilon) {
      *day_period_interest_rate = calculate_period_interest_rate(
          interest_rate, *current_year_type, UNO);
      week_interest = *day_period_interest_rate * PER_WEEK;
    }
    payment_of_period = floor_pyament(*deposit_amount * week_interest);
    *deposit_amount += payment_of_period;
    *term = *term - PER_WEEK;
  } else {
    *payout_frequency = PER_DAY;
    *remaining_days = FALSE;
    if (*extra_day_from_leap_year) {
      *term = *term + *extra_day_from_leap_year;
    }
  }
}

void per_month_calculate(datum *start_date, double *term,
                         double *deposit_amount, int *current_year_type,
                         double interest_rate, int *extra_day_from_leap_year) {
  int start_period_for_payment = FALSE;
  int end_period_for_payment = FALSE;

  start_period_for_payment = calculate_days_from_christmas_to_date(start_date);
  //   plus_month_period(start_date, current_year_type, interest_rate,
  //                     extra_day_from_leap_year);
}

void plus_day_period(datum *start_date, int *current_year_type,
                     int *extra_day_from_leap_year) {
  int check_result = conditions_check_day(start_date, current_year_type,
                                          extra_day_from_leap_year);

  switch (check_result) {
  case NOT_LEAP_FEBRUARY:
    start_date->date = 1;
    start_date->month++;
    break;
  case LEAP_FEBRUARY:
    start_date->date = 1;
    start_date->month++;
    *extra_day_from_leap_year += UNO;
    break;
  case THIRTY_DAY_MONTH:
    start_date->date = 1;
    start_date->month++;
    break;
  case END_OF_DECEMBER:
    start_date->date += PER_DAY - C_DECEMBER;
    start_date->month = MONTHS_IN_YEAR - 11;
    start_date->year++;
    is_leap_year(start_date->year) ? *current_year_type = LEAP_YEAR
                                   : (*current_year_type = NOT_LEAP_YEAR);
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = 1;
    start_date->month = 1;
    break;
  default:
    start_date->date++;
    break;
  }
}

int conditions_check_day(datum *start_date, int *current_year_type,
                         int *extra_day_from_leap_year) {
  int result = FALSE;
  if (start_date->date == C_FEBRUARY &&
      month_capacity[start_date->month] == C_FEBRUARY &&
      *current_year_type == NOT_LEAP_YEAR)
    result = NOT_LEAP_FEBRUARY;
  else if (start_date->date == C_FEBRUARY_LEAP &&
           month_capacity[start_date->month] == C_FEBRUARY &&
           *current_year_type == LEAP_YEAR)
    result = LEAP_FEBRUARY;
  else if (start_date->date == C_APRIL &&
           (month_capacity[start_date->month] == C_APRIL))
    result = THIRTY_DAY_MONTH;
  else if (start_date->date == C_DECEMBER &&
           start_date->month == MONTHS_IN_YEAR)
    result = END_OF_DECEMBER;
  else if (start_date->date == C_JANUARY &&
           (month_capacity[start_date->month] == C_JANUARY))
    result = THIRTY_ONE_DAY_MONTH;

  return result;
}

double plus_week_period(datum *start_date, int *current_year_type,
                        double interest_rate, int *extra_day_from_leap_year) {
  double result = FALSE;
  int check_result = FALSE;

  check_result = conditions_check_week(start_date, current_year_type,
                                       extra_day_from_leap_year);
  switch (check_result) {
  case MORE_THAN_FABRUARY_NOT_LEAP:
    start_date->date = start_date->date + PER_WEEK - C_FEBRUARY;
    start_date->month++;
    break;
  case MORE_THAN_FABRUARY_LEAP:
    start_date->date = start_date->date + PER_WEEK - C_FEBRUARY +
                       (*current_year_type - NOT_LEAP_YEAR);
    start_date->month++;
    *extra_day_from_leap_year += UNO;
    break;
  case MORE_THEN_THRTY_DAY_MONTH:
    start_date->date = start_date->date + PER_WEEK - C_APRIL;
    start_date->month++;
    break;
  case MORE_THAN_DECEMBER:
    start_date->date = start_date->date + PER_WEEK - C_DECEMBER;
    start_date->month = MONTHS_IN_YEAR - 11;
    start_date->year++;
    result =
        leap_and_not_leap_periods(start_date, interest_rate, current_year_type);
    break;
  case THIRTY_ONE_DAYS_MONTH:
    start_date->date = start_date->date + PER_WEEK - C_JANUARY;
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

  if (start_date->date + PER_WEEK > C_FEBRUARY &&
      month_capacity[start_date->month] == C_FEBRUARY &&
      *current_year_type == NOT_LEAP_YEAR)
    result = MORE_THAN_FABRUARY_NOT_LEAP;
  else if (start_date->date + PER_WEEK > C_FEBRUARY_LEAP &&
           month_capacity[start_date->month] == C_FEBRUARY &&
           *current_year_type == LEAP_YEAR)
    result = MORE_THAN_FABRUARY_LEAP;
  else if (start_date->date + PER_WEEK > C_APRIL &&
           (month_capacity[start_date->month] == C_APRIL))
    result = MORE_THEN_THRTY_DAY_MONTH;
  else if (start_date->date + PER_WEEK > C_DECEMBER &&
           start_date->month == MONTHS_IN_YEAR)
    result = MORE_THAN_DECEMBER;
  else if (start_date->date + PER_WEEK > C_JANUARY &&
           month_capacity[start_date->month] == C_JANUARY)
    result = THIRTY_ONE_DAYS_MONTH;

  return result;
}

double leap_and_not_leap_periods(datum *start_date, double interest_rate,
                                 int *current_year_type) {
  int days_in_previous_period = PER_WEEK - start_date->date;
  int days_in_current_period = PER_WEEK - days_in_previous_period;
  int previous_year_type = FALSE;
  double result = FALSE;

  previous_year_type = *current_year_type;

  is_leap_year(start_date->year) ? *current_year_type = LEAP_YEAR
                                 : (*current_year_type = NOT_LEAP_YEAR);

  if (start_date->date < PER_WEEK && *current_year_type != previous_year_type) {
    result = calculate_period_interest_rate(interest_rate, previous_year_type,
                                            days_in_previous_period);
    result += calculate_period_interest_rate(interest_rate, *current_year_type,
                                             days_in_current_period);
  }
  return result;
}

void calculate_remain_days_from_biggets_periods(
    int *remaining_days, double *term, double *day_period_interest_rate) {
  if (!*remaining_days) {
    while (*term > FALSE) {
      *term -= UNO;
      *remaining_days += UNO;
    }
    *day_period_interest_rate *= *remaining_days;
  }
}

// double calculate_transitional_month_period_interest_rate(
//     datum *start_date, double interest_rate, double deposit_amount) {
//   double result = FALSE;
//   int start_of_period = FALSE;
//   int end_of_period = FALSE;
//   double day_period_interest_rate = FALSE;

//   day_period_interest_rate += calculte_december_part_interest_rate(
//       start_date, interest_rate, &start_of_period, &end_of_period);
//   day_period_interest_rate += calculte_january_part_interest_rate(
//       start_date, interest_rate, &start_of_period, &end_of_period);
//   result = period_interest_rate;

//   return result;
// }

// double calculte_december_part_interest_rate(datum *start_date,
//                                             double interest_rate,
//                                             int *start_of_period,
//                                             int *end_of_period) {
//   double result = FALSE;
//   int number_of_days_in_year = FALSE;
//   int temp_date = start_date->date;

//   is_leap_year(start_date->year) ? number_of_days_in_year = LEAP_YEAR
//                                  : (number_of_days_in_year = NOT_LEAP_YEAR);

//   *start_of_period = calculate_days_from_christmas_to_date(start_date);
//   start_date->date = 31;
//   *end_of_period = calculate_days_from_christmas_to_date(start_date);
//   result += calculate_period_interest_rate(
//       interest_rate, number_of_days_in_year, *end_of_period -
//       *start_of_period);
//   start_date->date = temp_date;
//   start_date->month = JANUARY_MONTH;
//   start_date->year++;

//   return result;
// }

// double calculte_january_part_interest_rate(datum *start_date,
//                                            double interest_rate,
//                                            int *start_of_period,
//                                            int *end_of_period) {
//   double result = FALSE;
//   int number_of_days_in_year = FALSE;

//   is_leap_year(start_date->year) ? number_of_days_in_year = LEAP_YEAR
//                                  : (number_of_days_in_year = NOT_LEAP_YEAR);
//   *start_of_period = *end_of_period;
//   *end_of_period = calculate_days_from_christmas_to_date(start_date);
//   result += calculate_period_interest_rate(
//       interest_rate, number_of_days_in_year, *end_of_period -
//       *start_of_period);

//   return result;
// }
// double calculate_transitional_month(datum *start_date, double
// interest_rate,
//                                     double deposit_amount) {
//   double result = deposit_amount;
//   int start_of_period = FALSE;
//   int end_of_period = FALSE;
//   double day_period_interest_rate = FALSE;
//   int number_of_days_in_year = NOT_LEAP_YEAR;
//   int days_in_next_month = start_date->month + 2;

//   if (start_date->month == MONTHS_IN_YEAR)
//     is_leap_year(start_date->year + UNO) ? number_of_days_in_year =
//     LEAP_YEAR
//                                             : number_of_days_in_year;
//   else {
//     is_leap_year(start_date->year) ? number_of_days_in_year =
//     LEAP_YEAR
//                                       : number_of_days_in_year;
//   }
//   if (start_date->month < MONTHS_IN_YEAR)
//     days_in_next_month = days_before_month[days_in_next_month] -
//                          days_before_month[days_in_next_month - 1];

//   if (number_of_days_in_year == LEAP_YEAR && days_in_next_month == 28)
//     days_in_next_month++;
//   start_of_period = calculate_days_from_christmas_to_date(start_date);
//   if (start_date->month == MONTHS_IN_YEAR) {
//     start_date->month = JANUARY_MONTH;
//     start_date->year++;
//   } else if (days_in_next_month < start_date->date) {
//     if (start_date->date <= 31 && start_date->date >= 29) {
//       if (number_of_days_in_year == LEAP_YEAR) {
//         start_date->date = days_before_month;
//         start_date->month++;
//       } else {
//         start_date->date = days_in_next_month;
//         start_date->month++;
//       }
//     }
//   } else {
//     start_date->month++;
//   }

//   end_of_period = calculate_days_from_christmas_to_date(start_date);
//   day_period_interest_rate += calculate_period_interest_rate(
//       interest_rate, number_of_days_in_year, end_of_period -
//       start_of_period);
//   result += floor_pyament(result * period_interest_rate);
// }

int calculate_days_from_christmas_to_date(datum *start_date) {
  int result = FALSE;
  int temp_year = start_date->year - UNO;

  result = start_date->date + days_before_month[start_date->month] +
           ((is_leap_year(start_date->year) == LEAP_YEAR)) + temp_year * 365 +
           temp_year / 4 - temp_year / 100 + temp_year / 400;

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

// double calculate_accrued_interest(datum *start_date, double
// deposit_amount,
//                                   double interest_rate) {
//   double result = FALSE;
//   int days_for_count_interest = FALSE;

//   int days_in_current_year = FALSE;
//   double day_period_interest_rate = FALSE;

//   if (start_date->month == MONTHS_IN_YEAR) {
//     days_for_count_interest =
//         calculate_days_in_period(start_date, &days_in_current_year);
//     result = floor_pyament(
//         deposit_amount *
//         floor_pyament(deposit_amount * calculate_period_interest_rate(
//                                            interest_rate,
//                                            days_in_current_year,
//                                            days_for_count_interest)));
//     days_for_count_interest =
//         calculate_days_in_period(start_date, &days_in_current_year);
//     result =
//         floor_pyament(deposit_amount * calculate_period_interest_rate(
//                                            interest_rate,
//                                            days_in_current_year,
//                                            days_for_count_interest));
//   }
//   days_for_count_interest =
//       calculate_days_in_period(start_date, &days_in_current_year);
//   result = floor_pyament(
//       deposit_amount *
//       floor_pyament(deposit_amount * calculate_period_interest_rate(
//                                          interest_rate, days_in_current_year,
//                                          days_for_count_interest)));

//   return result;
// }

// double calculate_end_start_year() {
//   int result = FALSE;
//   start_of_period = calculate_days_from_start_era_to_current_day(
//       start_date->date, start_date->month, start_date->year);
//   end_of_period = calculate_days_from_start_era_to_current_day(
//       END_DATE, start_date->month, start_date->year);

//   start_date->month = UNO;
//   start_date->year += UNO;
//   start_of_period = calculate_days_from_start_era_to_current_day(
//                         START_DATE, start_date->month,
//                         start_date->year) +
//                     1;
//   end_of_period = calculate_days_from_start_era_to_current_day(
//       start_date->date, start_date->month, start_date->year);
//   return result;
// }

// int calculate_days_in_period(datum *start_date, int *days_in_current_year)
// {
//   int start_of_period = FALSE;
//   int end_of_period = FALSE;

//   is_leap_year(start_date->year) ? *days_in_current_year = LEAP_YEAR
//                                     : (*days_in_current_year =
//                                     NOT_LEAP_YEAR);
//   start_of_period = calculate_days_from_start_era_to_current_day(
//       start_date->date, start_date->month, start_date->year);
//   start_date->month += UNO;
//   end_of_period = calculate_days_from_start_era_to_current_day(
//       start_date->date, start_date->month, start_date->year);

//   return end_of_period - start_of_period;
// }

// int calculate_days_from_start_era_to_current_day(int date, int month,
//                                                  int year) {
//   int result = FALSE;
//   int temp_year = year - UNO;

//   result = date + days_before_month[month] +
//            ((is_leap_year(year) == LEAP_YEAR) && month > 2) +
//            temp_year * 365
//            + temp_year / 4 - temp_year / 100 + temp_year / 400;

//   return result;
// }

// withdrawals *check_withdrawals(int type_of_whithdrawl, int frequency, int
// date, int month, int year, double amount){
//     withdrawals *deposit_withdrawal = NULL;

//     if(deposit_withdrawal && type_of_whithdrawl > FALSE){
//         deposit_withdrawal = calloc(UNO, sizeof(withdrawals));
//         deposit_withdrawal->type_of_whithdrawl = type_of_whithdrawl;
//         deposit_withdrawal->amount = amount;
//         deposit_withdrawal->date = date;
//         deposit_withdrawal->month = month;
//         deposit_withdrawal->year = year;
//         deposit_withdrawal->frequency = frequency;
//     }

//     return deposit_withdrawal;
// }

//    if(deposit_data){
//     deposit_data->deposit_amount = deposit_amount;
//     deposit_data->term = term;
//     deposit_data->interest_rate = interest_rate;
//     deposit_data->tax_rate = tax_rate;
//     deposit_data->payout_frequency = payout_frequency;
//     deposit_data->interest_capitalization = interest_capitalization;
//     replenishment_list ? deposit_data->replenishment_list =
//     replenishment_list : (deposit_data->replenishment_list = NULL);
//     part_withdrawal_list ? deposit_data->part_withdrawal_list =
//     part_withdrawal_list : (deposit_data->part_withdrawal_list = NULL);
//    }