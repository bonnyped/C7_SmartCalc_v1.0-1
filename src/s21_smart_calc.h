#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CAPACITY 4096
#define NUMBER_OF_FUNCTIONS_PLUS_X 11
#define MAX_CAPACITY_OF_NAME_FUNCTION 6
#define NUMBER_OF_OPERATORS 7
#define NUMBER_OF_ENTITIES 5
#define JANUARY_MONTH 1
#define UNO 1
#define MONTHS_IN_YEAR 12
#define s21_epsilon 1e-7

typedef struct stack {
  char *data;
  double operand;
  int previous_priority;
  int associativity;
  struct stack *next_element_stack;
} stack;

typedef struct credit {
  double loan_body;
  double term;
  double interest_rate;
  int type_of_pay;
  double monthly_payment_max;
  double monthly_payment_min;
  double loan_overpayment;
  double total_payment;
} credit;

typedef struct withdrawals {
  int type_of_whithdrawl;
  int frequency;
  int date;
  int month;
  int year;
  double amount;
} withdrawals;

typedef struct deposit {
  double deposit_amount;
  double term;
  double interest_rate;
  double tax_rate;
  int payout_frequency;
  int interest_capitalization;
  withdrawals *replenishment_list;
  withdrawals *part_withdrawal_list;
} deposit;

typedef struct deposit_result {
  double accrued_interest;
  double tax_amount;
  double amount_on_deposit_by_the_end_of_the_term;
} deposit_result;

typedef struct datum {
  int date;
  int month;
  int year;
} datum;

enum types_of_first_chars {
  IS_NUMBER = 1,
  IS_ALPHA,
  IS_OPERATOR,
  IS_FUNCTION,
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

enum type_of_pay {
  DIFFERENTIAL = 1,
  ANNUITETTE,
};

enum months_or_years {
  MONTHS,
  YEARS,
};

enum type_of_whithdrawl {
  REMOVAL = 1,
  REFILL,
};

enum months {
  START_OF_YEAR,
  JANUARY = 0,
  FEBRUARY = 31,
  MARCH = 59,
  APRIL = 90,
  MAY = 120,
  JUNE = 151,
  JULY = 181,
  AUGUST = 212,
  SEPTEMBER = 243,
  OCTOBER = 273,
  NOVEMBER = 304,
  DECEMBER = 334,
};

enum type_of_year {
  NOT_LEAP_YEAR = 365,
  LEAP_YEAR,
};

enum end_start_of_year {
  END_DATE = 31,
  START_DATE = 1,
};

enum payout_frequency {
  PER_DAY = 1,
  PER_WEEK = 7,
  PER_MONTH = 31,
  PER_QUOTER,
  PER_YEAR,
  AT_THE_END_OF_TERM,
};

enum conditions_for_adding_periods {
  FEBRUARY_NL = 28,
  FEBRUARY_L,
  THIRTY_DAY_MONTH,
  THIRTY_ONE_DAY_MONTH,
  MORE_THAN_FABRUARY_NOT_LEAP = 1,
  MORE_THAN_FABRUARY_LEAP,
  MORE_THEN_THRTY_DAY_MONTH,
  MORE_THAN_DECEMBER,
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

/* calc_functions */
double calc_polish_revers_entry(char *pre);
int check_entity(char *start);
stack *calc_or_stack(int entity, stack *stacked_numbers, char *leksema);
stack *add_number_stack(stack *stacked_numbers, char *leksema);
void *calc_function(stack *stacked_numbers, char *leksema);
stack *calc_operands_wtih_operators(stack *stacked_numbers, char *leksema);
/* calc_functions */

/* credit_functions */
credit *s21_credit_calc(double loan_body, double term, double interest_rate,
                        int type_of_pay, int not_months);
void calc_whole_payments_annuitette(credit *current_calculation,
                                    double loan_body, double term,
                                    double interest_rate);
void calc_annuity_rate(credit *current_calculation, double loan_body,
                       double term, double interest_rate);
double floor_pyament(double value_to_floor);
void calc_whole_payments_differential(credit *current_calculation,
                                      double loan_body, double term,
                                      double interest_rate);
/* credit_functions */

/* deposit_calc_functions */
withdrawals *check_withdrawals(int type_of_whithdrawl, int frequency, int date,
                               int month, int year, double amount);
deposit_result *
s21_deposit_calc(double deposit_amount, double term, double interest_rate,
                 double tax_rate, int payout_frequency,
                 int interest_capitalization, withdrawals *replenishment_list,
                 withdrawals *part_withdrawal_list, datum *date_of_start);
void per_day_calculate(datum *start_date, int *current_year_type,
                       int *extra_day_from_leap_year, double interest_rate,
                       int *remaining_days, double *term,
                       double *deposit_amount);
void per_week_calculate(datum *start_date, int *current_year_type,
                        int *extra_day_from_leap_year, double interest_rate,
                        int *remaining_days, double *term,
                        double *deposit_amount, int *payout_frequency);
void per_month_calculate(datum *start_date, double *term,
                         double *deposit_amount, int *current_year_type,
                         double interest_rate, int *extra_day_from_leap_year,
                         int *temp_date, int *period_start);
int check_number_of_month_days(datum *start_date, int *current_year_type);
void plus_day_period(datum *start_date, int *current_year_type,
                     int *extra_day_from_leap_year);
int conditions_check_day(datum *start_date, int *current_year_type,
                         int *extra_day_from_leap_year);
double plus_week_period(datum *start_date, int *current_year_type,
                        double interest_rate, int *extra_day_from_leap_year);
double conditions_check_week(datum *start_date, int *current_year_type,
                             int *extra_day_from_leap_year);
double plus_month_period(datum *start_date, int *current_year_type,
                         double interest_rate, int *extra_day_from_leap_year,
                         int *temp_date, double *month_interest,
                         int condition_res);
int conditions_check_month(datum *start_date, int *current_year_type,
                           int *temp_date);
double leap_and_not_leap_periods(datum *start_date, double interest_rate,
                                 int *current_year_type,
                                 int count_days_in_period);
void calculate_remain_days_from_biggets_periods(
    int *remaining_days, double *term, double *day_period_interest_rate);
double calculate_period_interest_rate(double interest_rate,
                                      int days_in_current_year,
                                      int days_for_count_interest);
int calculate_days_from_christmas_to_date(datum *date_of_start);
int is_leap_year(int number_of_year);
// double calculate_accrued_interest(datum *date_of_start, double
// deposit_amount, double interest_rate);
// int calculate_days_in_period(datum *date_of_start, int
// *days_in_current_year); int calculate_days_from_start_era_to_current_day(int
// day, int month, int year);
/* deposit_calc_functions */

#endif // S21_SMART_CALC_H
