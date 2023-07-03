#include "s21_smart_calc.h"

int main(){
    stack* stack_number = NULL;
    stack* stack_operation = NULL;
    int error = 0;
    char calc_string[128] = {0};
    char* start = NULL;
    char* continuos = NULL;
    double number = 0.0;

    fgets(calc_string, 128, stdin);
    start = strtok(calc_string, " \n");
    if(start) {
        stack_number = add_stack_number(start, stack_number);
        stack_operation = add_stack_operation(start, stack_operation);
    }
    do {
        continuos = strtok(NULL, " \n");
        if(continuos){
            stack_number = add_stack_number(continuos, stack_number);
            stack_operation = add_stack_operation(continuos, stack_operation);
        }
    } while (continuos);


    while(stack_number){
        printf("\n----\n%f\n----\n", *(double*)stack_number->data);
        stack_number = stack_number->next_elemennt_stack--;
    }

    while(stack_operation){
        printf("\n----\n%s\n----\n", (char*)stack_operation->data);
        stack_operation = stack_operation->next_elemennt_stack--;
    }
    
    
    // if(start[0] > '0' && start[0] < '9'){
    //     number = strtod(start, &continuos);
    //     start = continuos;
    //     stack_number = s21_push(stack_number);
    //     s21_set_data(stack_number, &number, sizeof(number));
    // } else {
    //     !stack_operation ? continuos = strtok(start, " ") : (continuos = strtok(NULL, " \n"));
    //     stack_operation = s21_push(stack_operation);
    //     start = continuos;
    //     if(start){
    //     s21_set_data(stack_operation, &start, strlen(start));
    //     }
    // }
    // } while (*continuos != '\n' || !start);

    // if(stack_number){
    // printf("@@@@@@@\n%f\n@@@@@@@@@@\n", *(double*)stack_number->data);
    // printf("@@@@@@@\n%s\n@@@@@@@@@@\n", start);
    
    
    // if(calc_string) printf("\n%s\n", calc_string);
    
    return 0;
}

