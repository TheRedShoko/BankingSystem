#include "Services/FileService.h"
#include <filesystem>

FileService::FileService()
{
}

FileService::FileService(const std::string& fileName)
{
	file.open(fileName, std::ios::out | std::ios::app);
	file.close();
	file.open(fileName);
}

FileService::FileService(const std::string& fileName, std::ios_base::openmode mode)
{
	file.open(fileName, mode);
}

FileService::~FileService()
{
	if (this->file.is_open())
	{
		this->file.close();
	}
}

void FileService::CreateFolder(const std::string& folder)
{
	std::filesystem::create_directories(folder);
}

void FileService::ChangeOpenedFile(const std::string& fileName)
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

void FileService::WriteLine(const std::string& line)
{
	if (!file)
	{
		throw std::exception("Reading from file failed!");
	}

	this->file.seekp(0, std::ios::end);

	this->file << line << std::endl;
}
