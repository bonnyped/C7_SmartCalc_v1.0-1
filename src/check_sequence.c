#include "s21_smart_calc.h"

int check_sequence(int *current_entity, int *previous_sequence_element,
                   int type_of_first_char, int element_of_vector,
                   int operator) {
  int error = FALSE;
  int entity_is_X = 0;
  int entity_is_operation_MOD = 1;

  if (type_of_first_char == IS_NUMBER)
    *current_entity = NUMBER;

  else if (type_of_first_char == IS_ALPHA) {
    if (element_of_vector == entity_is_X)
      *current_entity = NUMBER;
    else if (element_of_vector == entity_is_operation_MOD)
      *current_entity = BINURY_OPERATOR;
    else
      *current_entity = FUNCTION;
  }

  else if (type_of_first_char == IS_OPERATOR) {
    if (operator== OPEN_BRACKET)
      *current_entity = OPEN_BRACKETS;
    else if (operator== CLOSE_BRACKET)
      *current_entity = CLOSE_BRACKETS;
    else
      *current_entity = BINURY_OPERATOR;
  }

  previous_sequence_element[*current_entity] == FALSE
      ? error = ERROR_OF_SEQUENCE
      : error;

  return error;
}
