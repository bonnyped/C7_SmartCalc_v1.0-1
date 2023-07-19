#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 4096
#define NUMBER_OF_FUNCTIONS_PLUS_X 11
#define MAX_CAPACITY_OF_NAME_FUNCTION 6
#define NUMBER_OF_OPERATORS 7
#define NUMBER_OF_ENTITIES_SEQUENCE 8
#define NUMBER_OF_ENTITIES 5
#define UNO (sizeof(operators) / sizeof(operators))

typedef struct stack {
  char *data;
  int priority;
  struct stack *next_element_stack;
} stack;

enum types_of_first_chars {
  SKIP = -1,
  IS_NUMBER = 1,
  IS_ALPHA,
  IS_OPERATOR,
};

enum input_errors {
  MORE_THEN_ONE_POINT = -5,
  ERROR_OF_SEQUENCE,
  NOT_REALLOCED,
  NOT_MATCHED_ALPHA_LEKSEMA,
  NOT_MATCHED_OPERATOR,
  EMPTY_STRING, // value == 0 must have
};

enum type_definition {
  OPEN_BRACKET = 40,
  CLOSE_BRACKET = 41,
  MULT = 42,
  PLUS = 43,
  MINUS = 45,
  POINT = 46,
  SUB = 47,
  DEGREE = 94,
};

enum entity {
  BINURY_OPERATOR,
  OPEN_BRACKETS,
  CLOSE_BRACKETS,
  FUNCTION,
  NUMBER,
};

enum entities_of_sequense {
  BEHIND_OPERATOR,
  BEHIND_OPEN_BRACKET,
  BEHIND_CLOSE_BRACKET,
  BEHIND_FUNCTION,
  TEMPLATE_RETURN_TO_ORIGINAL_STATE,
  BEHIND_NUMBER,
  FIRST_CHAR,
  LAST_CHAR,
};

enum reject_accept_sequence {
  FALSE,
  TRUE,
};

/* stack_functions */
stack *s21_push(stack *next_el);
stack *s21_pop(stack *next_el);
void s21_free_stack(stack *next_el);
void s21_set_data(stack *next_el, void *data, unsigned int size);
void s21_set_priority(stack *current_el, int priority);
/* stack_functions */

/* inverse_polish_notation_functions */
int string_conversion(char *input_string);
void add_number_output_string(char *A, char *B, int *start_to_write);
char *check_spaces_input_string(char *A, int *error);
int realloc_memory(char *ptr_for_realloc, int *capacity);
int check_current_priority(char *A);
stack *add_stack_operation(char *A, char *B, stack *stack_operation,
                           int *start_to_write);
stack *relocate_operators(stack *stack_operation, char *B, int *start_to_write);
/* inverse_polish_notation_functions */

/* transfer_functions */
char *delete_whitespaces(char *A, int index_A);
int add_zero_in_double_type(char *A, int index_A, char *B, int *index_B,
                            int *capacity, int *previous_entity,
                            int *current_sequence_element,
                            int type_of_first_char);
int transfer_number_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                 int *capacity, int *previous_entity,
                                 int *current_sequence_element,
                                 int type_of_first_char);
int transfer_alpha_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                int *capacity, int *current_entity,
                                int *previous_sequence_element,
                                int type_of_first_char);
int transfer_operator_to_B(const char *current_operator, int index_A, char *B,
                           int *index_B, int *capacity, int *current_entity,
                           int *previous_sequence_element,
                           int type_of_first_char);
int is_operator(char a);
void add_whitspace(int *start_to_write, int length, char *B);
/* transfer_functions */

/* check_functions */
int check_sequence(int *previous_entity, int *current_sequence_element,
                   int type_of_first_char, int element_of_vector, int operator);
int check_points_in_number(const char *B);
int multiplicity_plus_minus_check(const char *current_operator, int index_A,
                                  char *operator);
/* check_functions */

#endif // S21_SMART_CALC_H
