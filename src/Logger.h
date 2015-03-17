#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>

// inspired by
// http://stackoverflow.com/questions/4366904/custom-stream-to-method-in-c

class Logger : public std::ostream {
private:
    class LogBuf : public std::stringbuf {

    public:
        bool print;
        std::string prefix;

        LogBuf(const std::string& prefix, bool print);
        ~LogBuf();

        int sync();
    };

public:
    Logger(const std::string& prefix, bool print = true);
    ~Logger();
};

#endif