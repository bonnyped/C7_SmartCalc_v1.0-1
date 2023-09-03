#include "s21_smart_calc.h"

void s21_credit_calc(credit *current_calculation) {
  current_calculation->not_months
      ? current_calculation->term = current_calculation->term / MONTHS_IN_YEAR
      : current_calculation->term;

  switch (current_calculation->type_of_pay) {
  case ANNUITETTE:
    calc_whole_payments_annuitette(
        current_calculation, current_calculation->loan_body,
        current_calculation->term, current_calculation->interest_rate);
    break;
  case DIFFERENTIAL:
    calc_whole_payments_differential(
        current_calculation, current_calculation->loan_body,
        current_calculation->term, current_calculation->interest_rate);
    break;
  };
}

void calc_whole_payments_annuitette(credit *current_calculation,
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

void calc_annuity_rate(credit *current_calculation, double loan_body,
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

void calc_whole_payments_differential(credit *current_calculation,
                                      double loan_body, double term,
                                      double interest_rate) {
  double monthly_payment_to_loan_body = loan_body / term;
  current_calculation->total_payment = loan_body;
  double month_overpayment = FALSE;

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
