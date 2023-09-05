#include "s21_smart_calc.h"

const char types_of_errors[6][28] = {
    "EMPTY_STRING\0",      "NOT_MATCHED_ALPHA_LEKSEMA\0", "NOT_REALLOCED\0",
    "ERROR_OF_SEQUENCE\0", "MORE_THEN_ONE_POINT\0",       "NO_OPEN_BRACKET\0"};

char *string_conversion(char *input_string, int *error) {
  int max_capacity_calloc = MAX_CAPACITY;
  int start_to_write = FALSE;
  int number_of_operands = FALSE;
  stack *stack_operation = NULL;
  char *start = NULL;
  char *string_with_spaces = NULL;
  char *tmp_string_with_spaces = NULL;
  char *reverse_polish_entry = NULL;

  string_with_spaces = calloc(max_capacity_calloc, sizeof(char));

  *error = check_spaces_input_string(input_string, &max_capacity_calloc,
                                     string_with_spaces);

  if (!*error) {
    tmp_string_with_spaces = strdup((const char *)string_with_spaces);
    reverse_polish_entry = calloc(max_capacity_calloc, (sizeof(char)));

    do {
      !start ? start = strtok(tmp_string_with_spaces, " ")
             : (start = strtok(NULL, " "));
      if (start) {
        stack_operation = add_number_output_string(
            start, reverse_polish_entry, &start_to_write, &number_of_operands,
            stack_operation);
        stack_operation =
            upload_offload_stack(start, reverse_polish_entry, stack_operation,
                                 &start_to_write, error, &number_of_operands);
      } else {
        if (*error)
          s21_free_stack(stack_operation);
        else
          while (stack_operation) {
            stack_operation = relocate_operators(
                reverse_polish_entry, &start_to_write, stack_operation);
          }
        // if(stack_operation)
        //   stack_operation= s21_pop(stack_operation);
      }
    } while (start);
    if (tmp_string_with_spaces) free(tmp_string_with_spaces);
    if (string_with_spaces) free(string_with_spaces);
  } else {
    if (reverse_polish_entry) free(reverse_polish_entry);
    reverse_polish_entry = NULL;
    reverse_polish_entry = (char *)&types_of_errors[abs(*error)];
  }

  return reverse_polish_entry;
}
