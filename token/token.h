#ifndef TOKEN_HEADER
#define TOKEN_HEADER


#define ILLEGAL "ILLEGAL"
#define ENDFILE "EOF"

// Identifiers + literals
#define IDENT "IDENT"
#define INT "INT"

// Operators
#define ASSIGN "="
#define PLUS "+"
#define MINUS "-"
#define BANG "!"
#define ASTERISK "*"
#define SLASH "/"
#define LT "<"
#define GT ">"
#define EQ "=="
#define NOT_EQ "!="

// Delimiters
#define COMMA ","
#define SEMICOLON ";"
#define LPAREN "("
#define RPAREN ")"
#define LBRACE "{"
#define RBRACE "}"

// Keywords
#define FUNCTION = "fn"
#define LET "let"
#define TRUE "true"
#define FALSE "false"
#define IF "if"
#define ELSE "else"
#define RETURN "return"

struct Token {
    const char* type;
    const char* literal;
};
typedef struct Token Token;

#endif