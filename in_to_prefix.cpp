#include <iostream>
#include <string.h>
#define MAX_SIZE 50

using namespace std;
void in_to_pre(char infix[], char prefix[]);
int prec(char oper);

class Stack
{

    char s[MAX_SIZE];

    int t;

public:
    Stack()
    {
        t = -1;
    }

    void push(char n);
    char pop();
    int isFull();
    int isEmpty();

};

int Stack::isFull()
{
    return t == MAX_SIZE - 1;
}

void Stack::push(char n)
{
    if (t == MAX_SIZE - 1)
        cout << "STACK OVERFLOW";
    else
        s[++t] = n;
}

int Stack::isEmpty()
{
    return t == - 1;
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
    char infix[MAX_SIZE];
    cout << "Enter infix: ";
    cin >> infix;

    char prefix[MAX_SIZE];
    cout << "Corresponding pfix: ";
    in_to_pre(infix, prefix);
    cout << prefix;

}

void in_to_pre(char infix[], char prefix[])
{
    Stack s;
    int k = 0;
    int p1, p2;
    char e_pop;

    for (int i = strlen(infix) - 1; i >= 0; i--)
    {
        switch (infix[i])
        {

        // opening parenthesis
        case ')':
            s.push(infix[i]);
            break;

        //  closing parenthesis : keep on popping until you get an opening parenthesis
        case '(':
            while ((e_pop = s.pop()) != ')') // ; HERE WAS A BUG
                prefix[k++] = e_pop;
            break;

        // operators :: while precedence(1) < precedence(2) pop off and add to result
        case '+':
        case '-':
        case '*':
        case '/':
            if (!s.isEmpty())
            {
                p1 = prec(infix[i]);
                /*p2 = prec(e_pop = s.pop());
                while (p1 <= p2)
                {
                    prefix[k++] = e_pop;

                    if (s.isEmpty())
                        break;

                    e_pop = s.pop();
                    p2 = prec(e_pop);
                }
                */
                e_pop = s.pop();
                while (p1 < prec(e_pop))
                {
                    prefix[k++] = e_pop;
                    if (!s.isEmpty())
                        e_pop = s.pop();
                    else
                        break;
                }
                if (p1 >= prec(e_pop))
                {
                    s.push(e_pop);
                }
            }
            s.push(infix[i]);

            break;
        default: // operands
            prefix[k++] = infix[i];
        }
    }

    while (!s.isEmpty())
        prefix[k++] = s.pop();

    prefix[k] = '\0';

    strrev(prefix);

}

int prec(char oper)
{
    switch (oper)
    {
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}



