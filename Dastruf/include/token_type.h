#ifndef TOKEN_TYPE_H
#define TOKEN_TYPE_H

enum class TokenType
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
    END,

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

#endif