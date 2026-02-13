#include"Dog.hpp"
#include"Cat.hpp"
#include"Animal.hpp"
int main()
{
	int size = 100;
	Animal *animal[size];
	for(int i = 0; i < (size / 2); i++)
		animal[i] = new Dog();
	for(int i = (size / 2); i < size; i++)
		animal[i] = new Cat();
	for(int i = 0; i < size; i++)
		animal[i]->makeSound();
	for(int i = 0; i < size; i++)
		delete animal[i];
	return 0;
}
// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "Animal.hpp"

// int main()
// {
//     std::cout << "=== Basic Test ===" << std::endl;
//     {
//         const Animal* j = new Dog();
//         const Animal* i = new Cat();
//         delete j;
//         delete i;
//     }

//     std::cout << "\n=== Array Test ===" << std::endl;
//     {
//         const int size = 10;
//         Animal *animals[size];

//         for(int i = 0; i < (size / 2); i++)
//             animals[i] = new Dog();
//         for(int i = (size / 2); i < size; i++)
//             animals[i] = new Cat();

//         for(int i = 0; i < size; i++)
//             animals[i]->makeSound();

//         for(int i = 0; i < size; i++)
//             delete animals[i];
//     }

//     std::cout << "\n=== Deep Copy Test ===" << std::endl;
//     {
//         Dog basic;
//         {
//             Dog tmp = basic;  // Copy constructor test
//         }

//         Cat cat1;
//         Cat cat2;
//         cat2 = cat1;  // Assignment operator test
//     }

//     return 0;
// }
