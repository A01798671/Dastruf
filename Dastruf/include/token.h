#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "token_type.h"

class Token
{
private:
    const TokenType type;
    const std::string lexeme;
    const std::string literal;
    const int line;
    std::string token_type_to_string(TokenType type) const;

public:
    Token(TokenType type, const std::string &lexeme, const std::string &literal, int line);
    std::string to_string() const;
};

#endif