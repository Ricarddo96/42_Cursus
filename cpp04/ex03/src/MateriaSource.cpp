#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rsh)
{
	if (this != &rsh)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->materias[i];
			if (rsh.materias[i])
				this->materias[i] = rsh.materias[i]->clone();
			else
				this->materias[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		delete this->materias[i];
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++) 
    {
        if (!this->materias[i])
        {
            this->materias[i] = m->clone();
            delete m;
            break;
        }
        else if (i == 3 && this->materias[i])
        {
            delete m;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->materias[i] != NULL)
        {
            if (this->materias[i]->getType() == type)
            {
                return this->materias[i]->clone();
            }
        }
    }
    return NULL;
}