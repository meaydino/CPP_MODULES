#include<iostream>
#include"../include/PhoneBook.hpp"

int main()
{
	PhoneBook phonebook;
	std::string command;


	std::cout << "┌─────────────────────────────────────────┐" << std::endl;
	std::cout << "│               -WELCOME-                 │" << std::endl;
	std::cout << "│              -PHONEBOOK-                │" << std::endl;
	std::cout << "└─────────────────────────────────────────┘" << std::endl;
	std::cout << std::endl;

	while(!std::cin.eof() && !std::cin.fail())
	{
		std::cout << "┌─────────────────────────────────────────┐" << std::endl;
		std::cout << "│  Enter command (ADD, SEARCH, EXIT):     │" << std::endl;
		std::cout << "└─────────────────────────────────────────┘" << std::endl;
		std::cout << ">> ";

		if(!std::getline(std::cin, command))
		{
			std::cout << std::endl;
			break;
		}
		if(command == "ADD")
			phonebook.add();
		else if(command == "SEARCH")
			phonebook.search();
		else if(command == "EXIT")
			break;
	}
}
