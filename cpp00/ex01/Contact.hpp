#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {

private:

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:

	void set_first_name(std::string s);
	void set_last_name(std::string s);
	void set_nick_name(std::string s);
	void set_phone_number(std::string s);
	void set_darkest_secret(std::string s);
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nick_name() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;
};

#endif
