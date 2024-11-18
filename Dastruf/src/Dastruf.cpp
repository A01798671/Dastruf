using namespace std;

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "lexer.cpp"

class Dastruf
{
public:
    static void execute(int argc, char *argv[])
    {
        if (argc > 2)
        {
            std::cout << "Usage: dastruf [script]" << std::endl;
            exit(64);
        }
        else if (argc == 2)
        {
            runFile(argv[1]);
        }
        else
        {
            runPrompt();
        }
    }

    static void error(int line, const std::string &message)
    {
        report(line, "", message);
    }

    static bool hadError;

private:
    static void runPrompt()
    {
        std::cout << "Dastruf v0.0.1" << std::endl;
        std::string line;

        while (true)
        {
            std::cout << ">";
            if (!std::getline(std::cin, line))
            {

                break;
            }

            run(line);
            hadError = false;
        }
    }
    static void runFile(const std::string &path)
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

        run(content);
        file.close();
        if (hadError)
            exit(65);
    }
    static void run(const std::string &source)
    {
        std::cout << "Running Dastruf code:\n"
                  << source << std::endl;
        Lexer lexer(source);
        vector<Token> tokens = lexer.scanTokens();
        for (Token token : tokens)
        {
            std::cout << token.toString() << std::endl;
        }
    }
    static void report(int line, const std::string &where, const std::string &message)
    {
        std::cerr << "[line " << line << "] Error" << where << ": " << message << std::endl;
        hadError = true;
    }
};
bool Dastruf::hadError = false;

int main(int argc, char *argv[])
{
    // Dastruf::error(3, "EROORSASO");
    Dastruf::execute(argc, argv);
    return 0;
}
