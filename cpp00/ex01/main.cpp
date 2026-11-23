#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	PhoneBook phonebook;
	std::string input;

	(void)argv;
	(void)argc;
	while (1)
	{
		std::cout << "Enter one of these three comands: ADD, SEARCH, EXIT --> " << std::endl;
		if (!std::getline(std::cin, input)) 
		{
        	std::cout << std::endl;
        	break;
		}
		if (input == "ADD")
		{
			phonebook.add();
		}
		else if (input == "SEARCH")
		{
			phonebook.search();
		}
		else if (input == "EXIT")
		{
			break;
		}
	}
	return 0;
}
