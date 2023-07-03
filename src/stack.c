#include "s21_smart_calc.h"

stack* s21_push(stack* next_el){
    stack* result = (stack*)malloc(sizeof(stack));
    result->data = NULL;
    result->next_elemennt_stack = next_el;

    return result;
}

stack* s21_pop(stack* next_el){
    stack* result = NULL;
     
    if(next_el){
        if(next_el->data) free(next_el->data);
        result = next_el->next_elemennt_stack;
        free(next_el);
    }

    return result;
}

void s21_free_stack(stack* next_el){
    while(next_el){
        next_el = s21_pop(next_el);
    }
}

void s21_set_data(stack* next_el, void* data, unsigned int size){
    if(next_el->data) free(next_el->data);
    next_el->data = malloc(size);
    memcpy(next_el->data, data, size);
}

