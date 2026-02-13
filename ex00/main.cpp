#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
//     const Animal* a = new Animal();
//     const Animal* d = new Dog();
//     const Animal* c = new Cat();

//     a->makeSound(); // Animal sound
//     d->makeSound(); // Woof!
//     c->makeSound(); // Meow!

//     delete a;
//     delete d;
//     delete c;
// }
int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    return 0;
}

