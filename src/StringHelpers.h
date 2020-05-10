#ifndef STRING_HELPERS_H
#define STRING_HELPERS_H

#include <string>
#include <sstream>
// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string toString(const T& value)
{
	std::stringstream stream;
	stream << value;
	return stream.str();
}

#endif