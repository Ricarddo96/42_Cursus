#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook {

private:

	Contact contacts[8];
	int index;
	int count;
	std::string format(std::string s);

public:

	PhoneBook();
	void add();
	void search();
};

#endif
