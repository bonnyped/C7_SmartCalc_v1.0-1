#include "s21_smart_calc.h"

stack *s21_push(stack *next_el) {
  stack *result = (stack *)malloc(sizeof(stack));
  result->data = NULL;
  result->next_element_stack = next_el;

  return result;
}

stack *s21_pop(stack *last_el) {
  stack *result = NULL;

  if (last_el) {
    if (last_el->data)
      free(last_el->data);
    result = last_el->next_element_stack;
    free(last_el);
  }

  return result;
}

void s21_free_stack(stack *next_el) {
  while (next_el) {
    next_el = s21_pop(next_el);
  }
}

void s21_set_data(stack *next_el, void *data, unsigned int size) {
  if (next_el->data)
    free(next_el->data);
  next_el->data = malloc(size);
  memcpy(next_el->data, data, size);
}

void s21_set_priority(stack *current_el, int priority) {
  current_el->previous_priority = priority;
}

void s21_set_associativity(stack *current_el, char *operation) {
  *operation == DEGREE ? current_el->associativity = TRUE
                       : (current_el->associativity);
  *operation == '~' ? current_el->associativity = -1
                    : (current_el->associativity);
}