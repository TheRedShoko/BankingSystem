#pragma once
#include <fstream>
#include <string>

class FileService
{
private:
	std::fstream file;
public:
	FileService();
	FileService(const std::string& fileName);
	FileService(const std::string& fileName, std::ios_base::openmode mode);
	~FileService();
	static void CreateFolder(const std::string& folder);
	void ChangeOpenedFile(const std::string& fileName);
	std::string ReadLine(unsigned int lineNumber);
	bool ReadNextLine(std::string& output);
	void WriteLine(const std::string& line);
};

