#include "s21_smart_calc.h"

double calc_polish_revers_entry(char *pre) {
  double result = FALSE;
  int entity = FALSE;
  char *start = NULL;
  stack *stacked_numbers = NULL;

  do {
    !start ? start = strtok(pre, " ") : (start = strtok(NULL, " "));
    entity = check_entity(start);
    stacked_numbers = calc_or_stack(entity, stacked_numbers, start);
  } while (start);

  result = stacked_numbers->operand;
  stacked_numbers = s21_pop(stacked_numbers);
  printf("\n\n\nRESULTATIK\n\n\n%lf\n\n\nRESULTATIK\n\n\n", result);

  return result;
}

int check_entity(char *start) {
  int result = FALSE;

  if (start) {
    if (isdigit(*start) || *start == X_N)
      result = IS_NUMBER;
    else if (isalpha(*start) && *start != MOD_F)
      result = IS_FUNCTION;
    else if (is_operator(*start) || *start == MOD_F)
      result = IS_OPERATOR;
  }

  return result;
}

stack *calc_or_stack(int entity, stack *stacked_numbers, char *leksema) {
  switch (entity) {
  case IS_NUMBER:
    stacked_numbers = add_number_stack(stacked_numbers, leksema);
    break;
  case IS_FUNCTION:
    calc_function(stacked_numbers, leksema);
    break;
  case IS_OPERATOR:
    stacked_numbers = calc_operands_wtih_operators(stacked_numbers, leksema);
    break;
  }

  return stacked_numbers;
}

stack *add_number_stack(stack *stacked_numbers, char *leksema) {
  double converted_number = FALSE;

  converted_number = strtod(leksema, NULL);
  stacked_numbers = s21_push(stacked_numbers);
  stacked_numbers->operand = converted_number;

  return stacked_numbers;
}

void *calc_function(stack *stacked_numbers, char *leksema) {
  switch (*leksema) {
  case COS_F:
    stacked_numbers->operand = cos(stacked_numbers->operand);
    break;
  case SIN_F:
    stacked_numbers->operand = sin(stacked_numbers->operand);
    break;
  case TAN_F:
    stacked_numbers->operand = tan(stacked_numbers->operand);
    break;
  case ACOS_F:
    stacked_numbers->operand = acos(stacked_numbers->operand);
    break;
  case ASIN_F:
    stacked_numbers->operand = asin(stacked_numbers->operand);
    break;
  case ATAN_F:
    stacked_numbers->operand = atan(stacked_numbers->operand);
    break;
  case SQRT_F:
    stacked_numbers->operand = sqrt(stacked_numbers->operand);
    break;
  case LN_F:
    stacked_numbers->operand = log(stacked_numbers->operand);
    break;
  case LOG_F:
    stacked_numbers->operand = log10(stacked_numbers->operand);
    break;
  }
}

stack *calc_operands_wtih_operators(stack *stacked_numbers, char *leksema) {
  double tranisite_variable = stacked_numbers->operand;

  if (*leksema == UNARY_MINUS) {
    stacked_numbers->operand = tranisite_variable * (-1);
  } else {
    stacked_numbers = s21_pop(stacked_numbers);
    switch (*leksema) {
    case MOD_F:
      stacked_numbers->operand =
          fmod(stacked_numbers->operand, tranisite_variable);
      break;
    case MULT:
      stacked_numbers->operand = stacked_numbers->operand * tranisite_variable;
      break;
    case PLUS:
      stacked_numbers->operand = stacked_numbers->operand + tranisite_variable;
      break;
    case MINUS:
      stacked_numbers->operand = stacked_numbers->operand - tranisite_variable;
      break;
    case DIV:
      stacked_numbers->operand = stacked_numbers->operand / tranisite_variable;
      break;
    case DEGREE:
      stacked_numbers->operand =
          pow(stacked_numbers->operand, tranisite_variable);
      break;
    }
  }

  return stacked_numbers;
}
