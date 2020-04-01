/*Gladys Roman
  CSE330 Lab1 Part2
  This program finds the equivalent postfix expression Y for the algorithm X, which is an arithmetic expression written in infix notation.
  June 20, 2019
*/

// libraries
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
class Stack
{
 	public:
 	Stack();//creates the stack
 	bool isempty(); // returns true if the stack is empty
 	T gettop();//returns the front of the list 
 	void push(T entry);//add entry to the top of the stack
 	void pop();//remove the top of the stack
 
	private:
 	vector<T> stack;
}; // Stack

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::isempty()
{ 	if (stack.size() == 0)
		return true;
	else
		return false;
}

template<typename T>
T Stack<T>::gettop()
{ 	return stack[stack.size()-1];
}

template<typename T>
void Stack<T>::push(T entry)
{   	stack.push_back(entry);
}

template<typename T>
void Stack<T>::pop()
{   	stack.pop_back();
}

string infix2postfix(string infix)
{       //put string into a vector 
	vector<char> x;
	vector<char> y;
	Stack<char> stack;
	char c;
	for(int i = 0; i < infix.length(); i++) 
	{	c = infix.at(i); //gets each char from the string
		x.push_back(c); //push each char into the vector
	}
	stack.push('[');
	x.push_back(']');
	
	while(!stack.isempty()) //while it's not empty
	{	if(x[0] == '(')
			stack.push(x[0]);
		//next is operators: +, -, /, *
		else if(x[0] == '+' || x[0] == '-')
		{	while(stack.gettop() == '+' || 
			      stack.gettop() == '-' ||
			      stack.gettop() == '*' ||
			      stack.gettop() == '/')
			{	y.push_back(stack.gettop());
				stack.pop();
			}
			stack.push(x[0]);
		}
		else if(x[0] == '*' || x[0] == '/')
		{ 	while(stack.gettop() == '*' || stack.gettop() == '/')
			{	y.push_back(stack.gettop());
				stack.pop();
			}
			stack.push(x[0]);
		}
		else if(x[0] == ')' || x[0] == ']')
		{	while(stack.gettop() != '(' && stack.gettop() != '[')
			{	y.push_back(stack.gettop());
				stack.pop();
			}
			stack.pop();
		}
		else 
			y.push_back(x[0]);

		x.erase(x.begin());
	}
	//for loop that goes thru y and returns a string that y creates
	string postfix;
	for(int i = 0; i < y.size(); i++)
	{	postfix += y[i];
	}
	
	return postfix;
}

// main
int main()
{
	string infix = "(A + B) * C - (D / (J + D))"; 
	cout << infix2postfix(infix) << endl;
	
	return 0;
}
