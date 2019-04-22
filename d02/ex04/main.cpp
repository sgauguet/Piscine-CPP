#include "Fixed.class.hpp"

std::stringstream& insert(std::stringstream& stack, const std::string& op ) // Insert operator on top of the stack
{
  std::streamsize pos = stack.tellp(); // position in output sequence
  stack.str( op + " " + stack.str() );
  stack.seekp( pos + op.length() ); //Set position in output sequence
  return stack;
}

std::stringstream& remove(std::stringstream& stack ) // Remove operator from top of the stack
{
	std::string result(stack.str());
	result = result.substr(result.find_first_of(" ")+1);
	stack.str( result );
	return stack;
}

float getFirstOperand(std::stringstream& stack ) // Get first operand of the stack
{
	float result;
	std::string token;
	std::stringstream tmp;
	std::getline(stack, token, ' ');
	tmp << token;
	tmp >> result;
	remove(stack);
	return result;
}

void	calculate(std::stringstream& expr) {
	Fixed result;
	std::string token;
	float op1;
	float op2;
	std::stringstream stack;
	std::stringstream tmp;

	while(std::getline(expr, token, ' ')) {
		tmp << token;
		if (tmp >> op1)
			insert(stack, token);
		else if (token == "+" || token == "-" || token == "*" || token == "/") {
			op1 = getFirstOperand( stack );
			op2 = getFirstOperand( stack );
			if (token == "+")
				result = op2 + op1;
			else if (token == "-")
				result = op2 - op1;
			else if (token == "*")
				result = op2 * op1;
			else if (token == "/")
				result = op2 / op1;
			insert(stack, result.toString());
		}
		tmp.str("");
		tmp.clear();
		stack.clear();
	}
	std::cout << result << std::endl;
}

void	eval_expr(std::string expr) {
	std::istringstream input(expr, std::istringstream::in); // Initial expression
	std::stringstream output; // Final expression converted in Reverse Polish Notation using Shunting-yard algorithm
	std::stringstream stack; // Operator stack 
	std::stringstream tmp;
	float f;
	std::string token;
	std::string token2;

	while(std::getline(input, token, ' ')) {
		tmp << token;
		if (tmp >> f) // If the token is a number, it is pushed to the output queue 
			output << f << " " ; 
		else if (token == "+" || token == "-" || token == "*" || token == "/") { // If the token is an operator...
			while (std::getline(stack, token2, ' ')) {
				if (token2 == "*" || token2 == "/" ) {
					output << token2 << " ";
					remove(stack);
				}
				else if ((token == "+" || token == "-") && token2 != "(") {
					output << token2 << " ";
					remove(stack);
				}
				else
					break ;
				token2.erase();
			}
			insert(stack, token);
		}
		else if (token == "(") // if the token is a left paren
			insert(stack, token);
		else if (token == ")") { // if the token is a right paren
			while (std::getline(stack, token2, ' ')) {
				if (token2 != "(") {
					output << token2 << " ";
					remove(stack);
				}
				else {
					remove(stack);
					break;
				}
				token2.erase();
			}
		}
		token.erase();
		token2.erase();
		tmp.str("");
		tmp.clear();
		stack.clear();
	}
	stack.clear();
	while (std::getline(stack, token2, ' ')) {
		output << token2 << " ";
		remove(stack);
	}
	//std::cout << "output : " << output.str() << std::endl;
	calculate(output);
}

int main(int argc, char **argv) {

	if (argc < 1)
		return 1;
	while (*++argv) {
			eval_expr(*argv);
	}
	return 0;
}
