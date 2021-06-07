#include "Services/FileService.h"

FileService::FileService()
{
}

FileService::FileService(std::string fileName) : file(fileName)
{
}

FileService::FileService(std::string fileName, std::ios_base::openmode mode) : file(fileName, mode)
{
}

FileService::~FileService()
{
	if (this->file.is_open())
	{
		this->file.close();
	}
}

void FileService::ChangeOpenedFile(std::string fileName)
{
	if (this->file.is_open())
	{
		this->file.close();
	}

	this->file.open(fileName);
}

std::string FileService::ReadLine(unsigned int lineNumber)
{
	if (!file)
	{
		throw std::exception("Reading from file failed!");
	}

	this->file.seekg(0);

	std::string dummy;
	for (size_t i = 0; i <= lineNumber; i++)
	{
		std::getline(this->file, dummy);
	}

	return dummy;
}

bool FileService::ReadNextLine(std::string& output)
{
	if (!file)
	{
		throw std::exception("Reading from file failed!");
	}

	std::string result;
	std::getline(this->file, result);

	if (this->file.eof())
	{
		return false;
	}

	output = result;

	return true;
}

void FileService::WriteLine(std::string line)
{
	if (!file)
	{
		throw std::exception("Reading from file failed!");
	}

	this->file.seekp(0, std::ios::end);

	this->file << line << std::endl;
}
