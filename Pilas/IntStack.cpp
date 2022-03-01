#include <iostream>
#include "IntsStack.h"

using namespace std;


bool IntsStack::empty()
{
	if(top == -1) 
		return true;
		
	return false;
}

void IntsStack::insert(int n)
{
	stack[++top] = n;
}

void IntsStack::print()
{
	for(int i = top; i >= 0; i--)
	{
		cout << stack[i] << "\n";
	}
}

void IntsStack::pop()
{
	if(!empty())
		top--;
}

int IntsStack::get_top()
{
	if(!empty())
		return stack[top];
	
	return -1;
}

int IntsStack::length()
{
	return top;
}