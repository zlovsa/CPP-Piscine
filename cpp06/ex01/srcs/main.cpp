#include <iostream>
#include "main.hpp"

std::string *random_string()
{
	size_t l = 5 + rand() % 10;
	std::string *str = new std::string();
	while (str->length() < l)
	{
		char c = static_cast<char>(rand());
		while (!std::isprint(c) || std::ispunct(c))
			c = static_cast<char>(rand());
		*str += c;
	}
	return str;
}

void printData(Data*data)
{
	std::cout << data << ".str1 = '" << *data->str1 << "'" << std::endl
			  << data << ".int0 = " << data->int0 << std::endl
			  << data << ".str2 = '" << *data->str2 << "'" << std::endl
			  << "Size: " << sizeof(*data) << std::endl;
}

void *serialize(void)
{
	size_t len = sizeof(std::string *) + sizeof(int) + sizeof(std::string *);
	char *raw = new char[len];
	std::cout << "Allocated " << len << " bytes on the heap: " << raw << std::endl;

	std::string **str1p = reinterpret_cast<std::string **>(raw);
	int *int0p = reinterpret_cast<int *>(raw + sizeof(*str1p));
	std::string **str2p = reinterpret_cast<std::string **>(raw
								+ sizeof(*str1p) + sizeof(*int0p));

	*str1p = random_string();
	*int0p = rand();
	*str2p = random_string();

	std::cout << "Generated:" << std::endl
			  << str1p << " : '" << **str1p << "'" << std::endl
			  << int0p << " : " << *int0p << std::endl
			  << str2p << " : '" << **str2p << "'" << std::endl;
	
	return reinterpret_cast<void *>(raw);
}

Data *deserialize(void *raw)
{
	Data *data = 0;
	if (!raw)
		return 0;
	try
	{
		data = new Data;
		char *charraw = reinterpret_cast<char *>(raw);
		data->str1 = *reinterpret_cast<std::string **>(charraw);
		data->int0 = *reinterpret_cast<int*>(charraw + sizeof(data->str1));
		data->str2 = *reinterpret_cast<std::string **>(charraw
						+ sizeof(data->str1) + sizeof(data->int0));
		std::cout << "Deserialize (Data *) from (void*): " << std::endl;
		printData(data);
	}
	catch(std::exception &e)
	{
		std::cerr << "Error reinterpret: " << e.what() << std::endl;
		delete data;
		data = 0;
	}
	return data;
}

int main(void)
{
	srand(time(NULL));
	std::cout << "Generate and serialize:" << std::endl
			  << std::endl;
	void *ptr = serialize();
	std::cout << std::endl
			  << "Get (void *)" << ptr << ". Now deserialize:" << std::endl
			  << std::endl;
	Data *data = deserialize(ptr);
	delete data;
	return 0;
}