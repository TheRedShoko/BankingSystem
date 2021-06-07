#pragma once
#include <string>

class StringEscaper
{
private:
	static const char escapeSymbol = '$';
public:
	static std::string EscapeSpaces(std::string toEscape);
	static std::string RevertEscapedSpaces(std::string toEscape);
};