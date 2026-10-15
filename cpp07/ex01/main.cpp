#include<iostream>
#include"iter.hpp"

template<typename T>
void printElement(T &element)
{
    std::cout << element << std::endl;
}

void increment(int &n)
{
    n++;
}
int main()
{
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(int);

    std::cout << "--- Printing integer array ---" << std::endl;
    ::iter(intArray, intArrayLength, printElement<int>);

    std::string stringArray[] = {"Hello", "World", "from", "iter"};
    size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

    std::cout << "\n--- Printing string array ---" << std::endl;
    ::iter(stringArray, stringArrayLength, printElement<std::string>);

    std::cout << "\n--- Incrementing and printing integer array ---" << std::endl;
    ::iter(intArray, intArrayLength, increment);
    ::iter(intArray, intArrayLength, printElement<int>);

    const int constIntArray[] = {10, 20, 30};
    size_t constIntArrayLength = sizeof(constIntArray) / sizeof(int);
    std::cout << "\n--- Printing const integer array ---" << std::endl;
    ::iter(constIntArray, constIntArrayLength, printElement<const int>);


    return 0;
}
