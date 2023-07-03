#include "s21_smart_calc.h"

stack* add_stack_number(char* A, stack* stack_number){
    int res = 0;

    if(A) *A >= 48 && *A <= 57 ? res = 1 : res;

    if(res) {
        double number = 0.0;
        char** end = NULL;
        number = strtod(A, end);
        stack_number = s21_push(stack_number);
        s21_set_data(stack_number, &number, sizeof(double));
    }

    return stack_number;
}

stack* add_stack_operation(char* A, stack* stack_operation){
    int res = 0;

    if(A) *A >= 48 && *A <= 57 ? res : (res = 1);
    
    if(res) {
        stack_operation = s21_push(stack_operation);
        s21_set_data(stack_operation, A, sizeof(A));
    }

    return stack_operation;
}
