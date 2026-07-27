#ifndef RPN_HPP
#define RPN_HPP

#include<stack>
#include<iostream>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		bool isOperator(char c);
		void calculateOperation(char op);
		int calculate(const std::string& expression);

};


#endif
