#include "User/Person.h"

std::string Person::ToString()
{
	return this->idn + " " + this->firstName + " " + this->middleName + " " + this->lastName + " " + this->birthDate.ToString() + this->phoneNumber + this->address;
}
