#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <string.h>

typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    UNKNOWN
} token_type_t;

typedef struct {
    token_type_t type;
    char* text;
} token_t;

token_t* create_token(token_type_t type, const char* text);
void free_token(token_t* token);

#endif