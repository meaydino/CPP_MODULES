#include"Dog.hpp"
#include"Cat.hpp"
#include"Animal.hpp"
// int main()
// {
// 	int size = 100;
// 	Animal *animal[size];
// 	for(int i = 0; i < (size / 2); i++)
// 		animal[i] = new Dog();
// 	for(int i = (size / 2); i < size; i++)
// 		animal[i] = new Cat();
// 	for(int i = 0; i < size; i++)
// 		animal[i]->makeSound();
// 	for(int i = 0; i < size; i++)
// 		delete animal[i];
// 	return 0;
// }

int main()
{
    std::cout << "=== Basic Test ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }

    std::cout << "\n=== Array Test ===" << std::endl;
    {
        const int size = 10;
        Animal *animals[size];

        for(int i = 0; i < (size / 2); i++)
            animals[i] = new Dog();
        for(int i = (size / 2); i < size; i++)
            animals[i] = new Cat();

        for(int i = 0; i < size; i++)
            animals[i]->makeSound();

        for(int i = 0; i < size; i++)
            delete animals[i];
    }
	std::cout << "\n=== Real Deep Copy Proof ===\n";

	Dog dog1;
	dog1.setIdea(0, "I love bones");

	Dog dog2 = dog1;

	dog2.setIdea(0, "I love cats");

	std::cout << "Dog1 idea: " << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 idea: " << dog2.getIdea(0) << std::endl;

    std::cout << "\n=== Deep Copy Test ===" << std::endl;
    {
        Dog basic;
        {
            Dog tmp = basic;  // Copy constructor test
        }

        Cat cat1;
        Cat cat2;
        cat2 = cat1;  // Assignment operator test
    }

    return 0;
}
