#include "s21_smart_calc.h"

const char functions_plus_x[NUMBER_OF_FUNCTIONS_PLUS_X]
                           [MAX_CAPACITY_OF_NAME_FUNCTION] = {
                               "x\0",    "mod\0",  "cos\0",  "sin\0",
                               "tan\0",  "acos\0", "asin\0", "atan\0",
                               "sqrt\0", "ln\0",   "log\0"};

const int operators[NUMBER_OF_OPERATORS] = {
    PLUS, MINUS, MULT, SUB, OPEN_BRACKET, CLOSE_BRACKET, DEGREE};

const int
    regular_sequence_matrix[NUMBER_OF_ENTITIES_SEQUENCE][NUMBER_OF_ENTITIES] = {
        /* bin op_br cl_br  func  num*/
        {TRUE, TRUE, FALSE, TRUE, TRUE},    // BEHIND_BINARY_OPERATOR
        {FALSE, FALSE, FALSE, TRUE, TRUE},  // BEHIND_OPEN_BRACKET
        {TRUE, FALSE, FALSE, FALSE, FALSE}, // BEHIND_CLOSE_BRACKET
        {FALSE, TRUE, FALSE, FALSE, FALSE}, // BEHIND_FUNCTION
        {TRUE, FALSE, TRUE, FALSE, FALSE},  // BEHIND_NUMBER
        {TRUE, TRUE, TRUE, TRUE, TRUE},     // TEMLATE
        {TRUE, TRUE, FALSE, TRUE, TRUE},    // FIRST_CHAR
        {FALSE, FALSE, TRUE, FALSE, TRUE},  // LAST_CHAR
};

char *check_spaces_input_string(char *A, int *error) {
  char *B = NULL;
  int *previous_sequence_element = NULL;
  int max_capacity_calloc = MAX_CAPACITY;
  int length = strlen(A);
  int current_entity = FIRST_CHAR;
  int index_A = FALSE;
  int index_B = FALSE;
  int type_of_first_char = FALSE;

  previous_sequence_element = (int *)regular_sequence_matrix[current_entity];
  B = calloc(max_capacity_calloc, sizeof(char));

  do {
    if (A[index_A] == ' ')
      A = delete_whitespaces(A, index_A);
    if (A[index_A] == '.') {
      type_of_first_char = IS_NUMBER;
      index_A = add_zero_in_double_type(
          A, index_A, B, &index_B, &max_capacity_calloc, &current_entity,
          previous_sequence_element, type_of_first_char);
      previous_sequence_element =
          (int *)regular_sequence_matrix[current_entity];
    }

    if (isdigit(A[index_A])) {
      type_of_first_char = IS_NUMBER;
      index_A = transfer_number_leksema_to_B(
          A, index_A, B, &index_B, &max_capacity_calloc, &current_entity,
          previous_sequence_element, type_of_first_char);
      previous_sequence_element =
          (int *)regular_sequence_matrix[current_entity];
    }

    if (isalpha(A[index_A])) {
      type_of_first_char = IS_ALPHA;
      index_A = transfer_alpha_leksema_to_B(
          &A[index_A], index_A, B, &index_B, &max_capacity_calloc,
          &current_entity, previous_sequence_element, type_of_first_char);
      previous_sequence_element =
          (int *)regular_sequence_matrix[current_entity];
    }

    if (is_operator(A[index_A])) {
      type_of_first_char = IS_OPERATOR;
      index_A = transfer_operator_to_B(
          &A[index_A], index_A, B, &index_B, &max_capacity_calloc,
          &current_entity, previous_sequence_element, type_of_first_char);
      previous_sequence_element =
          (int *)regular_sequence_matrix[current_entity];
    }

  } while (A[index_A] != '\n' && index_A > 0);
  printf("\n\n\n\n!!!!\n%s\n!!!!\n\n\n\n", B); // clean memory B
  if (!index_A)
    printf("\nEMTY_STRING\n");
  if (index_A < 0) {
    *error = index_A;
  }

  return B;
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
  int no_matches = NUMBER_OF_FUNCTIONS_PLUS_X;
  int element_of_vector = 0;
  size_t length = 0;
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
  }

  if (!error) {
    if (*index_B + length >= *capacity)
      error = realloc_memory(B, capacity);

    if (!error) {
      strcpy(&B[*index_B], template);
      index_A += length;
      add_whitspace(index_B, length, B);
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
  int error = NOT_MATCHED_OPERATOR;
  int no_mathes = NUMBER_OF_OPERATORS;
  int element_of_vector = 0;
  char operator= * current_operator;

  index_A = multiplicity_plus_minus_check(current_operator, index_A, &operator);

  for (; element_of_vector < no_mathes && error; element_of_vector++) {
    operator== operators[element_of_vector]
        ? error = check_sequence(current_entity, previous_sequence_element,
                                 type_of_first_char, FALSE, operator)
        : error;
  }

  if (!error) {
    if (*index_B + UNO >= *capacity)
      error = realloc_memory(B, capacity);

    if (!error) {
      B[*index_B] = operator;
      if (*(current_operator + index_A) == operator)
        index_A += UNO;
      add_whitspace(index_B, UNO, B);
    }
  } else
    index_A = error;

  return index_A;
}

int multiplicity_plus_minus_check(const char *current_operator, int index_A,
                                  char *operator) {
  char *pointer_of_current_operator = (char *)current_operator;

  while (*pointer_of_current_operator == PLUS) {
    pointer_of_current_operator++;
    index_A++;
  }
  while (*pointer_of_current_operator == MINUS) {
    if (pointer_of_current_operator != current_operator)
      *operator== PLUS ? *operator= MINUS : (*operator= PLUS);

    pointer_of_current_operator++;
    index_A++;
  }
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
  if (a == PLUS || a == MINUS || a == MULT || a == SUB || a == OPEN_BRACKET ||
      a == CLOSE_BRACKET || a == DEGREE)
    result = 1;

  return result;
}

void add_number_output_string(char *A, char *B, int *start_to_write) {
  int res = 0;
  int length = 0;

  if (A)
    *A >= 48 && *A <= 57 ? res = 1 : res;

  if (res) {
    length = strlen(A);
    memcpy(&B[*start_to_write], A, length);
    add_whitspace(start_to_write, length, B);
  }
}

void add_whitspace(int *start_to_write, int length, char *B) {
  *start_to_write = *start_to_write + length;
  B[*start_to_write] = ' ';
  *start_to_write = *start_to_write + 1;
}

stack *add_stack_operation(char *A, char *B, stack *stack_operation,
                           int *start_to_write) {
  int res = 0;
  int current_priority = 0;
  int previous_priority = 0;

  if (A)
    *A >= 48 && *A <= 57 ? res : (res = 1);
  if (res) {
    current_priority = check_current_priority(A);
    if (stack_operation) {
      previous_priority = stack_operation->priority;
      if (current_priority > previous_priority) {
        stack_operation =
            relocate_operators(stack_operation, B, start_to_write);
        stack_operation = s21_push(stack_operation);
        s21_set_data(stack_operation, A, sizeof(A));
      } else {
        stack_operation = s21_push(stack_operation);
        s21_set_data(stack_operation, A, sizeof(A));
      }
    } else {
      stack_operation = s21_push(stack_operation);
      s21_set_priority(stack_operation, current_priority);
      s21_set_data(stack_operation, A, sizeof(A));
    }
  }
  return stack_operation;
}

int check_current_priority(char *A) {
  int res = 0;
  int length = 0;

  length = strlen(A);
  if (length == 1 && (*A == 47 || *A == 45))
    res = 1;

  return res;
}

stack *relocate_operators(stack *stack_operation, char *B,
                          int *start_to_write) {
  while (stack_operation) {
    int length = 0;

    length = strlen((char *)stack_operation->data);
    memcpy(&B[*start_to_write], stack_operation->data, length);
    add_whitspace(start_to_write, length, B);
    stack_operation = s21_pop(stack_operation);
  }

  return stack_operation;
}
