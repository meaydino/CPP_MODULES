#include "Zombie.hpp"

int main(void)
{
    Zombie* heapZombie;

    // Heap allocation
    heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie; // ❗ şart

    std::cout << "-----------------" << std::endl;

    // Stack allocation
    randomChump("StackZombie");

    return 0;
}
