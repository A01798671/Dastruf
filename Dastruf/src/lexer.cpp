#include "lexer.h"

Lexer::Lexer(const std::string &source) : source(source), start(0), current(0), line(1) {}

std::vector<Token> Lexer::scan_tokens()
{
    while (!is_at_end())
    {
        start = current;
        scan_token();
    }

    tokens.emplace_back(TokenType::EOF_TOKEN, "", "", line);
    return tokens;
}

bool Lexer::is_at_end() const
{
    return current >= source.length();
}

char Lexer::peek()
{
    if (is_at_end())
        return '\0';
    return source[current];
}

bool Lexer::match(char expected)
{
    if (is_at_end())
        return false;
    if (source[current] != expected)
        return false;
    current++;
    return true;
}

char Lexer::advance()
{
    return source[current++];
}

void Lexer::add_token(TokenType type)
{
    add_token(type, "");
}

void Lexer::add_token(TokenType type, const std::string &literal)
{
    std::string text = source.substr(start, current - start);
    tokens.emplace_back(type, text, literal, line);
}

void Lexer::scan_token()
{
    char c = advance();
    switch (c)
    {
    case '(':
        add_token(TokenType::LEFT_PAREN);
        break;
    case ')':
        add_token(TokenType::RIGHT_PAREN);
        break;
    case '[':
        add_token(TokenType::LEFT_BRACKET);
        break;
    case ']':
        add_token(TokenType::RIGHT_BRACKET);
        break;
    case ',':
        add_token(TokenType::COMMA);
        break;
    case '.':
        add_token(TokenType::DOT);
        break;
    case '-':
        add_token(TokenType::MINUS);
        break;
    case '+':
        add_token(TokenType::PLUS);
        break;
    case ':':
        add_token(TokenType::COLON);
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && !is_at_end())
            {
                advance();
            }
        }
        else
        {
            add_token(TokenType::SLASH);
        }
        break;
    case '*':
        if (match('*'))
            add_token(TokenType::STAR_STAR);
        else
            add_token(TokenType::STAR);
        break;
    case '%':
        add_token(TokenType::PERCENT);
        break;
    case '!':
        if (match('='))
            add_token(TokenType::NOT_EQUAL);
        else
            add_token(TokenType::NOT);
        break;
    case '=':
        if (match('='))
            add_token(TokenType::EQUAL_EQUAL);
        else
            add_token(TokenType::EQUAL);
        break;
    case '<':
        if (match('='))
            add_token(TokenType::LESS_EQUAL);
        else
            add_token(TokenType::LESS);
        break;
    case '>':
        if (match('='))
            add_token(TokenType::GREATER_EQUAL);
        else
            add_token(TokenType::GREATER);
        break;
    case ' ':
        break;
    case '\t':
        break;
    case '\n':
        line++;
        break;
    case '\r':
        break;
    default:
        std::cerr << "Unexpected character: " << c << " at line " << line << std::endl;
        break;
    }
}