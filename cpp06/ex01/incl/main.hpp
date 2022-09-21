#ifndef MAIN_HPP
# define MAIN_HPP
# include <string>

typedef struct Data
{
	std::string *str1;
	int int0;
	std::string *str2;
} t_data;

void *serialize(void);
Data *deserialize(void *raw);

#endif
