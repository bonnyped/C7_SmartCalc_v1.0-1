#include "s21_smart_calc.h"

int main() {
  int error = 0;
  char *RPE = NULL;
  char *input_string = "1-3+5-11*0.12^2/33-Sin(2.1)+Cos(2^4)/"
                       "11+22-Tan(4)^3+1+2+(-3)/2+1^3-Log(12)/Log(3.4)\n";
  printf("\n\n\nINPUT STRING\n%sINPUT STRING\n\n\n", input_string);

  RPE = string_conversion(input_string);

  printf("\n\n\nRPE\n%s\nRPE\n\n\n", RPE);

  return 0;
}