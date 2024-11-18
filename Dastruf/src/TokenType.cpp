using namespace std;

#include <iostream>

enum TokenType
{
    // Single-character tokens
    LEFT_PAREN,
    RIGHT_PAREN,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    COMMA,
    DOT,
    MINUS,
    PLUS,
    COLON,
    SLASH,
    STAR,
    STAR_STAR,
    PERCENT,

    // One or two character tokens
    NOT,
    NOT_EQUAL,
    EQUAL,
    EQUAL_EQUAL,
    GREATER,
    GREATER_EQUAL,
    LESS,
    LESS_EQUAL,
    TAB,

    // Literals
    IDENTIFIER,
    STRING_LITERAL,
    NUMBER,

    // Keywords
    INT,
    FLOAT,
    STRING,
    BOOL,
    LIST,
    CHAR,
    TRUE,
    FALSE,
    NULL_TOKEN,
    AND,
    OR,
    IF,
    ELIF,
    ELSE,
    WHILE,
    P,
    THIS,
    EOF_TOKEN,
    ARR,
    RETURN,
    BREAK,
    CONTINUE,
    IMPORT
};
