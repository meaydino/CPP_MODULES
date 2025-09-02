#ifndef CONTACT_HPP
#define CONTACT_HPP

#include<iostream>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastname;
		std::string _nickname;
		std::string _phonenumber;
		std::string _darkestsecret;

	public:
		std::string get_first_name() const;
		std::string get_last_name() const;
		std::string get_nickname() const;
		std::string get_phone_number() const;
		std::string get_darkest_secret() const;

		void set_first_name(std::string firstName);
		void set_last_name(std::string lastname);
		void set_nick_name(std::string nicname);
		void set_phone_number(std::string phonenumber);
		void set_darkest_secret(std::string darkestsecret);
};


#endif
