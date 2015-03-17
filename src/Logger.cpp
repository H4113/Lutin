#include "Logger.h"

Logger::Logger(const std::string& prefix, bool print)
	: std::ostream(new LogBuf(prefix, print))
{
}

Logger::~Logger()
{ 
	delete rdbuf();
}

Logger::LogBuf::LogBuf(const std::string& fprefix, bool fprint)
	: prefix(fprefix),print(fprint)
{
}

Logger::LogBuf::~LogBuf()
{ 
	pubsync();
}

int Logger::LogBuf::sync()
{
	if(print)
	{
        std::cout << prefix << ": " << str();
        str("");
    }

    return !std::cout;
}
        