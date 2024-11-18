#ifndef DASTRUF_H
#define DASTRUF_H

#include <string>

namespace Dastruf
{
    void run_file(const std::string &path);
    void run_prompt();
    void error(int line, const std::string &message);
}

#endif // DASTRUF_H