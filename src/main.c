// Copyright [2023] <Copyright bonnyped>

#include "s21_smart_calc.h"

int main() {
  int error = FALSE;
  double res = FALSE;
  // credit *result = NULL;
  deposit *result_dep = NULL;

  if ((result_dep = calloc(UNO, sizeof(deposit)))) {
    result_dep->start_date = calloc(UNO, sizeof(datum));
    // add list
    // result_dep->add_list = calloc(UNO, sizeof(drop_add_lists));
    // result_dep->add_list->date_add_drop = calloc(UNO, sizeof(drop_add_lists));
    // result_dep->add_list->date_add_drop->date = 16;
    // result_dep->add_list->date_add_drop->month = 03;
    // result_dep->add_list->date_add_drop->year = 2024;
    // result_dep->add_list->amount = 1000000;
    // result_dep->add_list->frequency = PER_ONCE;

    // drop list
    // result_dep->drop_list = calloc(UNO, sizeof(drop_add_lists));
    // result_dep->drop_list->date_add_drop = calloc(UNO, sizeof(drop_add_lists));
    // result_dep->drop_list->date_add_drop->date = 18;
    // result_dep->drop_list->date_add_drop->month = 02;
    // result_dep->drop_list->date_add_drop->year = 2024;
    // result_dep->drop_list->amount = 50000;
    // result_dep->drop_list->frequency = PER_ONCE;

    result_dep->amount = 123000;
    result_dep->interest_rate = 15;
    result_dep->term = 120;
    result_dep->tax_rate = 12;
    result_dep->interest_capitalization = TRUE;
    result_dep->payout_frequency = PER_DAY;
    result_dep->start_date->date = 15;
    result_dep->start_date->month = 12;
    result_dep->start_date->year = 2023;
  }
  // if ((result = calloc(UNO, (sizeof(credit))))) {
  //   result->interest_rate = 11;
  //   result->loan_body = 111;
  //   result->term = 11;
  //   result->type_of_pay = DIFFERENTIAL;
  //   result->not_months = FALSE;
  // }

  // char *RPE = NULL;
  // int type_of_term = MONTHS;
  // char *input_string = "sin(-(-2^(-3)))+log(10^(-4)*10^4*10)\0";
  // printf("\n\n\nINPUT STRING\n%s\nINPUT STRING\n\n\n", input_string);
  // s21_credit_calc(result);

  // RPE = string_conversion(input_string, &error);

  // printf("\n\n\nRPE\n%s\nRPE\n\n\n", RPE);

  // res = calc_polish_reverse_entry(RPE, 0.93);

  // double deposit_amount = 100000;
  // double term = 365;
  // double interest_rate = 4;
  // double tax_rate = FALSE;
  // int payout_frequency = PER_YEAR;
  // int interest_capitalization = 4;
  // datum *date_of_start = calloc(UNO, sizeof(deposit));
  // date_of_start->date = 30;
  // date_of_start->month = 12;
  // date_of_start->year = 2018;

  s21_deposit_calc(result_dep);

  //   printf("\n\n\nmontly_payment\n%.2lf\nmontly_payment\n\nloan_overpayment\n%."
  //          "2lf\nloan_overpayment\n\ntotal\n%.2lf\ntatal\n",
  //          result->monthly_payment_max, result->loan_overpayment,
  //          result->total_payment);
  // result ? free(result) : result;
  if (result_dep) {
    if (result_dep->start_date)
      free(result_dep->start_date);
    if (result_dep->add_list) {
      if (result_dep->add_list->date_add_drop)
        free(result_dep->add_list->date_add_drop);
      free(result_dep->add_list);
    }
    free(result_dep);
  }

  return 0;
}