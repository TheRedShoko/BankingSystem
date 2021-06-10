#include "Services/IOService.h"

void IOService::Write(std::string outputString)
{
	IOService::output << outputString;
}

void IOService::WriteLine(std::string outputString)
{
	IOService::output << outputString << std::endl;
}

void IOService::ReadString(std::string& inputVar)
{
	IOService::input >> inputVar;
	IOService::input.ignore();
}

void IOService::ReadLine(std::string& inputVar)
{
	std::getline(IOService::input, inputVar);
}

void IOService::ReadString(std::string message, std::string& inputVar)
{
	IOService::Write(message + " ");
	IOService::ReadString(inputVar);
}

void IOService::ReadLine(std::string message, std::string& inputVar)
{
	IOService::Write(message + " ");
	IOService::ReadLine(inputVar);
}

void IOService::ReadDouble(double& var)
{
	IOService::input >> var;
	IOService::input.ignore();
}

void IOService::ReadDouble(std::string message, double& var)
{
	IOService::Write(message + " ");
	IOService::ReadDouble(var);
}
