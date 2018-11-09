#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
// NO OF TESTED CASES: 2 valid prefix eval
/*
-+4*532
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

int prefix_to_infix(char* prefix, char* infix)
{
    Stack s;
    // do either backwards walking OR strrev(prefix) and walk from 0 to len - 1;
    for (int i = strlen(prefix) - 1; i >= 0; i--) // CHANGE 1
    {
        if (isdigit(prefix[i]))
            s.push(prefix[i] - '0');
        else
        {
            int operand1 = s.pop(); // CHANGE 2
            int operand2 = s.pop(); // CHANGE 3

            switch(prefix[i])
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
    char prefix[MAX], infix[MAX];
    cin >> prefix;
    cout << prefix_to_infix(prefix, infix) << endl;
}


