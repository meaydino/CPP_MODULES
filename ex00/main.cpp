#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* a = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();

    a->makeSound(); // Animal sound
    d->makeSound(); // Woof!
    c->makeSound(); // Meow!

    delete a;
    delete d;
    delete c;
}

