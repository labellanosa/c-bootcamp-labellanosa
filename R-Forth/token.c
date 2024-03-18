#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

token_t *token_allocate() {
    return (token_t *)malloc(sizeof(token_t));
}

void token_new(token_t *token) {
    token->token_text_t = NULL;
    token->token_type_t = 0;
}

void token_init(token_t *token, char *text, enum Type type) {
    token->token_text_t = strdup(text);

    if (token->token_text_t == NULL) {
        perror("String duplication failed");
        exit(EXIT_FAILURE);
    }

    token->token_type_t = type;
}

char* token_text(token_t *token) {
    return token->token_text_t;
}

enum Type token_type(token_t *token) {
    return token->token_type_t;
}

void token_print_text(token_t *token) {
    printf("%s", token->token_text_t);
}

void token_print_type(token_t *token) {
    switch (token->token_type_t) {
        case NUMBER:
            printf("Number");
            break;
        case OPERATOR:
            printf("Operator");
            break;
        case SYMBOL:
            printf("Symbol");
            break;
        case WORD:
            printf("Word");
            break;
        default:
            printf("NULL");
            break;
    }
}

void token_free(token_t *token){
    free(token->token_text_t);
    free(token);
}