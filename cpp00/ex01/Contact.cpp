#include "Contact.hpp"

void Contact::set_first_name(std::string s)
{
	first_name = s;
}

void Contact::set_last_name(std::string s)
{
	last_name = s;
}

void Contact::set_nick_name(std::string s)
{
	nickname = s;
}

void Contact::set_phone_number(std::string s)
{
	phone_number = s;
}

void Contact::set_darkest_secret(std::string s)
{
	darkest_secret = s;
}

std::string Contact::get_first_name() const
{
	return first_name;
}

std::string Contact::get_last_name() const
{
	return last_name;
}

std::string Contact::get_nick_name() const
{
	return nickname;
}

std::string Contact::get_phone_number() const
{
	return phone_number;
}

std::string Contact::get_darkest_secret() const
{
	return darkest_secret;
}
