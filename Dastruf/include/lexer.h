#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "token.h"

class Lexer
{
public:
    Lexer(const std::string &source);
    std::vector<Token> scan_tokens();

private:
    std::string source;
    std::vector<Token> tokens;
    int start;
    int current;
    int line;
    bool is_at_end() const;
    void scan_token();
    char advance();
    void add_token(TokenType type);
    void add_token(TokenType type, const std::string &literal);
    bool match(char expected);
    char peek();
};

#endif