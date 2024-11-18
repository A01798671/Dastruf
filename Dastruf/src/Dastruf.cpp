#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Dastruf.h"
#include "token_type.h"
#include "token.h"
#include "lexer.h"

namespace dastruf
{
    //-----------------------------------------Private-----------------------------------------------------
    void run(const std::string &source)
    {
        Lexer lexer(source);
        std::vector<Token> tokens = lexer.scan_tokens();
        for (Token token : tokens)
        {
            std::cout << token.to_string() << std::endl;
        }
    }
    bool had_error = false;
    //-----------------------------------------Public-----------------------------------------------------
    void run_file(const std::string &path)
    {
        std::ifstream file(path, std::ios::in | std::ios::binary);
        if (!file)
        {
            std::cerr << "Error: Could not open file " << path << std::endl;
            exit(65);
        }
        std::ostringstream buffer;
        buffer << file.rdbuf();
        std::string content = buffer.str();
        file.close();
        run(content);
        if (had_error)
            exit(65);
    }
    void run_prompt()
    {
        std::cout << "Dastruf v0.0.1\n";
        // Hola
        std::string line;
        while (true)
        {
            std::cout << ">";
            if (!std::getline(std::cin, line))
            {
                break;
            }
            run(line);
            had_error = false;
        }
    }
    void error(int line, const std::string &message)
    {
        had_error = true;
        std::cerr << "[line " << line << "] Error" << ": " << message << "\n";
    }
}