#include "s21_smart_calc.h"

int main() {
  int error = 0;
  char *input_string = "--.324234\n";
  printf("\n\n\nINPUT STRING\n%s\nINPUT STRING\n\n\n", input_string);

  error = string_conversion(input_string);

  printf("\n\n\nRESULT\n%d\nRESULT\n\n\n", error);

  return 0;
}