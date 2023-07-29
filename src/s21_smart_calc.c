#include "s21_smart_calc.h"

const char functions_plus_x[NUMBER_OF_FUNCTIONS_PLUS_X]
                           [MAX_CAPACITY_OF_NAME_FUNCTION] = {
                               "x\0",    "mod\0",  "cos\0",  "sin\0",
                               "tan\0",  "acos\0", "asin\0", "atan\0",
                               "sqrt\0", "ln\0",   "log\0"};

const int operators[NUMBER_OF_OPERATORS] = {
    PLUS, MINUS, MULT, DIV, OPEN_BRACKET, CLOSE_BRACKET, DEGREE};

const int regular_sequence_matrix[NUMBER_OF_OPERATORS][NUMBER_OF_ENTITIES] = {
    /* bin op_br cl_br  func  num*/
    {TRUE, TRUE, FALSE, TRUE, TRUE},    // BEHIND_BINARY_OPERATOR +
    {TRUE, TRUE, FALSE, TRUE, TRUE},    // BEHIND_OPEN_BRACKET    +
    {TRUE, FALSE, TRUE, FALSE, FALSE},  // BEHIND_CLOSE_BRACKET   -
    {FALSE, TRUE, FALSE, FALSE, FALSE}, // BEHIND_FUNCTION        -
    {TRUE, FALSE, TRUE, FALSE, FALSE},  // BEHIND_NUMBER          -
    {TRUE, TRUE, FALSE, TRUE, TRUE},    // FIRST_CHAR             +
    {FALSE, FALSE, TRUE, FALSE, TRUE},  // LAST_CHAR              -
};

int check_spaces_input_string(char *A, int *max_capacity_calloc,
                              char *transformed_string) {
  int current_entity = FIRST_CHAR;
  int skip = FALSE;
  int error = FALSE;
  int index_A = FALSE;
  int index_B = FALSE;
  int type_of_first_char = FALSE;
  size_t length = FALSE;
  int *previous_sequence_element =
      (int *)regular_sequence_matrix[current_entity];

  if (A)
    length = strlen(A);

  do {
    skip = FALSE;

    if (A[index_A] == ' ')
      A = delete_whitespaces(A, index_A);

    if (isdigit(A[index_A]) || A[index_A] == '.') {
      skip = TRUE;
      type_of_first_char = IS_NUMBER;
      index_A = (A[index_A] == '.'
                     ? add_zero_in_double_type(
                           A, index_A, transformed_string, &index_B,
                           max_capacity_calloc, &current_entity,
                           previous_sequence_element, type_of_first_char)
                     : transfer_number_leksema_to_B(
                           A, index_A, transformed_string, &index_B,
                           max_capacity_calloc, &current_entity,
                           previous_sequence_element, type_of_first_char));
    }

    if (isalpha(A[index_A]) && !skip) {
      skip = TRUE;
      type_of_first_char = IS_ALPHA;
      index_A = transfer_alpha_leksema_to_B(
          &A[index_A], index_A, transformed_string, &index_B,
          max_capacity_calloc, &current_entity, previous_sequence_element,
          type_of_first_char);
    }

    if (is_operator(A[index_A]) && !skip) {
      type_of_first_char = IS_OPERATOR;
      index_A =
          transfer_operator_to_B(&A[index_A], index_A, transformed_string,
                                 &index_B, max_capacity_calloc, &current_entity,
                                 previous_sequence_element, type_of_first_char);
      ;
    }
    previous_sequence_element = (int *)regular_sequence_matrix[current_entity];

  } while (A[index_A] != '\n' && index_A > 0);

  previous_sequence_element = (int *)regular_sequence_matrix[LAST_CHAR];
  if (previous_sequence_element[current_entity] == FALSE)
    index_A = ERROR_OF_SEQUENCE;

  if (index_A <= 0) {
    error = index_A;
    if (transformed_string) {
      free(transformed_string);
    }
  }

  return error;
}

char *delete_whitespaces(char *A, int index_A) {
  while (A[index_A] == ' ' || A[index_A] == '\t') {
    A++;
  }

  return A;
}

int add_zero_in_double_type(char *A, int index_A, char *B, int *index_B,
                            int *capacity, int *current_entity,
                            int *previous_sequence_element,
                            int type_of_first_char) {
  int error = 0;

  if (*index_B + UNO >= *capacity)
    error = realloc_memory(B, capacity);

  if (!error) {
    B[*index_B] = 48;
    *index_B = *index_B + UNO;
    index_A = transfer_number_leksema_to_B(
        A, index_A, B, index_B, capacity, current_entity,
        previous_sequence_element, type_of_first_char);
  }

  return index_A;
}

int transfer_number_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                 int *capacity, int *current_entity,
                                 int *previous_sequence_element,
                                 int type_of_first_char) {
  char numbers[] = "1234567890.";
  int length = strspn(&A[index_A], numbers);
  int error = FALSE;

  if (*index_B + length >= *capacity)
    error = realloc_memory(B, capacity);

  if (!error) {
    error = check_sequence(current_entity, previous_sequence_element,
                           type_of_first_char, FALSE, FALSE);
    if (!error) {
      strncpy(&B[*index_B], &A[index_A], length);
      error = check_points_in_number(&B[*index_B]);
      if (!error) {
        index_A += length;
        add_whitspace(index_B, length, B);
      }
    }
  }

  if (error)
    index_A = error;

  return index_A;
}

int check_points_in_number(const char *B) {
  int error = FALSE;
  int count_points = FALSE;
  char *temp = NULL;

  while (temp = strchr(B, POINT)) {
    B = temp;
    B++;
    count_points++;
  }

  count_points < 2 ? error : (error = MORE_THEN_ONE_POINT);

  return error;
}

int transfer_alpha_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                int *capacity, int *current_entity,
                                int *previous_sequence_element,
                                int type_of_first_char) {
  int error = NOT_MATCHED_ALPHA_LEKSEMA;
  int result = FALSE;
  int no_matches = NUMBER_OF_FUNCTIONS_PLUS_X;
  int element_of_vector = FALSE;
  size_t length = FALSE;
  char template[MAX_CAPACITY_OF_NAME_FUNCTION] = {0};

  for (; element_of_vector < no_matches && error; element_of_vector++) {
    length = strlen(*(&functions_plus_x[element_of_vector]));
    strxfrm(template, A, length);
    for (size_t i = 0; i < length; i++) {
      template[i] = tolower(template[i]);
    }
    !strncmp(template, *(&functions_plus_x[element_of_vector]), length)
        ? error = check_sequence(current_entity, previous_sequence_element,
                                 type_of_first_char, element_of_vector, FALSE)
        : error;
    if (!error)
      result = abbreviation_functions_name(element_of_vector);
  }

  if (!error) {
    if (*index_B + length >= *capacity)
      error = realloc_memory(B, capacity);

    if (!error) {
      B[*index_B] = result;
      index_A += length;
      add_whitspace(index_B, UNO, B);
    }
  }

  if (error)
    index_A = error;

  return index_A;
}

int transfer_operator_to_B(const char *current_operator, int index_A, char *B,
                           int *index_B, int *capacity, int *current_entity,
                           int *previous_sequence_element,
                           int type_of_first_char) {
  int error = FALSE;
  int element_of_vector = FALSE;
  int max = NUMBER_OF_OPERATORS;
  char operator= * current_operator;
  int input_index_A = index_A;

  error = check_sequence(current_entity, previous_sequence_element,
                         type_of_first_char, FALSE, operator);

  if (!error) {
    if (*index_B + UNO >= *capacity)
      error = realloc_memory(B, capacity);

    if (!error) {
      B[*index_B] = operator;
      index_A++;
      add_whitspace(index_B, UNO, B);
      if (input_index_A == FALSE && operator== MINUS)
        *current_entity = FIRST_CHAR;
    }
  } else
    index_A = error;

  return index_A;
}

int realloc_memory(char *ptr_for_realloc, int *capacity) {
  int result = NOT_REALLOCED;
  char *new_block = NULL;

  (new_block = realloc(ptr_for_realloc, *capacity * 2)) ? result = 0 : result;

  !result ? *capacity = *capacity * 2 : *capacity;

  return result;
}

int is_operator(char a) {
  int result = 0;
  if (a == PLUS || a == MINUS || a == MULT || a == DIV || a == OPEN_BRACKET ||
      a == CLOSE_BRACKET || a == DEGREE || a == 'm' || a == 'M')
    result = 1;

  return result;
}

int abbreviation_functions_name(int number_of_vectors_element) {
  int result = FALSE;

  switch (number_of_vectors_element) {
  case 0:
    result = X_N;
    break;
  case 1:
    result = MOD_F;
    break;
  case 2:
    result = COS_F;
    break;
  case 3:
    result = SIN_F;
    break;
  case 4:
    result = TAN_F;
    break;
  case 5:
    result = ACOS_F;
    break;
  case 6:
    result = ASIN_F;
    break;
  case 7:
    result = ATAN_F;
    break;
  case 8:
    result = SQRT_F;
    break;
  case 9:
    result = LN_F;
    break;
  case 10:
    result = LOG_F;
    break;
  default:
    break;
  }

  return result;
}

stack *add_number_output_string(char *A, char *B, int *start_to_write,
                                int *number_of_operands,
                                stack *stack_operation) {
  int result = FALSE;
  size_t length = FALSE;

  if (A)
    (*A >= 48 && *A <= 57) || *A == 'x' ? result = TRUE : result;

  if (result) {
    length = strlen(A);
    memcpy(&B[*start_to_write], A, length);
    add_whitspace(start_to_write, length, B);
    *number_of_operands += UNO;
    while (stack_operation && stack_operation->associativity == -1) {
      stack_operation =
          relocate_unary_binary_operators(stack_operation, B, start_to_write);
    }
  }
  return stack_operation;
}

void add_whitspace(int *start_to_write, int length, char *B) {
  *start_to_write = *start_to_write + length;
  B[*start_to_write] = ' ';
  *start_to_write = *start_to_write + 1;
}

stack *upload_offload_stack(char *A, char *B, stack *stack_operation,
                            int *start_to_write, int *error,
                            int *number_of_operands) {
  int result = FALSE;
  int current_priority = FALSE;
  int associativity = FALSE;

  if (A)
    (*A >= 48 && *A <= 57) || *A == 'x' ? result : (result = TRUE);

  if (result) {
    if ((current_priority = check_current_priority(A)) == DEGREE)
      associativity = TRUE;
    if (is_operator(*A))
      stack_operation = upload_offload_stack_operation(
          A, B, stack_operation, start_to_write, current_priority,
          associativity, error, number_of_operands);
    else {
      stack_operation = upload_function(A, stack_operation);
    }
  }

  return stack_operation;
}

int check_current_priority(char *A) {
  int priority = 0;

  if ((*A == PLUS || *A == MINUS) || (isalpha(*A) && *A != 'x'))
    priority = LOW;
  if (*A == MULT || *A == DIV)
    priority = MID;
  if (*A == DEGREE)
    priority = DEGREE;

  return priority;
}

stack *upload_offload_stack_operation(char *A, char *B, stack *stack_operation,
                                      int *start_to_write, int current_priority,
                                      int associativity, int *error,
                                      int *number_of_operands) {
  int skip = FALSE;

  stack_operation =
      check_unary_operators(A, stack_operation, number_of_operands, &skip);
  stack_operation = check_brackets(A, stack_operation, number_of_operands,
                                   &skip, B, start_to_write, error);
  if (!skip) {
    if (stack_operation) {
      stack_operation = rightassociativity_equal_operation(
          stack_operation, current_priority, A, &skip, associativity);
      stack_operation =
          prefix_function_on_top(stack_operation, skip, B, start_to_write);
      stack_operation = priority_low_or_equal(stack_operation, skip, B,
                                              start_to_write, current_priority);
      stack_operation = leftassociativity_equal_operation(
          stack_operation, skip, B, start_to_write, current_priority);
      if (!skip)
        stack_operation =
            push_and_set_operation(stack_operation, current_priority, A);
    } else {
      if (!skip)
        stack_operation =
            push_and_set_operation(stack_operation, current_priority, A);
    }
    *number_of_operands = FALSE;
  }

  return stack_operation;
}

stack *check_unary_operators(char *A, stack *stack_operation,
                             int *number_of_operands, int *skip) {
  if ((*A == PLUS || *A == MINUS) && *number_of_operands == FALSE) {
    if (*A == PLUS)
      *skip = TRUE;
    else {
      char its_unary = UNARY_MINUS;
      stack_operation =
          push_and_set_operation(stack_operation, FALSE, &its_unary);
      *skip = TRUE;
    }
  }
  return stack_operation;
}

stack *check_brackets(char *A, stack *stack_operation, int *number_of_operands,
                      int *skip, char *B, int *start_to_write, int *error) {
  if (!(*skip) && *A == OPEN_BRACKET) {
    stack_operation = push_and_set_operation(stack_operation, MAX, A);
    *number_of_operands = FALSE;
    *skip += TRUE;
  } else if (!(*skip) && *A == CLOSE_BRACKET) {
    while (stack_operation && *(char *)stack_operation->data != OPEN_BRACKET) {
      stack_operation = relocate_operators(B, start_to_write, stack_operation);
    }
    if (stack_operation && *(char *)stack_operation->data == OPEN_BRACKET) {
      stack_operation = s21_pop(stack_operation);

      while (stack_operation && *(char *)stack_operation->data == UNARY_MINUS) {
        stack_operation =
            relocate_operators(B, start_to_write, stack_operation);
      }
    } else
      *error = NO_OPEN_BRACKET;

    *skip += TRUE;
  }

  return stack_operation;
}

stack *rightassociativity_equal_operation(stack *stack_operation,
                                          int current_priority, char *A,
                                          int *skip, int associativity) {
  if (!(*skip) && stack_operation->associativity == associativity &&
      current_priority == DEGREE) {
    *skip = TRUE;
    stack_operation =
        push_and_set_operation(stack_operation, current_priority, A);
  }

  return stack_operation;
}
stack *prefix_function_on_top(stack *stack_operation, int skip, char *B,
                              int *start_to_write) {
  while (!skip && stack_operation && isalpha(*stack_operation->data)) {
    stack_operation =
        relocate_unary_binary_operators(stack_operation, B, start_to_write);
  }
  return stack_operation;
}

stack *priority_low_or_equal(stack *stack_operation, int skip, char *B,
                             int *start_to_write, int current_priority) {
  while (!skip && stack_operation && is_operator(*stack_operation->data) &&
         stack_operation->previous_priority >= current_priority &&
         stack_operation->previous_priority != MAX) {
    stack_operation =
        relocate_unary_binary_operators(stack_operation, B, start_to_write);
  }
  return stack_operation;
}

stack *leftassociativity_equal_operation(stack *stack_operation, int skip,
                                         char *B, int *start_to_write,
                                         int current_priority) {
  while (!skip && stack_operation && stack_operation->associativity == FALSE &&
         stack_operation->previous_priority == current_priority) {
    stack_operation =
        relocate_unary_binary_operators(stack_operation, B, start_to_write);
  }
  return stack_operation;
}

stack *relocate_unary_binary_operators(stack *stack_operation, char *B,
                                       int *start_to_write) {
  memcpy(&B[*start_to_write], stack_operation->data, UNO);
  add_whitspace(start_to_write, UNO, B);
  stack_operation = s21_pop(stack_operation);

  return stack_operation;
}

stack *push_and_set_operation(stack *stack_operation, int current_priority,
                              char *A) {
  stack_operation = s21_push(stack_operation);
  s21_set_priority(stack_operation, current_priority);
  s21_set_associativity(stack_operation, A);
  s21_set_data(stack_operation, A, sizeof(A));

  return stack_operation;
}

stack *upload_function(char *A, stack *stack_operation) {
  stack_operation = s21_push(stack_operation);
  s21_set_priority(stack_operation, FALSE);
  s21_set_associativity(stack_operation, A);
  s21_set_data(stack_operation, A, sizeof(A));

  return stack_operation;
}

stack *relocate_operators(char *B, int *start_to_write,
                          stack *stack_operation) {
  memcpy(&B[*start_to_write], stack_operation->data, UNO);
  add_whitspace(start_to_write, UNO, B);
  stack_operation = s21_pop(stack_operation);

  return stack_operation;
}
