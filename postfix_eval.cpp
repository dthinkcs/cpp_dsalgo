#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
// NO OF TESTED CASES: 2 valid postfix
/*
453*+2-
17
*/

class Stack
{
    int t;
    int s[MAX];

public:
    Stack()
    {
         t = -1;
    }
    void push(int item);
    int pop();
    int isFull() {return t == MAX - 1;}
    int isEmpty() {return t == -1;}
};

void Stack::push(int item)
{
    if (isFull())
        cout << "STACK OVERFLOW" << endl;
    else
        s[++t] = item;
}

int Stack::pop()
{
    if (isEmpty())
        return 0;
    else
        return s[t--];
}

int postfix_to_infix_eval(char* postfix)
{
    Stack s;
    for (int i = 0; postfix[i]; i++)
    {
        if (isdigit(postfix[i]))
            s.push(postfix[i] - '0');
        else
        {
            int operand2 = s.pop();
            int operand1 = s.pop();

            switch(postfix[i])
            {
            case '+':
                s.push(operand1 + operand2);
                break;
            case '-':
                s.push(operand1 - operand2);
                break;
            case '*':
                s.push(operand1 * operand2);
                break;
            case '/':
                s.push(operand1 / operand2);
                break;
            }
        }
    }
    return s.pop();
}

int main()
{
    char postfix[MAX], infix[MAX];
    cin >> postfix;
    cout << postfix_to_infix_eval(postfix);
}

