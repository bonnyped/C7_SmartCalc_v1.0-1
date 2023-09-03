#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CAPACITY 4096
#define CAPACITY_OF_NAME_ERRORS 25
#define NUMBER_OF_FUNCTIONS_PLUS_X 11
#define MAX_CAPACITY_OF_NAME_FUNCTION 6
#define NUMBER_OF_OPERATORS 7
#define NUMBER_OF_ENTITIES 5
#define JANUARY_MONTH 1
#define UNO 1
#define MONTHS_IN_YEAR 12
#define s21_epsilon 1e-7
#define MAX_SIZE_DATA_SCHEDULE 20000
#define NONTAXABLE_BASE 1000000

/// @brief
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
  int not_months;
} credit;

typedef struct datum {
  int date;
  int month;
  int year;
} datum;

typedef struct drop_add_lists {
  datum *date_add_drop;
  int frequency;
  double amount;
} drop_add_lists;

typedef struct deposit {
  datum *start_date;
  double amount;
  double term;
  double interest_rate;
  double tax_rate;
  int payout_frequency;
  int interest_capitalization;
  drop_add_lists *add_list;
  drop_add_lists *drop_list;
  double amount_add_drops;
  double accumulated_balance_interest;
  double accrued_interest;
  double tax_amount;
  double end_term_amount;
} deposit;

typedef struct schedule {
  int from_christmas_date;
  int event;
  double amount;
  int date;
  int month;
  int year;
  double day_interest;
  //   double balance;
  //   double cap_balance;
  //   double interest_balance;
} schedule;

enum types_of_first_chars {
  IS_NUMBER = 1,
  IS_ALPHA,
  IS_OPERATOR,
  IS_FUNCTION,
};

enum input_errors {
  NO_OPEN_BRACKET = -5,
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
  TYPE_POINT = 46,
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
  BEFORE_JANUARY = 0,
  BEFORE_FEBRUARY = 31,
  BEFORE_MARCH = 59,
  BEFORE_APRIL = 90,
  BEFORE_MAY = 120,
  BEFORE_JUNE = 151,
  BEFORE_JULY = 181,
  BEFORE_AUGUST = 212,
  BEFORE_SEPTEMBER = 243,
  BEFORE_OCTOBER = 273,
  BEFORE_NOVEMBER = 304,
  BEFORE_DECEMBER = 334,
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
  PER_ONCE,
  PER_DAY = 1,
  PER_WEEK = 7,
  PER_MONTH = 31,
  PER_TWO_MONTHS,
  PER_QUOTER = 3,
  PER_TWO_QUATERS = 6,
  PER_YEAR = MONTHS_IN_YEAR,
  AT_THE_END_OF_TERM,
  RESEDUE_PERIOD = -1,
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

enum capacity_quoter {
  SHORT_QUOTER_NL = 89,
  SHORT_QUOTER,
  MEDIUN_QUOTER,
  LONG_QUOTER,
};

enum actions {
  ADD_DATE = 1,
  DROP_DATE,
  END_OF_YEAR,
  END_OF_PERIOD,
};

enum events_type {
  EVENT_YEAR = 12,
  EVENT_PAYOUT,
  EVENT_ADD,
  EVENT_DROP,
};

void function_print(schedule **data_schedule, int counter, deposit *data);

/* stack_functions */
stack *s21_push(stack *next_el);
stack *s21_pop(stack *next_el);
void s21_free_stack(stack *next_el);
void s21_set_data(stack *next_el, void *data, unsigned int size);
void s21_set_priority(stack *current_el, int priority);
void s21_set_associativity(stack *current_el, char *operation);
/* stack_functions */

/* inverse_polish_notation_functions */
char *string_conversion(char *input_string, int *error);
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
                   int type_of_first_char, int element_of_vector, int operat);
int check_points_in_number(const char *B);
int multiplicity_plus_minus_check(const char *current_operator, int index_A,
                                  char *operator_l);
/* check_functions */

/* calc_functions */
double calc_polish_reverse_entry(char *pre, double x_number);
int check_entity(char *start, double *converted_number, double x_number);
stack *calc_or_stack(int entity, stack *stacked_numbers, char *leksema,
                     double converted_number);
void calc_function(stack *stacked_numbers, char *leksema);
stack *calc_operands_wtih_operators(stack *stacked_numbers, char *leksema);
/* calc_functions */

/* credit_functions */
void s21_credit_calc(credit *current_calculation);
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
void s21_deposit_calc(deposit *data);
void fill_end_of_years(deposit *data, schedule **datas_buffer, int *counter);
void fill_payment_events(deposit *data, schedule **datas_buffer, int *counter);
void fill_adds_or_drops(datum *start, double term, schedule **datas_buffer,
                        int *counter, drop_add_lists *add_or_drop_list, int event);
void plus_day_period(datum *start_date);
int conditions_check_day(datum *start_date);
void plus_week_period(datum *start_date);
int conditions_check_week(datum *start_date);
double plus_month_period(datum *start_date, int temp_date);
int conditions_check_month(datum *start_date, int temp_date);
int calculate_days_from_christmas_to_date(datum *date_of_start);
void add_data_to_schedule(schedule **datas_buffer, int *counter, int period_end,
                          int event, double amount, datum *current_date);
void flip_calendar(datum *start_date, int current_frequency, int temp_date);
void insert_sort(schedule **buffer, int count);
void calculate_deposit(schedule **data_schedule, int counter, deposit *data);
void year_calculates(schedule **data_schedule, int index, int *last_event,
                     double *day_interest, double *accumulated_period_interest,
                     deposit *data);
int is_leap_year(int number_of_year);
void add_drop_calculates(schedule **data_schedule, int index, int *last_event,
                         double day_interest, deposit *data,
                         double *accumulated_period_interest, int event_type);
void payout_calculates(schedule **data_schedule, int index, int *last_event,
                       double day_interest, deposit *data,
                       double *accumulated_period_interest);
void tax_calculate(deposit *data);
int check_frequence_add_drop(int index);
/* deposit_calc_functions */

#endif // S21_SMART_CALC_H
