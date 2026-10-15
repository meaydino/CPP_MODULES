#include "RPN.hpp"
#include <sstream>

RPN::RPN(){}

RPN::RPN(const RPN &other):_stack(other._stack)
{}

RPN &RPN::operator=(const RPN &other)
{
	if(this != &other)
	{
		this->_stack = other._stack;
	}
	return(*this);
}

RPN::~RPN(){}

void RPN::calculateOperation(char op)
{
	if(_stack.size() < 2)
		throw std::exception();

	int first = _stack.top();
	_stack.pop();

	int second = _stack.top();
	_stack.pop();

	int result;

	if(op == '+')
		result = second + first;
	else if(op == '-')
		result = second - first;
	else if(op == '*')
		result = second * first;
	else if(op == '/')
	{
		if(first == 0)
			throw std::exception();
		result = second / first;
	}
	_stack.push(result);
}

int RPN::calculate(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string token;

	while(ss >> token)
	{
		if(token[0] >= '0' && token[0] <= '9')
		{
			_stack.push(token[0] - '0');
		}
		else if(token == "+" || token == "-" || token == "/" || token == "*")
			calculateOperation(token[0]);
		else
			throw std::exception();
	}
	if(_stack.size() != 1)
		throw std::exception();

	return(_stack.top());
}
