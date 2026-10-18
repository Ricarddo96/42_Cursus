#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
	public:

	Character(std::string name);
	Character(const Character &copy);
	Character &operator=(const Character &rsh);
	~Character();
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

	private: 

	AMateria* inventory[4];
	std::string name;
};

#endif
