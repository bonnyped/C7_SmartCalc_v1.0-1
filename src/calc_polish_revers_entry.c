#include "s21_smart_calc.h"

double calc_polish_reverse_entry(char *pre, double x_number) {
  double result = FALSE;
  int entity = FALSE;
  char *start = NULL;
  char *temp_pre = strdup((const char *)pre);
  stack *stacked_numbers = NULL;
  double converted_number = FALSE;

  do {
    !start ? start = strtok(temp_pre, " ") : (start = strtok(NULL, " "));
    if (start) {
      entity = check_entity(start, &converted_number, x_number);
      stacked_numbers =
          calc_or_stack(entity, stacked_numbers, start, converted_number);
    }
  } while (start);

  result = stacked_numbers->operand;
  while (stacked_numbers) {
    stacked_numbers = s21_pop(stacked_numbers);
  }
  if (temp_pre) free(temp_pre);

  return result;
}

int check_entity(char *start, double *converted_number, double x_number) {
  int result = IS_NUMBER;

  if (start) {
    if (isdigit(*start)) {
      *converted_number = strtod(start, NULL);
    } else if (*start == X_N) {
      *converted_number = x_number;
    } else if (isalpha(*start) && *start != MOD_F)
      result = IS_FUNCTION;
    else if (is_operator(*start) || *start == MOD_F || *start == UNARY_MINUS)
      result = IS_OPERATOR;
  }

  return result;
}

stack *calc_or_stack(int entity, stack *stacked_numbers, char *leksema,
                     double converted_number) {
  switch (entity) {
    case IS_NUMBER:
      stacked_numbers = s21_push(stacked_numbers);
      stacked_numbers->operand = converted_number;
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

void calc_function(stack *stacked_numbers, char *leksema) {
  if (stacked_numbers) {
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
}

stack *calc_operands_wtih_operators(stack *stacked_numbers, char *leksema) {
  double tranisite_variable = FALSE;
  if (stacked_numbers) {
    tranisite_variable = stacked_numbers->operand;

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
          stacked_numbers->operand =
              stacked_numbers->operand * tranisite_variable;
          break;
        case PLUS:
          stacked_numbers->operand =
              stacked_numbers->operand + tranisite_variable;
          break;
        case MINUS:
          stacked_numbers->operand =
              stacked_numbers->operand - tranisite_variable;
          break;
        case DIV:
          stacked_numbers->operand =
              stacked_numbers->operand / tranisite_variable;
          break;
        case DEGREE:
          stacked_numbers->operand =
              pow(stacked_numbers->operand, tranisite_variable);
          break;
      }
    }
  }

  return stacked_numbers;
}
