using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Token.cpp"

class Lexer
{
public:
    Lexer(const std::string &source) : source(source) {}

    std::vector<Token> scanTokens()
    {
        while (!isAtEnd())
        {
            start = current;
            scanToken();
        }

        tokens.emplace_back(TokenType::EOF_TOKEN, "", "", line);
        return tokens;
    }

private:
    std::string source;
    std::vector<Token> tokens;
    int start = 0;
    int current = 0;
    int line = 1;

    bool isAtEnd() const
    {
        return current >= source.length();
    }

    void scanToken()
    {
        char c = advance();
        switch (c)
        {
        case '(':
            addToken(TokenType::LEFT_PAREN);
            break;
        case ')':
            addToken(TokenType::RIGHT_PAREN);
            break;
        case '[':
            addToken(TokenType::LEFT_BRACKET);
            break;
        case ']':
            addToken(TokenType::RIGHT_BRACKET);
            break;
        case ',':
            addToken(TokenType::COMMA);
            break;
        case '.':
            addToken(TokenType::DOT);
            break;
        case '-':
            addToken(TokenType::MINUS);
            break;
        case '+':
            addToken(TokenType::PLUS);
            break;
        case ':':
            addToken(TokenType::COLON);
            break;
        case '/':
            if (match('/'))
            {
                while (peek() != '\n' && !isAtEnd())
                {
                    advance();
                }
            }
            else
            {
                addToken(TokenType::SLASH);
            }
            break;
        case '*':
            if (match('*'))
                addToken(TokenType::STAR_STAR);
            else
                addToken(TokenType::STAR);
            break;
        case '%':
            addToken(TokenType::PERCENT);
            break;
        case '!':
            if (match('='))
                addToken(TokenType::NOT);
            else
                addToken(TokenType::NOT_EQUAL);
            break;
        case '=':
            if (match('='))
                addToken(TokenType::EQUAL_EQUAL);
            else
                addToken(TokenType::EQUAL);
            break;
        case '<':
            if (match('='))
                addToken(TokenType::LESS_EQUAL);
            else
                addToken(TokenType::LESS);
            break;
        case '>':
            if (match('='))
                addToken(TokenType::GREATER_EQUAL);
            else
                addToken(TokenType::GREATER);
            break;
        case ' ':
        case '\r':
            break;
        case '\t':
            addToken(TokenType::TAB);
            break;
        case '\n':
            line++;
            break;
        default:
            std::cerr << "Unexpected character: " << c << " at line " << line << std::endl;
            break;
        }
    }

    char advance()
    {
        return source[current++];
    }

    void addToken(TokenType type)
    {
        addToken(type, "");
    }

    void addToken(TokenType type, const std::string &literal)
    {
        std::string text = source.substr(start, current - start);
        tokens.emplace_back(type, text, literal, line);
    }

    bool match(char expected)
    {
        if (isAtEnd())
            return false;
        if (source[current] != expected)
            return false;
        current++;
        return true;
    }

    char peek()
    {
        if (isAtEnd())
            return '\0';
        return source[current];
    }
};