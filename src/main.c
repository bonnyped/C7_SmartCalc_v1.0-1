#include "s21_smart_calc.h"

int main(){
    stack* stack_operation = NULL;
    int error = 0;
    char input_string[MAX_CAPACITY] = {0};
    char output_string[MAX_CAPACITY] = {0};
    char* start = NULL;
    char* continuos = NULL;
    double number = 0.0;
    int start_to_write = 0;

    fgets(input_string, MAX_CAPACITY, stdin);

    start = strtok(input_string, " \n");
    if(start) {
        add_number_output_string(start, output_string, &start_to_write);
        stack_operation = add_stack_operation(start, output_string, stack_operation, &start_to_write);
    }
    do {
        continuos  = strtok(NULL, " \n");
        if(continuos){
            add_number_output_string(continuos, output_string, &start_to_write);
            stack_operation = add_stack_operation(continuos, output_string, stack_operation, &start_to_write);
        } else {
            if(stack_operation){
                do{
                    stack_operation = relocate_operators(stack_operation, output_string, &start_to_write);
                } while(stack_operation);
            }
        }
    } while (continuos);


    if(output_string) printf("\n here is the string \n %s \n here is the string \n ", output_string);

    while(stack_operation){
        printf("\n----\n%s\n----\n", (char*)stack_operation->data);
        stack_operation = stack_operation->next_element_stack--;
    }
    
    return 0;
}

