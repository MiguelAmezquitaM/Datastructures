#ifndef IntsStack_hpp
#define IntsStack_hpp

#include <iostream>

using namespace std;

class IntsStack
{
    int stack[100];
    int top;
    
public:
    void insert(int n);
    void print();
    int get_top();
    void pop();
    int length();
    bool empty();
    bool search(int n);
    IntsStack()
	{
		top = -1;
	}
};

#endif

