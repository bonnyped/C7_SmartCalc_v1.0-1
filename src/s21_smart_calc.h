#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct leksema{
    char type;
    double data;
} leksema;

typedef struct stack{
    void* data;
    struct stack* next_elemennt_stack;    
} stack;

stack* s21_push(stack* next_el);
stack* s21_pop(stack* next_el);
void s21_free_stack(stack* next_el);
void s21_set_data(stack* next_el, void* data, unsigned int size);

stack* add_stack_number(char* A, stack* stack_number);
stack* add_stack_operation(char* A, stack* stack_operation);

#endif //S21_SMART_CALC_H