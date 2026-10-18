#include "../includes/AMateria.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"
#include "../includes/Character.hpp"
#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include <iostream>

static void separator(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main()
{
	separator("Subject main");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	separator("Unknown type / empty inventory edge cases");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());

		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "createMateria(\"fire\") -> NULL (OK)" << std::endl;

		ICharacter* alice = new Character("alice");
		alice->use(0, *alice);
		alice->use(-1, *alice);
		alice->use(99, *alice);
		alice->unequip(0);
		alice->unequip(-1);
		alice->unequip(42);

		delete alice;
		delete src;
	}

	separator("Full inventory + unequip (no delete)");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* hero = new Character("hero");
		AMateria* floor[4];
		for (int i = 0; i < 4; i++)
			floor[i] = NULL;

		AMateria* m0 = src->createMateria("ice");
		AMateria* m1 = src->createMateria("cure");
		AMateria* m2 = src->createMateria("ice");
		AMateria* m3 = src->createMateria("cure");
		AMateria* m4 = src->createMateria("ice");

		hero->equip(m0);
		hero->equip(m1);
		hero->equip(m2);
		hero->equip(m3);
		hero->equip(m4);
		if (m4)
		{
			std::cout << "5th equip ignored (inventory full), deleting leftover" << std::endl;
			delete m4;
		}

		ICharacter* foe = new Character("foe");
		hero->use(0, *foe);
		hero->use(1, *foe);
		hero->use(2, *foe);
		hero->use(3, *foe);

		floor[1] = m1;
		hero->unequip(1);
		hero->use(1, *foe);
		std::cout << "slot 1 empty after unequip (no crash)" << std::endl;

		AMateria* refill = src->createMateria("ice");
		hero->equip(refill);
		hero->use(1, *foe);

		delete foe;
		delete hero;
		for (int i = 0; i < 4; i++)
			delete floor[i];
		delete src;
	}

	separator("Character deep copy");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		Character original("original");
		original.equip(src->createMateria("ice"));
		original.equip(src->createMateria("cure"));

		Character copy(original);
		Character assigned("tmp");
		assigned = original;

		ICharacter* target = new Character("target");
		std::cout << "original:" << std::endl;
		original.use(0, *target);
		original.use(1, *target);
		std::cout << "copy:" << std::endl;
		copy.use(0, *target);
		copy.use(1, *target);
		std::cout << "assigned:" << std::endl;
		assigned.use(0, *target);
		assigned.use(1, *target);

		delete target;
		delete src;
	}

	separator("MateriaSource full + copy");
	{
		MateriaSource src;
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());
		src.learnMateria(new Cure());
		src.learnMateria(new Ice());

		AMateria* a = src.createMateria("ice");
		AMateria* b = src.createMateria("cure");
		AMateria* c = src.createMateria("fire");
		if (a)
			std::cout << "created: " << a->getType() << std::endl;
		if (b)
			std::cout << "created: " << b->getType() << std::endl;
		if (c == NULL)
			std::cout << "unknown type still NULL after full learn (OK)" << std::endl;

		MateriaSource copy(src);
		AMateria* d = copy.createMateria("ice");
		if (d)
			std::cout << "copy source created: " << d->getType() << std::endl;

		delete a;
		delete b;
		delete c;
		delete d;
	}

	separator("Done");
	return 0;
}
