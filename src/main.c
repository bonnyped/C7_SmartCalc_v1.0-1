#include "s21_smart_calc.h"

int main() {
  int error = FALSE;
  credit *result = NULL;
  deposit_result *result_dep = NULL;
  char *RPE = NULL;
  int type_of_term = MONTHS;
  char *input_string = "SiN(3.1412)\n";
  printf("\n\n\nINPUT STRING\n%sINPUT STRING\n\n\n", input_string);

  result = s21_credit_calc(300000, 18, 15, DIFFERENTIAL, type_of_term);

  RPE = string_conversion(input_string);

  printf("\n\n\nRPE\n%s\nRPE\n\n\n", RPE);

  calc_polish_revers_entry(RPE);

  double deposit_amount = 100000;
  double term = 595;
  double interest_rate = 4;
  double tax_rate = FALSE;
  int payout_frequency = PER_DAY;
  int interest_capitalization = 4;
  datum *date_of_start = calloc(UNO, sizeof(deposit));
  date_of_start->date = 30;
  date_of_start->month = 12;
  date_of_start->year = 2022;

  result_dep = s21_deposit_calc(deposit_amount, term, interest_rate, tax_rate,
                                payout_frequency, interest_capitalization, NULL,
                                NULL, date_of_start);

  printf("\n\n\nmontly_payment\n%.2lf\nmontly_payment\n\nloan_overpayment\n%."
         "2lf\nloan_overpayment\n\ntotal\n%.2lf\ntatal\n",
         result->monthly_payment_max, result->loan_overpayment,
         result->total_payment);
  result ? free(result) : result;

  return 0;
}