#ifndef LEXER_HEADER
#define LEXER_HEADER

#include "../token/token.h"

struct Lexer {
    const char* input;
    int position;
    int readPosition;
    char ch;
};
typedef struct Lexer Lexer;

Lexer* newLexer(const char* input);
Token nextToken(Lexer *l);

#endif