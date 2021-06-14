#pragma once
#include <iostream>
#include <string>
class IOService
{
private:
	inline static std::istream& input = std::cin;
	inline static std::ostream& output = std::cout;

public:
	static void Write(const std::string& output);
	static void WriteLine(const std::string& output);

	static void ReadString(std::string& inputVar);
	static void ReadLine(std::string& inputVar);
	static void ReadString(const std::string& message, std::string& inputVar);
	static void ReadLine(const std::string& message, std::string& inputVar);

	static void ReadDouble(double& var);
	static void ReadDouble(const std::string& message, double& var);
};