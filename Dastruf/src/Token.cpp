using namespace std;

#include <iostream>
#include <sstream>
#include "TokenType.cpp"

// Clase Token
class Token
{
public:
    Token(TokenType type, const std::string &lexeme, const std::string &literal, int line)
        : type(type), lexeme(lexeme), literal(literal), line(line) {}

    std::string toString() const
    {
        std::ostringstream oss;
        oss << tokenTypeToString(type) << " " << lexeme << " " << literal;
        return oss.str();
    }

    TokenType getType() const { return type; }
    std::string getLexeme() const { return lexeme; }
    std::string getLiteral() const { return literal; }
    int getLine() const { return line; }

private:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;

    std::string tokenTypeToString(TokenType type) const
    {
        switch (type)
        {
        // Single-character tokens
        case LEFT_PAREN:
            return "LEFT_PAREN";
        case RIGHT_PAREN:
            return "RIGHT_PAREN";
        case LEFT_BRACKET:
            return "LEFT_BRACKET";
        case RIGHT_BRACKET:
            return "RIGHT_BRACKET";
        case COMMA:
            return "COMMA";
        case DOT:
            return "DOT";
        case MINUS:
            return "MINUS";
        case PLUS:
            return "PLUS";
        case COLON:
            return "COLON";
        case SLASH:
            return "SLASH";
        case STAR:
            return "STAR";
        case STAR_STAR:
            return "STAR_STAR";
        case PERCENT:
            return "PERCENT";

        // One or two character tokens
        case NOT:
            return "NOT";
        case NOT_EQUAL:
            return "NOT_EQUAL";
        case EQUAL:
            return "EQUAL";
        case EQUAL_EQUAL:
            return "EQUAL_EQUAL";
        case GREATER:
            return "GREATER";
        case GREATER_EQUAL:
            return "GREATER_EQUAL";
        case LESS:
            return "LESS";
        case LESS_EQUAL:
            return "LESS_EQUAL";
        case TAB:
            return "TAB";
        // Literals
        case IDENTIFIER:
            return "IDENTIFIER";
        case STRING_LITERAL:
            return "STRING_LITERAL";
        case NUMBER:
            return "NUMBER";

        // Keywords
        case INT:
            return "INT";
        case FLOAT:
            return "FLOAT";
        case STRING:
            return "STRING";
        case BOOL:
            return "BOOL";
        case LIST:
            return "LIST";
        case CHAR:
            return "CHAR";
        case TRUE:
            return "TRUE";
        case FALSE:
            return "FALSE";
        case NULL_TOKEN:
            return "NULL";
        case AND:
            return "AND";
        case OR:
            return "OR";
        case IF:
            return "IF";
        case ELIF:
            return "ELIF";
        case ELSE:
            return "ELSE";
        case WHILE:
            return "WHILE";
        case P:
            return "P";
        case THIS:
            return "THIS";
        case EOF_TOKEN:
            return "EOF";
        case ARR:
            return "ARR";
        case RETURN:
            return "RETURN";
        case BREAK:
            return "BREAK";
        case CONTINUE:
            return "CONTINUE";
        case IMPORT:
            return "IMPORT";

        default:
            return "UNKNOWN";
        }
    }
};
