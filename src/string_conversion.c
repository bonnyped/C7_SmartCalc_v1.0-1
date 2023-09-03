#include "s21_smart_calc.h"

char *string_conversion(char *input_string) {
  int max_capacity_calloc = MAX_CAPACITY;
  int start_to_write = FALSE;
  int error = FALSE;
  int number_of_operands = FALSE;
  stack *stack_operation = NULL;
  char *start = NULL;
  char *string_with_spaces = NULL;
  char *reverse_polish_entry = NULL;

  string_with_spaces = calloc(max_capacity_calloc, sizeof(char));

  error = check_spaces_input_string(input_string, &max_capacity_calloc,
                                    string_with_spaces);
  if (string_with_spaces && !error) {

    printf("\ntransformed string\n%s\ntransformed string\n",
           string_with_spaces);

    reverse_polish_entry = malloc(max_capacity_calloc * (sizeof(char)));

    do {
      !start ? start = strtok(string_with_spaces, " ")
             : (start = strtok(NULL, " "));
      if (start) {
        stack_operation = add_number_output_string(
            start, reverse_polish_entry, &start_to_write, &number_of_operands,
            stack_operation);
        stack_operation =
            upload_offload_stack(start, reverse_polish_entry, stack_operation,
                                 &start_to_write, &error, &number_of_operands);
      } else {
        while (stack_operation && stack_operation->previous_priority < MAX) {
          stack_operation = relocate_operators(
              reverse_polish_entry, &start_to_write, stack_operation);
        }
      }
    } while (start);
  }
  string_with_spaces ? free(string_with_spaces) : string_with_spaces;

  printf("\nERROR\n%d\nERROR\n", error);

  return reverse_polish_entry;
}
