#ifndef FORM_HPP
#define FORM_HPP

#include<iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _beSigned;
		const int _grade;
		const int _execute;
	public:
		Form();
		Form(const std::string &name, int grade, int execute);
		Form(const Form &other);
		Form &operator=(const Form &other);
		const std::string &getName() const;
		bool getBeSigned() const;
		int getGrade() const;
		int getExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		~Form();



		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream &os, const Form &form);



#endif
