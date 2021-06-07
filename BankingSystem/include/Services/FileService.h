#pragma once
#include <fstream>
#include <string>

class FileService
{
private:
	std::fstream file;
public:
	FileService();
	FileService(std::string fileName);
	FileService(std::string fileName, std::ios_base::openmode mode);
	~FileService();
	void ChangeOpenedFile(std::string fileName);
	std::string ReadLine(unsigned int lineNumber);
	bool ReadNextLine(std::string& output);
	void WriteLine(std::string line);
};

