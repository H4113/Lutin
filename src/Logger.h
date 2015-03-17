#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>

// taken and slightly arranged from
// http://stackoverflow.com/questions/4366904/custom-stream-to-method-in-c

class Logger : public std::ostream {
private:
    class CLogBuf : public std::stringbuf {
    private:
        // or whatever you need for your application
        //std::string m_marker;
    public:
        CLogBuf(void) { }
        ~CLogBuf() {  pubsync(); }
        #ifdef DEBUG
            int sync() { std::cout << "debug" << ": " << str(); str("");  return !std::cout; }
        #else
            int sync() { return !std::cout; }
        #endif
    };

public:
    // Other constructors could specify filename, etc
    // just remember to pass whatever you need to CLogBuf
    Logger() : std::ostream(new CLogBuf()) {}
    ~Logger() { delete rdbuf(); }

   //std::ostream& write (const char* s, std::streamsize n){return *this;}

};

#endif