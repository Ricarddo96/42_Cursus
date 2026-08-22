#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	index = 0;
	count = 0;
}

std::string PhoneBook::format(std::string s)
{
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void PhoneBook::add()
{
	std::string fn = "";
	std::string ln = "";
	std::string nn = "";
	std::string pn = "";
	std::string ds = "";

	while (fn == "")
	{
		std::cout << "First name: " << std::endl;
		std::getline(std::cin, fn);
		if (fn == "")
			std::cout << "Invalid first name, please enter at least one character" << std::endl;
	}
	contacts[index].set_first_name(fn);
	while (ln == "")
	{
		std::cout << "Last name: " << std::endl;
		std::getline(std::cin, ln);
		if (ln == "")
			std::cout << "Invalid last name, please enter at least one character" << std::endl;
	}
	contacts[index].set_last_name(ln);
	while (nn == "")
	{
		std::cout << "Nickname: " << std::endl;
		std::getline(std::cin, nn);
		if (nn == "")
			std::cout << "Invalid nickname, please enter at least one character" << std::endl;
	}
	contacts[index].set_nick_name(nn);
	while (pn == "")
	{
		std::cout << "Phone number: " << std::endl;
		std::getline(std::cin, pn);
		if (pn == "")
			std::cout << "Invalid phone number, please enter at least one number" << std::endl;
	}
	contacts[index].set_phone_number(pn);
	while (ds == "")
	{
		std::cout << "Darkest secret: " << std::endl;
		std::getline(std::cin, ds);
		if (ds == "")
			std::cout << "Invalid darkest secret, please enter at least one character" << std::endl;
	}
	contacts[index].set_darkest_secret(ds);
	index = (index + 1) % 8;
	if (count < 8)
		count++;
}

void PhoneBook::search()
{
	int i = 0;
	std::string line;
	int idx;

	if (count == 0)
	{
		std::cout << "Empty PhoneBook" << std::endl;
		return;
	}
	while (i < count)
	{
		std::cout << std::right << std::setw(10) << i
			<< "|"
			<< std::right << std::setw(10) << format(contacts[i].get_first_name())
			<< "|"
			<< std::right << std::setw(10) << format(contacts[i].get_last_name())
			<< "|"
			<< std::right << std::setw(10) << format(contacts[i].get_nick_name())
			<< std::endl;
		i++;
	}
	std::cout << "Enter index: " << std::endl;
	std::getline(std::cin, line);
	std::stringstream converted(line);
	if (!(converted >> idx) || (idx < 0) || (idx >= count))
	{
		std::cout << "Not a valid number" << std::endl;
		return;
	}
	std::cout << "First name: " << contacts[idx].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[idx].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[idx].get_nick_name() << std::endl;
	std::cout << "Phone number: " << contacts[idx].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[idx].get_darkest_secret() << std::endl;
}
