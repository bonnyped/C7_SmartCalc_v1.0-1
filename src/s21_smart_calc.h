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
#define NUMBER_OF_ENTITIES 5
#define UNO 1

typedef struct stack {
  char *data;
  int previous_priority;
  int associativity;
  struct stack *next_element_stack;
} stack;

enum types_of_first_chars {
  IS_NUMBER = 1,
  IS_ALPHA,
  IS_OPERATOR,
};

enum input_errors {
  NO_OPEN_BRACKET = -6,
  MORE_THEN_ONE_POINT,
  ERROR_OF_SEQUENCE,
  NOT_REALLOCED,
  NOT_MATCHED_ALPHA_LEKSEMA,
  EMPTY_STRING, // value == 0 must have
};

enum type_definition {
  OPEN_BRACKET = 40,
  CLOSE_BRACKET = 41,
  MULT = 42,
  PLUS = 43,
  MINUS = 45,
  UNARY_MINUS = 126,
  POINT = 46,
  DIV = 47,
  DEGREE = 94,
};

enum prefix_function {
  X_N = 'x',
  MOD_F = 'm',
  COS_F = 'c',
  SIN_F = 's',
  TAN_F = 't',
  ACOS_F = 'a',
  ASIN_F = 'i',
  ATAN_F = 'n',
  SQRT_F = 'q',
  LN_F = 'l',
  LOG_F = 'g',
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
  BEHIND_NUMBER,
  FIRST_CHAR,
  LAST_CHAR,
};

enum boolen_entities {
  FALSE,
  TRUE,
};

enum priority {
  LOW,
  MID,
  MAX = 3,
};

/* stack_functions */
stack *s21_push(stack *next_el);
stack *s21_pop(stack *next_el);
void s21_free_stack(stack *next_el);
void s21_set_data(stack *next_el, void *data, unsigned int size);
void s21_set_priority(stack *current_el, int priority);
void s21_set_associativity(stack *current_el, char *operation);
/* stack_functions */

/* inverse_polish_notation_functions */
char *string_conversion(char *input_string);
int check_spaces_input_string(char *A, int *max_capacity_calloc,
                              char *transformed_string);
stack *add_number_output_string(char *A, char *B, int *start_to_write,
                                int *number_of_operands,
                                stack *stack_operation);
stack *upload_offload_stack(char *A, char *B, stack *stack_operation,
                            int *start_to_write, int *error,
                            int *number_of_operands);
int check_current_priority(char *A);
stack *upload_offload_stack_operation(char *A, char *B, stack *stack_operation,
                                      int *start_to_write, int current_priority,
                                      int associativity, int *error,
                                      int *number_of_operands);
stack *check_unary_operators(char *A, stack *stack_operation,
                             int *number_of_operands, int *skip);
stack *check_brackets(char *A, stack *stack_operation, int *number_of_operands,
                      int *skip, char *B, int *start_to_write, int *error);
stack *rightassociativity_equal_operation(stack *stack_operation,
                                          int current_priority, char *A,
                                          int *skip, int associativity);
stack *prefix_function_on_top(stack *stack_operation, int skip, char *B,
                              int *start_to_write);
stack *priority_low_or_equal(stack *stack_operation, int skip, char *B,
                             int *start_to_write, int current_priority);
stack *leftassociativity_equal_operation(stack *stack_operation, int skip,
                                         char *B, int *start_to_write,
                                         int current_priority);
stack *upload_function(char *A, stack *stack_operation);
stack *push_and_set_operation(stack *stack_operation, int current_priority,
                              char *A);
stack *relocate_operators(char *B, int *start_to_write, stack *stack_operation);
stack *relocate_unary_binary_operators(stack *stack_operation, char *B,
                                       int *start_to_write);
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
int realloc_memory(char *ptr_for_realloc, int *capacity);
int abbreviation_functions_name(int number_of_vectors_element);
/* transfer_functions */

/* check_functions */
int check_sequence(int *previous_entity, int *current_sequence_element,
                   int type_of_first_char, int element_of_vector, int operator);
int check_points_in_number(const char *B);
int multiplicity_plus_minus_check(const char *current_operator, int index_A,
                                  char *operator);
/* check_functions */

#endif // S21_SMART_CALC_H
