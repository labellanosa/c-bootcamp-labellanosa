#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "int_stack.h"

int ParseType(const char *token);
int SplitString(char *str, char *tokens[], const int maxTokens);

int main() {
    int max_tokens = 50;
    int stk_cap = 20;
    char *tokens[max_tokens];
    int_stack_t stk;
    int_stack_init(&stk, stk_cap);
    char str[256]; 
    printf("This my implementation of Forth in C. Type quit to close the program.");
    while (1) {
        fgets(str, sizeof(str), stdin);
        int tokenCount = SplitString(str, tokens, max_tokens);

        if (strcmp(str, "quit") == 0) {
            printf("Exiting the program.\n");
            break;
        } else {
            //Creating an array of token structs and passing it to the execute tokens method
            token_t token_array[tokenCount];
            for (int i = 0; i < tokenCount; i++) {
                token_t *t = token_allocate();
                token_new(t);
                token_init(t, tokens[i], ParseType(tokens[i]));
                token_array[i] = t;
            }
            executeTokens(token_array,token_count,stk);
        }
    }
    return 0;
}

int executeTokens(token_t tokens[],int token_count,int_stack_t stk){
    for (int i=0;i<token_count;i++){
        token_t *t = tokens[i];
                //If token is of type NUMBER, convert to int and push to the stack.
                if (token_type(t)==NUMBER) {
                    char **endptr;
                    long int tokenInt = strtol(token_text(t), endptr, 10);
                    int_stack_push(&stk,(int)tokenInt);
                    //token_free(t);
                }

                //If token is of type OPERATOR, call the specific stack operation.
                if (token_type(t) == OPERATOR) {
                    switch (*token_text(t)) {
                        case '+':
                            int_stack_add(&stk);
                            break;
                        case '-':
                            int_stack_sub(&stk);
                            break;
                        case '*':
                            int_stack_mul(&stk);
                            break;
                        case '/':
                            int_stack_div(&stk);
                            break;
                        default:
                            printf("WARNING: Unidentified Operator\n");
                            break;
                    }
                    //token_free(t);
                }
                //If word is of type symbol, just check for conditionals for now
                if(token_type(t)==SYMBOL){
                    if(strcmp(token_text(t), "=") == 0){
                        int_stack_equals(&stk);
                    }
                    if(strcmp(token_text(t), "<") == 0){
                        int_stack_less(&stk);
                    }
                    if(strcmp(token_text(t), ">") == 0){
                        int_stack_greater(&stk);
                    }
                    if(strcmp(token_text(t), ".") == 0){
                        int *a;
                        printf(int_stack_pop(&stk,a)+"\n");
                    }
                    if(strcmp(token_text(t), ".\"") == 0){//Special output case
                    
                    }
                    //token_free(t);
                }
                //If token is of WORD type, just check for all stack operations for now (variable support coming)
                if(token_type(t)==WORD){
                    if(strcmp(token_text(t), "swap") == 0){
                        int_stack_swap(&stk);
                    }
                    if(strcmp(token_text(t), "dup") == 0){
                        int_stack_dup(&stk);
                    }
                    if(strcmp(token_text(t), "rot") == 0){
                        int_stack_rot(&stk);
                    }
                    if(strcmp(token_text(t), "drop") == 0){
                        int_stack_drop(&stk);
                    }
                    if(strcmp(token_text(t), "over") == 0){
                        int_stack_over(&stk);
                    }
                    if(strcmp(token_text(t), "2swap") == 0){
                        int_stack_2swap(&stk);
                    }
                    if(strcmp(token_text(t), "2drop") == 0){
                        int_stack_2drop(&stk);
                    }
                    if(strcmp(token_text(t), "2over") == 0){
                        int_stack_2over(&stk);
                    }
                    if(strcmp(token_text(t), "2dup") == 0){
                        int_stack_2dup(&stk);
                    }
                    //token_free(t);
                }
                int_stack_print(&stk,stdout);
            }
            return 0;
}
            

//Method to determine token type
int ParseType(const char *token) {
    if (*token == '+' || *token == '-' || *token == '*' || *token == '/') {
        return OPERATOR;
    } else if (isalpha(*token)) {
        return WORD;
    } else if (isdigit(*token)) {
        return NUMBER;
    } else {
        return SYMBOL;
    }
}

//Method to break user input into separate tokens.
int SplitString(char *str, char *tokens[], const int maxTokens) {
    int i = 0;
    for (i = 0; i < maxTokens; i++) {
        char *token = strtok(i == 0 ? str : NULL, " \t\n");
        tokens[i] = token;
        if (token == NULL) {
            break;
        }
    }
    return i;
}