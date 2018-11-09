#include <iostream>
#define MAX_SIZE 50

using namespace std;
void in_to_post(char infix[], char postfix[]);
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

    char postfix[MAX_SIZE];
    cout << "Corresponding pfix: ";
    in_to_post(infix, postfix);
    cout << postfix;

}

void in_to_post(char infix[], char postfix[])
{
    Stack s;
    int k = 0;
    int p1, p2;
    char e_pop;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        switch (infix[i])
        {

        // opening parenthesis
        case '(':
            s.push(infix[i]);
            break;

        //  closing parenthesis : keep on popping until you get an opening parenthesis
        case ')':
            while ((e_pop = s.pop()) != '(') // ; HERE WAS A BUG
                postfix[k++] = e_pop;
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
                    postfix[k++] = e_pop;

                    if (s.isEmpty())
                        break;

                    e_pop = s.pop();
                    p2 = prec(e_pop);
                }
                */
                e_pop = s.pop();
                while (p1 <= prec(e_pop))
                {
                    postfix[k++] = e_pop;
                    if (!s.isEmpty())
                        e_pop = s.pop();
                    else
                        break;
                }
                if (p1 > prec(e_pop))
                {
                    s.push(e_pop);
                }
            }
            s.push(infix[i]);

            break;
        default: // operands
            postfix[k++] = infix[i];
        }
    }

    while (!s.isEmpty())
        postfix[k++] = s.pop();

    postfix[k] = '\0';

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



