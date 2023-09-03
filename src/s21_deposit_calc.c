#include "s21_smart_calc.h"

static int days_before_month[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR,  BEFORE_JANUARY,   BEFORE_FEBRUARY, BEFORE_MARCH,
    BEFORE_APRIL,   BEFORE_MAY,       BEFORE_JUNE,     BEFORE_JULY,
    BEFORE_AUGUST,  BEFORE_SEPTEMBER, BEFORE_OCTOBER,  BEFORE_NOVEMBER,
    BEFORE_DECEMBER};

static int month_capacity[UNO + MONTHS_IN_YEAR] = {
    START_OF_YEAR, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// void function_print(schedule **data_schedule, int counter, deposit *data) {
//   int index = 0;
//   printf("\n\n");
//   while (index < counter) {
//     // printf("\n%d - Index\n", index);
//     switch (data_schedule[index]->event) {
//     case EVENT_YEAR:
//       // printf("\n%d.%d.%d ===       -----END of year",
//       // data_schedule[index]->date,
//       //        data_schedule[index]->month, data_schedule[index]->year);
//       break;
//     case EVENT_PAYOUT:
//       printf("\n%d.%d.%d     ------------------------ PAY",
//              data_schedule[index]->date, data_schedule[index]->month,
//              data_schedule[index]->year);
//       break;
//     case EVENT_ADD:
//       printf("\n%d.%d.%d                 ADD", data_schedule[index]->date,
//              data_schedule[index]->month, data_schedule[index]->year);
//       break;
//     case EVENT_DROP:
//       printf("\n%d.%d.%d        -----------------          DROP",
//              data_schedule[index]->date, data_schedule[index]->month,
//              data_schedule[index]->year);
//       break;
//     default:
//       break;
//     }
//     // printf("\n%d     - day", data_schedule[index]->from_christmas_date);
//     printf("\n");
//     index++;
//   }
// }

void s21_deposit_calc(deposit *data) {
  schedule **data_schedule = calloc(MAX_SIZE_DATA_SCHEDULE, sizeof(schedule));
  int counter = FALSE;

  fill_end_of_years(data, data_schedule, &counter);
  fill_payment_events(data, data_schedule, &counter);

  if (data->add_list)
    fill_adds_or_drops(data->start_date, data->term, data_schedule, &counter, data->add_list, EVENT_ADD);

  if (data->drop_list)
    fill_adds_or_drops(data->start_date, data->term, data_schedule, &counter, data->drop_list, EVENT_DROP);

  insert_sort(data_schedule, counter);

  calculate_deposit(data_schedule, counter, data);

  data->amount_add_drops <= s21_epsilon ? data->amount_add_drops = FALSE
                                        : data->amount_add_drops;
  !data->interest_capitalization
      ? data->end_term_amount = data->amount
      : (data->accumulated_balance_interest =
             data->end_term_amount - data->amount - data->amount_add_drops);
  tax_calculate(data);

  data_schedule ? free(data_schedule) : data_schedule;
}

void fill_end_of_years(deposit *data, schedule **datas_buffer, int *counter) {
  int period_start = calculate_days_from_christmas_to_date(data->start_date);
  int period_end = FALSE;
  int days_between_years = FALSE;
  int term = (int)data->term;
  datum *end_year_date = calloc(UNO, sizeof(datum));

  end_year_date->date = THIRTY_ONE_DAY_MONTH;
  end_year_date->month = MONTHS_IN_YEAR;
  end_year_date->year = data->start_date->year;

  while (term > days_between_years) {
    period_end = calculate_days_from_christmas_to_date(end_year_date);
    days_between_years = period_end - period_start;
    if (term > days_between_years) {
      add_data_to_schedule(datas_buffer, counter, period_end, EVENT_YEAR, FALSE,
                           end_year_date);
      end_year_date->year++;
    }
    term -= days_between_years;
  }
  end_year_date ? free(end_year_date) : end_year_date;
}

void fill_payment_events(deposit *data, schedule **datas_buffer, int *counter) {
  int start_period = calculate_days_from_christmas_to_date(data->start_date);
  int period_end = FALSE;
  int term = (int)data->term;
  datum *copy_start_date = calloc(UNO, sizeof(datum));
  int temp_date = data->start_date->date;
  int days_between_periods = FALSE;

  copy_start_date->date = data->start_date->date;
  copy_start_date->month = data->start_date->month;
  copy_start_date->year = data->start_date->year;

  flip_calendar(copy_start_date, data->payout_frequency, temp_date);
  period_end = calculate_days_from_christmas_to_date(copy_start_date);
  days_between_periods = period_end - start_period;

  if (term > days_between_periods) {
    while (term >= days_between_periods) {
      start_period = period_end;
      term -= days_between_periods;
      add_data_to_schedule(datas_buffer, counter, period_end, EVENT_PAYOUT,
                           FALSE, copy_start_date);
      period_end = start_period + days_between_periods;
      flip_calendar(copy_start_date, data->payout_frequency, temp_date);
      period_end = calculate_days_from_christmas_to_date(copy_start_date);
      days_between_periods = period_end - start_period;
    }
  }
  if (term > 0) {
    period_end = start_period + term;
    add_data_to_schedule(datas_buffer, counter, period_end, EVENT_PAYOUT, FALSE,
                         copy_start_date);
  }
  copy_start_date ? free(copy_start_date) : copy_start_date;
}

void add_data_to_schedule(schedule **datas_buffer, int *counter, int period_end,
                          int event, double amount, datum *current_date) {
  datas_buffer[*counter] = calloc(UNO, sizeof(schedule));
  datas_buffer[*counter]->from_christmas_date = period_end;
  datas_buffer[*counter]->event = event;
  datas_buffer[*counter]->amount = amount;
  if(current_date){
  datas_buffer[*counter]->date = current_date->date;
  datas_buffer[*counter]->month = current_date->month;
  datas_buffer[*counter]->year = current_date->year;
  }
  *counter += UNO;
}

void flip_calendar(datum *start_date, int current_frequency, int temp_date) {
  switch (current_frequency) {
  case PER_DAY:
    plus_day_period(start_date);
    break;
  case PER_WEEK:
    plus_week_period(start_date);
    break;
  case PER_MONTH:
    plus_month_period(start_date, temp_date);
    break;
  case PER_TWO_MONTHS:
    for (int i = 0; i < 2; i++) {
      plus_month_period(start_date, temp_date);
    }
    break;
  case PER_QUOTER:
    for (int i = 0; i < PER_QUOTER; i++) {
      plus_month_period(start_date, temp_date);
    }
    break;
  case PER_TWO_QUATERS:
    for (int i = 0; i < PER_TWO_QUATERS; i++) {
      plus_month_period(start_date, temp_date);
    }
    break;
  case PER_YEAR:
    for (int i = 0; i < PER_TWO_QUATERS * 2; i++) {
      plus_month_period(start_date, temp_date);
    }
    break;
  default:
    break;
  }
}

void plus_day_period(datum *start_date) {
  int condition = conditions_check_day(start_date);

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
    start_date->year += UNO;
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

int conditions_check_day(datum *start_date) {
  int result = FALSE;

  if (start_date->date == FEBRUARY_NL &&
      month_capacity[start_date->month] == FEBRUARY_NL &&
      !is_leap_year(start_date->year))
    result = FEBRUARY_NL;
  else if (start_date->date == FEBRUARY_L &&
           month_capacity[start_date->month] == FEBRUARY_NL &&
           is_leap_year(start_date->year))
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

void plus_week_period(datum *start_date) {
  int condition = conditions_check_week(start_date);

  switch (condition) {
  case MORE_THAN_FABRUARY_NOT_LEAP:
    start_date->date = start_date->date + PER_WEEK - FEBRUARY_NL;
    start_date->month++;
    break;
  case MORE_THAN_FABRUARY_LEAP:
    start_date->date = start_date->date + PER_WEEK - FEBRUARY_L;
    start_date->month++;
    break;
  case MORE_THEN_THRTY_DAY_MONTH:
    start_date->date = start_date->date + PER_WEEK - THIRTY_DAY_MONTH;
    start_date->month++;
    break;
  case MORE_THAN_DECEMBER:
    start_date->date = start_date->date + PER_WEEK - THIRTY_ONE_DAY_MONTH;
    start_date->month = MONTHS_IN_YEAR - 11;
    start_date->year++;
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = start_date->date + PER_WEEK - THIRTY_ONE_DAY_MONTH;
    start_date->month++;
    break;
  default:
    start_date->date = start_date->date + PER_WEEK;
    break;
  }
}

int conditions_check_week(datum *start_date) {
  int result = FALSE;

  if (start_date->date + PER_WEEK > FEBRUARY_NL &&
      month_capacity[start_date->month] == FEBRUARY_NL &&
      !is_leap_year(start_date->year))
    result = MORE_THAN_FABRUARY_NOT_LEAP;
  else if (start_date->date + PER_WEEK > FEBRUARY_L &&
           month_capacity[start_date->month] == FEBRUARY_NL &&
           is_leap_year(start_date->year))
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

double plus_month_period(datum *start_date, int temp_date) {
  double result = FALSE;
  int condition_res = conditions_check_month(start_date, temp_date);

  switch (condition_res) {
  case FEBRUARY_NL:
    start_date->date = condition_res;
    start_date->month = start_date->month + UNO;
    break;
  case FEBRUARY_L:
    start_date->date = condition_res;
    start_date->month = start_date->month + UNO;
    break;
  case THIRTY_DAY_MONTH:
    start_date->date = condition_res;
    start_date->month = start_date->month + UNO;
    break;
  case BEFORE_DECEMBER:
    start_date->date = temp_date;
    start_date->month = JANUARY_MONTH;
    start_date->year++;
    break;
  case THIRTY_ONE_DAY_MONTH:
    start_date->date = temp_date;
    start_date->month = start_date->month + UNO;
    break;
  default:
    start_date->date = temp_date;
    start_date->month = start_date->month + UNO;
    break;
  }

  return result;
}

int conditions_check_month(datum *start_date, int temp_date) {
  int result = FALSE;
  int leap_year = is_leap_year(start_date->year);

  if (temp_date > FEBRUARY_NL && start_date->month == JANUARY_MONTH &&
      leap_year == FALSE)
    result = FEBRUARY_NL;
  else if (temp_date > FEBRUARY_L && start_date->month == JANUARY_MONTH &&
           leap_year == TRUE)
    result = FEBRUARY_L;
  else if (temp_date > THIRTY_DAY_MONTH &&
           (month_capacity[start_date->month] == THIRTY_DAY_MONTH))
    result = THIRTY_ONE_DAY_MONTH;
  else if (start_date->month == MONTHS_IN_YEAR)
    result = BEFORE_DECEMBER;
  else if (temp_date > THIRTY_DAY_MONTH &&
           month_capacity[start_date->month] == THIRTY_ONE_DAY_MONTH &&
           start_date->month != 7)
    result = THIRTY_DAY_MONTH;
  else if (start_date->month == 7)
    result = THIRTY_ONE_DAY_MONTH;
  else {
    result = temp_date;
  }

  return result;
}

void fill_adds_or_drops(datum *start, double term, schedule **datas_buffer,
                        int *counter, drop_add_lists *add_or_drop_list, int event) {
  int start_date = calculate_days_from_christmas_to_date(start);
  int event_date =
      calculate_days_from_christmas_to_date(add_or_drop_list->date_add_drop);
  int period_end = start_date + (int)term;
  int temp_date = add_or_drop_list->date_add_drop->date;

  do {
    if (start_date >= event_date) {
      flip_calendar(add_or_drop_list->date_add_drop,
                    add_or_drop_list->frequency, temp_date);
      event_date = calculate_days_from_christmas_to_date(
          add_or_drop_list->date_add_drop);
    } else {
      add_data_to_schedule(datas_buffer, counter, event_date, event,
                           add_or_drop_list->amount,
                           add_or_drop_list->date_add_drop);
      flip_calendar(add_or_drop_list->date_add_drop,
                    add_or_drop_list->frequency, temp_date);
      event_date = calculate_days_from_christmas_to_date(
          add_or_drop_list->date_add_drop);
      add_or_drop_list->frequency == PER_ONCE ? event_date = period_end + UNO
                                              : event_date;
    }
  } while (period_end >= event_date 
           /* period_end == calculate_days_from_christmas_to_date(
                             add_or_drop_list->date_add_drop) */);
}

int calculate_days_from_christmas_to_date(datum *start_date) {
  int result = FALSE;
  int temp_year = start_date->year - UNO;

  result += start_date->date;
  result += days_before_month[start_date->month];
  result +=
      (is_leap_year(start_date->year) && start_date->month > 2 ? LEAP_YEAR
                                                               : NOT_LEAP_YEAR);
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

void insert_sort(schedule **buffer, int count) {
  schedule *tmp = {0};
  for (int index = 1; index < count; index++)
    for (int jindex = index;
         jindex > 0 && buffer[jindex - 1]->from_christmas_date >
                           buffer[jindex]->from_christmas_date;
         jindex--) {
      tmp = buffer[jindex - 1];
      buffer[jindex - 1] = buffer[jindex];
      buffer[jindex] = tmp;
    }
}

void calculate_deposit(schedule **data_schedule, int counter, deposit *data) {
  int last_event = calculate_days_from_christmas_to_date(data->start_date);
  int current_year_days =
      is_leap_year(data->start_date->year) ? LEAP_YEAR : NOT_LEAP_YEAR;
  double day_interest = data->interest_rate / current_year_days / 100;
  double accumulated_period_interest = FALSE;
  data->end_term_amount = data->amount;

  for (int index = 0; index < counter; index++) {
    switch (data_schedule[index]->event) {
    case EVENT_YEAR:
      year_calculates(data_schedule, index, &last_event, &day_interest,
                      &accumulated_period_interest, data);
      break;
    case EVENT_ADD:
      add_drop_calculates(data_schedule, index, &last_event, day_interest, data,
                          &accumulated_period_interest,
                          data_schedule[index]->event);
      break;
    case EVENT_DROP:
      add_drop_calculates(data_schedule, index, &last_event, day_interest, data,
                          &accumulated_period_interest,
                          data_schedule[index]->event);
      break;
    case EVENT_PAYOUT:
      payout_calculates(data_schedule, index, &last_event, day_interest, data,
                        &accumulated_period_interest);
      break;
    }
  }
}

void year_calculates(schedule **data_schedule, int index, int *last_event,
                     double *day_interest, double *accumulated_period_interest,
                     deposit *data) {
  int period_capacity = FALSE;
  int days = FALSE;

  period_capacity = data_schedule[index]->from_christmas_date - *last_event;
  *accumulated_period_interest =
      data->end_term_amount * (*day_interest) * period_capacity;
  *last_event = data_schedule[index]->from_christmas_date;
  days =
      is_leap_year(data_schedule[index]->year + 1) ? LEAP_YEAR : NOT_LEAP_YEAR;
  *day_interest = data->interest_rate / days / 100;
  data_schedule[index] ? free(data_schedule[index]) : data_schedule[index];
}

void add_drop_calculates(schedule **data_schedule, int index, int *last_event,
                         double day_interest, deposit *data,
                         double *accumulated_period_interest, int event_type) {
  int period_capacity = data_schedule[index]->from_christmas_date - *last_event;
  double event_amount = event_type == EVENT_DROP ? data->drop_list->amount *= -1
                                                 : data->add_list->amount;

  *accumulated_period_interest +=
      data->end_term_amount * day_interest * period_capacity;
  *last_event = data_schedule[index]->from_christmas_date;
  data->end_term_amount += event_amount;
  data->amount_add_drops += event_amount;

  data_schedule[index] ? free(data_schedule[index]) : data_schedule[index];
}

void payout_calculates(schedule **data_schedule, int index, int *last_event,
                       double day_interest, deposit *data,
                       double *accumulated_period_interest) {
  int period_capacity = data_schedule[index]->from_christmas_date - *last_event;
  *last_event = data_schedule[index]->from_christmas_date;

  *accumulated_period_interest +=
      data->end_term_amount * day_interest * period_capacity;
  data->interest_capitalization
      ? data->end_term_amount += floor_pyament(*accumulated_period_interest)
      : (data->accumulated_balance_interest +=
         floor_pyament(*accumulated_period_interest));
  *accumulated_period_interest = FALSE;
  data_schedule[index] ? free(data_schedule[index]) : data_schedule[index];
}

void tax_calculate(deposit *data) {
  double tax_result = FALSE;

  tax_result = NONTAXABLE_BASE / 100 * data->tax_rate;
  tax_result -= data->accumulated_balance_interest;

  tax_result <= s21_epsilon *NONTAXABLE_BASE
      ? data->tax_amount = tax_result * (-1)
      : (data->tax_amount = FALSE);
}

int check_frequence_add_drop(int index){
  int result = -1;

  switch (index)
  {
  case 0:
    result = PER_ONCE;
    break;
  case 1:
    result = PER_MONTH;
    break;
  case 2:
    result = PER_TWO_MONTHS;
    break;
  case 3:
    result = PER_QUOTER;
    break;
  case 4:
    result = PER_TWO_QUATERS;
    break;
  case 5:
    result = PER_YEAR;
    break;

  default:
    break;
  }

  return result;
}

int check_frequence_payout(int index){
  int result = FALSE;

  switch (index)
  {
  case 0:
    result = PER_DAY;
    break;
  case 1:
    result = PER_WEEK;
    break;
  case 2:
    result = PER_MONTH;
    break;
  case 3:
    result = PER_QUOTER;
    break;
  case 4:
    result = PER_TWO_QUATERS;
    break;
  case 5:
    result = PER_YEAR;
    break;
  case 6:
    RESULT = AT_THE_END_OF_TERM;
    break;

  default:
    break;
  }

  return result;
}
