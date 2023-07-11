#include "s21_smart_calc.h"

void add_number_output_string(char* A, char* B, int* start_to_write){
    int res = 0;
    int length = 0;

    if(A) *A >= 48 && *A <= 57 ? res = 1 : res;

    if(res) {
        length = strlen(A);
        memcpy(&B[*start_to_write], A, length);
        add_whitspace(start_to_write, length, B);
    }
}

void add_whitspace(int* start_to_write, int length, char* B){
    *start_to_write = *start_to_write + length;
    B[*start_to_write] = ' ';
    *start_to_write = *start_to_write + 1;
    B[*start_to_write] = '\0';
}

stack* add_stack_operation(char* A, char* B, stack* stack_operation, int* start_to_write){
    int res = 0;
    int current_priority = 0;
    int previous_priority = 0;

    if(A) *A >= 48 && *A <= 57 ? res : (res = 1);
    if(res) {
        current_priority = check_current_priority(A);
        if(stack_operation){
        previous_priority = stack_operation->priority;
            if(current_priority > previous_priority){
                stack_operation = relocate_operators(stack_operation, B, start_to_write);
                stack_operation = s21_push(stack_operation);
                s21_set_data(stack_operation, A, sizeof(A));
            } else {
                stack_operation = s21_push(stack_operation);
                s21_set_data(stack_operation, A, sizeof(A));
            }
        } else {
            stack_operation = s21_push(stack_operation);
            s21_set_priority(stack_operation, current_priority);
            s21_set_data(stack_operation, A, sizeof(A));
        }
    }
    return stack_operation;
}

int check_current_priority(char* A){
    int res = 0;
    int length = 0;

    length = strlen(A);
    if(length == 1 && (*A == 47 || *A == 45))
        res = 1; 

    return res;
}

stack* relocate_operators(stack* stack_operation, char* B, int* start_to_write){
        while(stack_operation){
            int length = 0;
            
            length = strlen((char*)stack_operation->data);
            memcpy(&B[*start_to_write], stack_operation->data, length);
            add_whitspace(start_to_write, length, B);
            stack_operation = s21_pop(stack_operation);
        }

        return stack_operation;
}
