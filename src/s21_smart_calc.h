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
#define UNO (sizeof(operators) / sizeof(operators))

typedef struct stack {
  char *data;
  int priority;
  struct stack *next_element_stack;
} stack;

enum input_errors {
  NOT_REALLOCED = -3,
  NOT_MATCHED_ALPHA_LEKSEMA,
  NOT_MATCHED_OPERATOR,
  EMPRY_STRING,
};

enum type_definition {
  PLUS = 43,
  MINUS = 45,
  MULT = 45,
  SUB = 47,
  OPEN_BRACKET = 40,
  CLOSE_BRACKET = 41,
  DEGREE = 94,
  WHITESPACE = 32,
};

stack *s21_push(stack *next_el);
stack *s21_pop(stack *next_el);
void s21_free_stack(stack *next_el);
void s21_set_data(stack *next_el, void *data, unsigned int size);
void s21_set_priority(stack *current_el, int priority);

char *check_spaces_input_string(char *A);
int realloc_memory(char *ptr_for_realloc, int *capacity);
int isoperator(char a);

char *delete_whitespaces(char *A, int index_A);
int add_zero_in_double_type(char *A, int index_A, char *B, int *index_B,
                            int *capacity);
int transfer_number_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                 int *capacity);
int transfer_alpha_leksema_to_B(char *A, int index_A, char *B, int *index_B,
                                int *capacity);
int transfer_operator_to_B(char current_operator, int index_A, char *B,
                           int *index_B, int *capacity);

void add_number_output_string(char *A, char *B, int *start_to_write);
void add_whitspace(int *start_to_write, int length, char *B);
stack *add_stack_operation(char *A, char *B, stack *stack_operation,
                           int *start_to_write);
int check_current_priority(char *A);
stack *relocate_operators(stack *stack_operation, char *B, int *start_to_write);

#endif // S21_SMART_CALC_H