#include "FileReplace.class.hpp"
#include <sstream>
#include <iostream>
#include <fstream>

FileReplace::FileReplace(int argc, char *argv[])
{
	_fail = false;
	if (this->init(argc, argv))
		this->replace();
	return;
}

FileReplace::~FileReplace()
{
	return;
}

bool FileReplace::error(std::string msg)
{
	std::cerr << msg << std::endl;
	_fail = true;
	return false;
}

bool FileReplace::fail() const
{
	return _fail;
}

bool FileReplace::init(int argc, char *argv[])
{
	if (argc != 4)
		return this->error("Usage: replace <filename> <s1> <s2>");
	this->_filename = argv[1];
	this->_s1 = argv[2];
	this->_s2 = argv[3];
	if (this->_s1.empty() || this->_s2.empty())
		return error("<s1> and <s2> cannot be empty!");
	this->_ifs.open(this->_filename);
	if (!this->_ifs)
		return error("Error reading file!");
	this->_ofs.open(this->_filename.append(".replace"));
	if (!this->_ofs)
	{
		this->_ifs.close();
		return error("Error creating file!");
	}
	return true;
}

void FileReplace::replace()
{
	std::stringstream ss;
	ss << this->_ifs.rdbuf();
	std::string text = ss.str();
	size_t pos = text.find(this->_s1, 0);
	while (pos != std::string::npos)
	{
		text.replace(pos, this->_s1.length(), this->_s2);
		pos = text.find(this->_s1, pos + this->_s2.length());
	}
	this->_ofs << text;
	this->_ifs.close();
	this->_ofs.close();
}
