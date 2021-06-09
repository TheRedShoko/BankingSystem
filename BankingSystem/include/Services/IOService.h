#pragma once
#include <iostream>
#include <string>
class IOService
{
private:
	inline static std::istream& input = std::cin;
	inline static std::ostream& output = std::cout;

public:
	static void Write(std::string output);
	static void WriteLine(std::string output);

	static void ReadString(std::string& inputVar);
	static void ReadLine(std::string& inputVar);
	static void ReadString(std::string message, std::string& inputVar);
	static void ReadLine(std::string message, std::string& inputVar);

	static void ReadDouble(double& var);
	static void ReadDouble(std::string message, double& var);
};