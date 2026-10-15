#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Correct Animal Test ===" << std::endl;
    const Animal* animals = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    i->makeSound();
    j->makeSound();
    animals->makeSound();

    delete animals;
    delete j;
    delete i;

    std::cout << "\n=== Wrong Animal Test ===" << std::endl;
    const WrongAnimal* wronganimals = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();

    std::cout << wrongcat->getType() << std::endl;
    wrongcat->makeSound();
    wronganimals->makeSound();

    delete wronganimals;
    delete wrongcat;

    return 0;
}

