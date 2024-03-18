#include <stdlib.h>
#include "function.h"

function_t* function_allocate(){
    return(function_t *)malloc(sizeof(function_t));
}
void function_new(function_t *function){
    function->function_name = NULL;
    function->function_tokens = NULL;
    function->function_token_count = 0;
}
void function_init(function_t *function, char name[],token_t tokens[],int token_count){
    function->function_name = name;
    function->function_tokens = tokens;
    function->function_token_count = token_count;
}
char *function_name(function_t *function){
    return function->function_name;
}
token_t *function_tokens(function_t *function){
    return function->function_tokens;
}
int function_token_count(function_t *function){
    return function->function_token_count;
}