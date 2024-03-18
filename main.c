#include "token.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

token_type_t classify_token(const char* text);

int main() {
    char line[MAX_LINE_LENGTH];

    printf("Enter FORTH code (CTRL+D to stop):\n");
    while (fgets(line, MAX_LINE_LENGTH, stdin)) {
        char* token_text = strtok(line, " \n");
        while (token_text != NULL) {
            token_type_t type = classify_token(token_text);
            token_t* token = create_token(type, token_text);
            printf("Token: %s, Type: %d\n", token->text, token->type);

            free_token(token);
            token_text = strtok(NULL, " \n");
        }
    }

    return 0;
}

token_type_t classify_token(const char* text) {
    if (isdigit(text[0])) {
        return NUMBER;
    } else if (strchr("+-*/", text[0]) != NULL) {
        return OPERATOR;
    } else if (strchr(":;", text[0]) != NULL) {
        return SYMBOL;
    } else {
        return WORD;
    }
}