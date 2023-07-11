#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 2048

typedef struct leksema{
    char type;
    double data;
} leksema;

typedef struct stack{
    char* data;
    int priority;
    struct stack* next_element_stack;    
} stack;

stack* s21_push(stack* next_el);
stack* s21_pop(stack* next_el);
void s21_free_stack(stack* next_el);
void s21_set_data(stack* next_el, void* data, unsigned int size);
void s21_set_priority(stack* current_el, int priority);

void add_number_output_string(char* A, char* B, int* start_to_write);
void add_whitspace(int* start_to_write, int length, char* B);
stack* add_stack_operation(char* A, char* B, stack* stack_operation, int* start_to_write);
int check_current_priority(char* A);
stack* relocate_operators(stack* stack_operation, char* B, int* start_to_write);

#endif //S21_SMART_CALC_H