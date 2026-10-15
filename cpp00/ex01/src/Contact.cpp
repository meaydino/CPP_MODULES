#include<iostream>
#include"../include/Contact.hpp"

std::string Contact::get_first_name() const {
    return _firstName;
}

std::string Contact::get_last_name() const {
    return _lastname;
}

std::string Contact::get_nickname() const {
    return _nickname;
}

std::string Contact::get_phone_number() const {
    return _phonenumber;
}

std::string Contact::get_darkest_secret() const {
    return _darkestsecret;
}

void Contact::set_first_name(std::string firstName) {
    _firstName = firstName;
}

void Contact::set_last_name(std::string lastname) {
    _lastname = lastname;
}

void Contact::set_nick_name(std::string nickname) {
    _nickname = nickname;
}

void Contact::set_phone_number(std::string phonenumber) {
    _phonenumber = phonenumber;
}

void Contact::set_darkest_secret(std::string darkestsecret) {
    _darkestsecret = darkestsecret;
}
