#ifndef AFORM_HPP
#define AFORM_HPP

#include<iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _beSigned;
		const int _grade;
		const int _execute;
	public:
		AForm();
		AForm(const std::string &name, int grade, int execute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		const std::string &getName() const;
		bool getBeSigned() const;
		int getGrade() const;
		int getExecute() const;
		void beSigned(const Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;
		virtual ~AForm();

		class FormNotSignedException: public std::exception
		{
			public:
				const char *what() const throw();
		};
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
std::ostream &operator<<(std::ostream &os, const AForm &form);



#endif
