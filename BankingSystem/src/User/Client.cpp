#include "User/Client.h"

void Client::parseClientFromString(std::string s)
{
	size_t end = s.find(" ");
	size_t start = 0;

	this->idn = s.substr(start, end);

	start = end + 1;
	end = s.find(" ", start);

	this->firstName = s.substr(start, end);

	start = end + 1;
	end = s.find(" ", start);

	this->middleName = s.substr(start, end);

	start = end + 1;
	end = s.find(" ", start);

	this->lastName = s.substr(start, end);

	start = end + 1;
	end = s.find(" ", start);

	this->birthDate.SetDateFromString(s.substr(start, end));

	start = end + 1;
	end = s.find(" ", start);

	this->phoneNumber = s.substr(start, end);
	this->address = s.substr(end + 1);
}

Client::Client(std::string clientString)
{
	this->parseClientFromString(clientString);
}
