#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

class Stack
{
	char s[MAX_SIZE];
	int t[MAX_SIZE / 2];
	int b[MAX_SIZE / 2];

	public:
		Stack(int numOfStacks)
		{
			for (int i = 0; i <= numOfStacks  ; i++)
                t[i] = b[i] = (MAX_SIZE / numOfStacks) * i - 1;
		}

		void push(int stackPos, int value);
		int pop(int stackPos);
};

void Stack::push(int stackPos, int value)
{
    // pos = i - 1;
	if (t[stackPos-1] == b[stackPos])
		cout << "STACK OVERFLOW";
	else
		s[++t[stackPos-1]] = value;
}

int Stack::pop(int stackPos)
{
	if (t[stackPos-1] == b[stackPos-1])
		return -999;
	else
		return s[ t[stackPos-1]--];
}

int main()
{
    Stack s(4);
    s.push(1, 10);
    cout << s.pop(1);
}
