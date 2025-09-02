#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include<iostream>
#include"../include/Contact.hpp"

class PhoneBook
{
	Contact contacts[8];
	int contact_count;

	private:
		void display_contact(int index);
		void display_contacts();
		void display_field(const std::string fieldName, const std::string value);
		void add_contact(Contact contact);


		std::string	format_output(const std::string str) const;
		std::string	get_input(const std::string prompt) const;
		int	get_input_index(const std::string prompt) const;

	public:
		PhoneBook();
		void add();
		void search();
		bool empty();

};


#endif
