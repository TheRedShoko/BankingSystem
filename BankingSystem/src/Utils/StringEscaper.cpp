#include "Utils/StringEscaper.h"

std::string StringEscaper::EscapeSpaces(std::string toEscape)
{
	for (size_t i = 0; i < toEscape.length(); i++)
	{
		if (toEscape[i] == ' ')
		{
			toEscape[i] = StringEscaper::escapeSymbol;
		}
	}

	return toEscape;
}

std::string StringEscaper::RevertEscapedSpaces(std::string toEscape)
{
	for (size_t i = 0; i < toEscape.length(); i++)
	{
		if (toEscape[i] == StringEscaper::escapeSymbol)
		{
			toEscape[i] = ' ';
		}
	}

	return toEscape;
}
