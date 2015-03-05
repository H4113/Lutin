#ifndef UTILS_H
#define UTILS_H

// ----------------------------------------------------------------------------
// Utils - useful functions
// ----------------------------------------------------------------------------

#include <string>
#include <sstream>

template<typename T>
std::string ttos( T t )
{
   std::ostringstream ss;
   std::string s;
   ss << t;
   return ss.str();
}

template <typename T>
T stot( std::string s )
{
    std::istringstream ss( s );
    T t;
    ss >> t;
    return t;
}

#endif // UTILS_H
