#include <string.h>
#include <stdlib.h>
#include "lexer.h"

int isLetter(char ch) {
    return ('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ch == '_';
}

int isDigit(char ch) {
    return '0' <= ch && ch <= '9';
}

void readChar(Lexer *l) {
    if (l->readPosition >= strlen(l->input)) {
        l->ch = 0;
    } else {
        l->ch = l->input[l->readPosition];
    }
    l->position = l->readPosition;
    l->readPosition += 1;
}

char peekChar(Lexer *l) {
    if (l->readPosition >= strlen(l->input)) {
        return 0;
    } else {
        return l->input[l->readPosition];
    }
}

void skipWhitespace(Lexer *l) {
    while (l->ch == ' ' || l->ch == '\t' || l->ch == '\n' || l->ch == '\r') {
        readChar(l);
    }
}

char* readIdentifier(Lexer *l) {
    int position = l->position;
    while (isLetter(l->ch)) {
        readChar(l);
    }
    return strndup(l->input + position, l->position - position);
}

char* readNumber(Lexer *l) {
    int position = l->position;
    while (isDigit(l->ch)) {
        readChar(l);
    }
    return strndup(l->input + position, l->position - position);
}

// public calls

Lexer* newLexer(const char* input) {
    Lexer *l = (struct Lexer*)malloc(sizeof(Lexer));
    l->input = input;
    l->position = 0;
    l->readPosition = 0;
    l->ch = 0;
    readChar(l);
    return l;
}

Token nextToken(Lexer *l) {
    Token tok;

    skipWhitespace(l);
    switch (l->ch) {
        case '=':
            if (peekChar(l) == '=') {
                readChar(l); // move forward
                tok.type = EQ;
                tok.literal = "==";
            } else {
                tok.type = ASSIGN;
                tok.literal = "=";
            }
            tok.type = ASSIGN;
            tok.literal = "=";
            break;
        case '+':
            tok.type = PLUS;
            tok.literal = "+";
            break;
        case '-':
            tok.type = MINUS;
            tok.literal = "-";
            break;
        case '!':
            if (peekChar(l) == '=') {
                readChar(l); // move forward
                tok.type = NOT_EQ;
                tok.literal = "!=";
            } else {
                tok.type = BANG;
                tok.literal = "!";
            }
            break;
        case '/':
            tok.type = SLASH;
            tok.literal = "/";
            break;
        case '*':
            tok.type = ASTERISK;
            tok.literal = "*";
            break;
        case '<':
            tok.type = LT;
            tok.literal = "<";
            break;
        case '>':
            tok.type = GT;
            tok.literal = ">";
            break;
        case ',':
            tok.type = COMMA;
            tok.literal = ",";
            break;
        case ';':
            tok.type = SEMICOLON;
            tok.literal = ";";
            break;
        case '(':
            tok.type = LPAREN;
            tok.literal = "(";
            break;
        case ')':
            tok.type = RPAREN;
            tok.literal = ")";
            break;
        case '{':
            tok.type = LBRACE;
            tok.literal = "{";
            break;
        case '}':
            tok.type = RBRACE;
            tok.literal = "}";
            break;
        case 0:
            tok.type = ENDFILE;
            tok.literal = "";
            break;
        default:
            if (isLetter(l->ch)) {
                tok.literal = readIdentifier(l);
                tok.type = tok.literal;
                return tok;
            } else if (isDigit(l->ch)) {
                tok.type = INT;
                tok.literal = readNumber(l);
                return tok;
            }
            tok.type = ILLEGAL;
            tok.literal = "";
    }
    readChar(l);
    return tok;
}