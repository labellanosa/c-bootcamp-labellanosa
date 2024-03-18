#include "token.h"

typedef struct {
    char function_name[];
    token_t function_tokens[];
    int function_token_count;
} function_t;

extern function_t* function_allocate();
extern void function_new(function_t *function);
extern void function_init(function_t *function, char name[] ,token_t tokens[],int token_count);
extern char* function_name(function_t *function);
extern token_t* function_tokens(function_t *function);
extern int function_token_count(function_t *function);