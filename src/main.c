#include "s21_smart_calc.h"

int main() {
  int error = FALSE;
  credit_struct *result = NULL;
  char *RPE = NULL;
  int type_of_term = MONTHS;
  char *input_string = "SiN(3.1412)\n";
  printf("\n\n\nINPUT STRING\n%sINPUT STRING\n\n\n", input_string);

  result = s21_credit_calc(300000, 18, 15, DIFFERENTIAL, type_of_term);

  RPE = string_conversion(input_string);

  printf("\n\n\nRPE\n%s\nRPE\n\n\n", RPE);

  calc_polish_revers_entry(RPE);

  printf("\n\n\nmontly_payment\n%.2lf\nmontly_payment\n\nloan_overpayment\n%."
         "2lf\nloan_overpayment\n\ntotal\n%.2lf\ntatal\n",
         result->monthly_payment_max, result->loan_overpayment,
         result->total_payment);
  result ? free(result) : result;

  return 0;
}