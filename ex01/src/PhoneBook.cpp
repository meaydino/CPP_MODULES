#include "../include/PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : contact_count(0) {
}

std::string PhoneBook::format_output(const std::string str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

std::string PhoneBook::get_input(const std::string prompt) const {
    std::string input;
    while (input.empty()) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            return "";
        }
        if (input.empty()) {
            std::cout << "┌─────────────────────────────────────────┐" << std::endl;
            std::cout << "│      This field cannot be empty!       │" << std::endl;
            std::cout << "└─────────────────────────────────────────┘" << std::endl;
        }
    }
    return input;
}

int PhoneBook::get_input_index(const std::string prompt) const {
    std::string input;
    int index;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl;
            return -1;
        }

        std::stringstream ss(input);
        if (ss >> index && ss.eof()) {
            if (index >= 0 && index < contact_count) {
                return index;
            }
            std::cout << "┌─────────────────────────────────────────┐" << std::endl;
            std::cout << "│     Index out of range! Enter 0-" << (contact_count - 1) << "      │" << std::endl;
            std::cout << "└─────────────────────────────────────────┘" << std::endl;
        } else {
            std::cout << "┌─────────────────────────────────────────┐" << std::endl;
            std::cout << "│    Invalid input! Enter a valid number  │" << std::endl;
            std::cout << "└─────────────────────────────────────────┘" << std::endl;
        }
    }
}

void PhoneBook::add_contact(Contact contact) {
    static int oldest_index = 0;

    if (contact_count < 8) {
        contacts[contact_count] = contact;
        contact_count++;
    } else {
        contacts[oldest_index] = contact;
        oldest_index = (oldest_index + 1) % 8;
    }
}

void PhoneBook::display_contacts() {
    std::cout << "┌───────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│  Index    │First Name│Last Name │ Nickname │" << std::endl;
    std::cout << "├───────────┼──────────┼──────────┼──────────┤" << std::endl;

    for (int i = 0; i < contact_count; i++) {
        std::cout << "│" << std::right << std::setw(10) << i << " │"
                  << std::setw(10) << std::right << format_output(contacts[i].get_first_name()) << "│"
                  << std::setw(10) << std::right << format_output(contacts[i].get_last_name()) << "│"
                  << std::setw(10) << std::right << format_output(contacts[i].get_nickname()) << "│" << std::endl;
    }
    std::cout << "└───────────┴──────────┴──────────┴──────────┘" << std::endl;
}

void PhoneBook::display_contact(int index) {
    if (index >= 0 && index < contact_count) {
        std::cout << "┌─────────────────────────────────────────────────────────────────────────┐" << std::endl;
        std::cout << "│                            CONTACT DETAILS                              │" << std::endl;
        std::cout << "├─────────────────────────────────────────────────────────────────────────┤" << std::endl;

        display_field("First Name", contacts[index].get_first_name());
        display_field("Last Name", contacts[index].get_last_name());
        display_field("Nickname", contacts[index].get_nickname());
        display_field("PhoneNumber", contacts[index].get_phone_number());
        display_field("DarkSecret", contacts[index].get_darkest_secret());

        std::cout << "└─────────────────────────────────────────────────────────────────────────┘" << std::endl;
    }
}

void PhoneBook::add() {
    Contact new_contact;

    std::cout << "┌─────────────────────────────────────────┐" << std::endl;
    std::cout << "│            ADDING NEW CONTACT           │" << std::endl;
    std::cout << "└─────────────────────────────────────────┘" << std::endl;

    std::string firstName = get_input("Enter first name: ");
    if (firstName.empty()) return;
    new_contact.set_first_name(firstName);

    std::string lastName = get_input("Enter last name: ");
    if (lastName.empty()) return;
    new_contact.set_last_name(lastName);

    std::string nickname = get_input("Enter nickname: ");
    if (nickname.empty()) return;
    new_contact.set_nick_name(nickname);

    std::string phoneNumber = get_input("Enter phone number: ");
    if (phoneNumber.empty()) return;
    new_contact.set_phone_number(phoneNumber);

    std::string darkestSecret = get_input("Enter darkest secret: ");
    if (darkestSecret.empty()) return;
    new_contact.set_darkest_secret(darkestSecret);

    add_contact(new_contact);
    std::cout << "┌─────────────────────────────────────────┐" << std::endl;
    std::cout << "│       Contact added successfully!       │" << std::endl;
    std::cout << "└─────────────────────────────────────────┘" << std::endl;
}

void PhoneBook::search() {
    if (contact_count == 0) {
        std::cout << "┌─────────────────────────────────────────┐" << std::endl;
        std::cout << "│           No contacts found!            │" << std::endl;
        std::cout << "└─────────────────────────────────────────┘" << std::endl;
        return;
    }

    display_contacts();
    int index = get_input_index("Enter the index of the contact to display: ");
    if (index >= 0) {
        display_contact(index);
    }
}

bool PhoneBook::empty() {
    return contact_count == 0;
}

void PhoneBook::display_field(const std::string fieldName, const std::string value) {
    const int maxLineWidth = 57;
    std::string paddedFieldName;
    std::string fullLine;
    size_t pos;
    bool firstLine;
    std::string line;
    int availableSpace;
    std::string indent;

    paddedFieldName = fieldName + ": ";

    if (value.length() <= maxLineWidth - paddedFieldName.length()) {
        fullLine = paddedFieldName + value;
        std::cout << "│ " << std::left << std::setw(70) << fullLine << "  │" << std::endl;
    } else {
        pos = 0;
        firstLine = true;

        while (pos < value.length()) {
            if (firstLine) {
                availableSpace = maxLineWidth - paddedFieldName.length();
                line = paddedFieldName + value.substr(pos, availableSpace);
                pos += availableSpace;
                firstLine = false;
            } else {
                indent = std::string(paddedFieldName.length(), ' ');
                availableSpace = maxLineWidth - paddedFieldName.length();
                line = indent + value.substr(pos, availableSpace);
                pos += availableSpace;
            }

            std::cout << "│ " << std::left << std::setw(70) << line << "  │" << std::endl;
        }
    }
}
