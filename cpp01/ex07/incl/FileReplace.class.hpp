#ifndef FILEREPLACECLASS_H
# define FILEREPLACECLASS_H
# include <string>
# include <fstream>

class FileReplace
{
public:
	FileReplace(int argc, char *argv[]);
	~FileReplace();
	bool fail() const;

private:
	bool error(std::string msg);
	bool init(int argc, char *argv[]);
	void replace();
	std::string _filename;
	std::string _s1;
	std::string _s2;
	std::ifstream _ifs;
	std::ofstream _ofs;
	bool _fail;
};

#endif