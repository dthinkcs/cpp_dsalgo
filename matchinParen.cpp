#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

bool isMatch(char* word);

class Stack
{
	char s[MAX_SIZE];
	int t;

	public:
		Stack()
		{
			t = -1;
		}

		void push(char);
		char pop();
};

void Stack::push(char ch)
{
	if (t == MAX_SIZE - 1)
		cout << "STACK OVERFLOW";
	else
		s[++t] = ch;
}

char Stack::pop()
{
	if (t == -1)
		return '\0';
	else
		return s[t--];
}

int main()
{

	char word[MAX_SIZE];
	cout << "Enter a word: ";
	gets(word);

	cout << word << (isMatch(word) ? " has Matching Parenthesis" : " does NOT have Matching Parenthesis");

}

bool isMatch(char* word)
{
	Stack charStack;
	int i;
	int len = strlen(word);

	for (i = 0; i < len; i++)
    {
        if (word[i] == '(')
            charStack.push(word[i]);
        else if (word[i] == ')')
            if (charStack.pop() == '\0')
                return false;
    }

    if (charStack.pop() != '\0')
        return false;

	return true;
}

