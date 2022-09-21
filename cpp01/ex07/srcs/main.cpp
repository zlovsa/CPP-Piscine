#include "FileReplace.class.hpp"

int main(int argc, char *argv[])
{
	FileReplace fr(argc, argv);
	if (fr.fail())
		return 1;
	return 0;
}