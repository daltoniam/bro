#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexer/lexer.h"

int main() {
    const char *input = "let five = 5;";
    Lexer *l = newLexer(input);

Token tok = nextToken(l);
    while (strcmp(tok.type, ENDFILE) != 0 && strcmp(tok.type, ILLEGAL) != 0) {
        printf("type: %s literal: %s\n", tok.type, tok.literal);
        tok = nextToken(l);
    }

    free(l);
    return 0;
}