#ifndef TOKEN_T_H
#define TOKEN_T_H

#include <stdio.h>
#include <stdlib.h>

enum Type {
    NUMBER = 1,
    OPERATOR,
    SYMBOL,
    WORD
};

typedef struct {
    enum Type token_type_t;
    char *token_text_t;
} token_t;

extern token_t *token_allocate();

extern void token_new(token_t *token);

extern void token_init(token_t *token, char *text, enum Type type);

extern char *token_text(token_t *token);

extern enum Type token_type(token_t *token);

extern void token_print_text(token_t *token);

extern void token_print_type(token_t *token);

extern void token_free(token_t *token);

#endif