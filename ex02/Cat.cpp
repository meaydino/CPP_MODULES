#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	brain = new Brain();
	std::cout << "Cat default contructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal("Cat")
{
	(void)type;
	brain = new Brain();
	std::cout << "Cat parameterized constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow!....Meow!" << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
	brain->setIdea(index, idea);
}
std::string Cat::getIdea(int index) const
{
	return(brain->getIdea(index));
}
