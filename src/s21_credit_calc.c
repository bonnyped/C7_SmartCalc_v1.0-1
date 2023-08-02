#include "s21_smart_calc.h"

credit_struct *s21_credit_calc(double loan_body, double term,
                               double interest_rate, int type_of_pay,
                               int not_months) {
  credit_struct *current_calculation = calloc(UNO, sizeof(credit_struct));

  not_months ? term = term / MONTHS_IN_YEAR : term;

  switch (type_of_pay) {
  case ANNUITETTE:
    calc_whole_payments_annuitette(current_calculation, loan_body, term,
                                   interest_rate);
    break;
  case DIFFERENTIAL:
    calc_whole_payments_differential(current_calculation, loan_body, term,
                                     interest_rate);
    break;
  default:
    break;
  };

  return current_calculation;
}

void calc_whole_payments_annuitette(credit_struct *current_calculation,
                                    double loan_body, double term,
                                    double interest_rate) {
  calc_annuity_rate(current_calculation, loan_body, term, interest_rate);
  current_calculation->monthly_payment_max =
      floor_pyament(current_calculation->monthly_payment_max);
  current_calculation->total_payment =
      current_calculation->monthly_payment_max * term;
  current_calculation->loan_overpayment =
      current_calculation->total_payment - loan_body;
}

void calc_annuity_rate(credit_struct *current_calculation, double loan_body,
                       double term, double interest_rate) {
  double annuity_rate = FALSE;
  double monthly_interset_rate = interest_rate / MONTHS_IN_YEAR / 100;

  annuity_rate = monthly_interset_rate *
                 pow((UNO + monthly_interset_rate), term) /
                 (pow(UNO + monthly_interset_rate, term) - UNO);
  current_calculation->monthly_payment_max = loan_body * annuity_rate;
}

double floor_pyament(double value_to_floor) {
  char ceil_to_two_sign_after_point[MAX_CAPACITY / 2] = {0};

  sprintf(ceil_to_two_sign_after_point, "%.2lf", value_to_floor);
  sscanf(ceil_to_two_sign_after_point, "%lf", &value_to_floor);

  return value_to_floor;
}

void calc_whole_payments_differential(credit_struct *current_calculation,
                                      double loan_body, double term,
                                      double interest_rate) {
  double monthly_payment_to_loan_body = loan_body / term;
  current_calculation->total_payment = loan_body;
  time_t date = time(NULL);
  struct tm *today = localtime(&date);
  double month_overpayment = FALSE;
  int day = today->tm_mday;
  int month = today->tm_mon + UNO;
  int year = today->tm_year + 1900;

  monthly_payment_to_loan_body = floor_pyament(monthly_payment_to_loan_body);

  for (int i = FALSE; i < (int)term; i++) {
    month_overpayment = loan_body * (interest_rate / 100.00) / MONTHS_IN_YEAR;
    month_overpayment = floor_pyament(month_overpayment);
    current_calculation->loan_overpayment += month_overpayment;
    loan_body -= monthly_payment_to_loan_body;
    if (!i)
      current_calculation->monthly_payment_max =
          monthly_payment_to_loan_body + month_overpayment;
    if (i == (int)term - UNO)
      current_calculation->monthly_payment_min =
          monthly_payment_to_loan_body + month_overpayment;
  }
  current_calculation->total_payment += current_calculation->loan_overpayment;
}

// int calculate_days_in_period(int day, int *month, int *year) {
//   int start_of_period = FALSE;
//   int end_of_period = FALSE;

//   start_of_period =
//       calculate_days_from_start_era_to_current_day(day, month, year);
//   *month += UNO;
//   if (*month > 12) {
//     *month = UNO;
//     *year += UNO;
//   }
//   end_of_period =
//       calculate_days_from_start_era_to_current_day(day, month, year);

//   return end_of_period - start_of_period;
// }

// int calculate_days_from_start_era_to_current_day(int day, int *month,
//                                                  int *year) {
//   int result = FALSE;
//   int temp_year = *year - UNO;

//   result = day + days_before_month[*month] +
//            ((is_leap_year(*year) == LEAP_YEAR) && *month > 2) +
//            temp_year * 365 + temp_year / 4 - temp_year / 100 + temp_year /
//            400;

//   return result;
// }

// int is_leap_year(int number_of_year) {
//   int result = FALSE;

//   if (number_of_year % 4 == 0 &&
//       (number_of_year % 100 != 0 || number_of_year % 400 == 0))
//     result = TRUE;

//   return result;
// }

// if (number_of_days_in_year == LEAP_YEAR) {
//   if (!is_leap_year(year)) {
//     number_of_days_in_year = NOT_LEAP_YEAR;
//   }
// } else if (number_of_days_in_year == NOT_LEAP_YEAR && is_leap_year(year) &&
//            month > 2) {
//   number_of_days_in_year = LEAP_YEAR;
// }
// days_in_payment_period = calculate_days_in_period(day, &month, &year);

// static int days_before_month[UNO + MONTHS_IN_YEAR] = {
//     START_OF_YEAR, JANUARY, FEBRUARY,  MARCH,   APRIL,    MAY,     JUNE,
//     JULY,          AUGUST,  SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};