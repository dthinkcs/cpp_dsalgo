#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
// NO OF TESTED CASES: 3 valid postfix
/*
abc-+de-fg-h+/*
((a+(b-c))*((d-e)/((f-g)+h)))

*/
class Stack
{
    int t;
    char s[MAX][MAX];

public:
    Stack()
    {
         t = -1;
    }
    void push(char* item);
    char* pop();
    int isFull() {return t == MAX - 1;}
    int isEmpty() {return t == -1;}
};

void Stack::push(char* item)
{
    if (isFull())
        cout << "STACK OVERFLOW" << endl;
    else
        strcpy(s[++t], item);
}

char* Stack::pop()
{
    if (isEmpty())
        return 0;
    else
        return s[t--];
}

void postfix_to_infix(char* postfix, char* infix)
{
    Stack s;
    for (int i = 0; postfix[i]; i++)
    {
        char *operand2, *operand1;
        char res[MAX];
        char sym[2]; sym[0] = postfix[i]; sym[1] = '\0';
        switch (postfix[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            operand2 = s.pop();
            operand1 = s.pop();

            strcpy(res, "(");
            strcat(res, operand1);
            strcat(res, sym);
            strcat(res, operand2);
            strcat(res, ")");
            s.push(res);
            break;
        default:
            s.push(sym); // push operand sym is now
        }
    }
    strcpy(infix, s.pop());
}

int main()
{
    char postfix[MAX], infix[MAX];
    cin >> postfix;
    postfix_to_infix(postfix, infix);
    cout << infix << endl;
}

