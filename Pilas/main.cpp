#include "IntsStack.h"
#include <iostream>

using namespace std;

void deletebase(IntsStack& stack);

int main()
{
	IntsStack stack;
	
	stack.insert(5);
	stack.insert(4);
	stack.insert(3);
	stack.insert(8);
	stack.insert(7);
	
	stack.print();
	
	deletebase(stack);
	
	cout <<  "\n\n";
	
	stack.print();
	
	cin.get();
	return 1;
}


void deletebase(IntsStack& stack)
{
	IntsStack aux;

	while(!stack.empty())
	{
		aux.insert(stack.get_top());
		stack.pop();
	}

	aux.pop();

	while(!aux.empty())
	{
		stack.insert(aux.get_top());
		aux.pop();
	}
}

