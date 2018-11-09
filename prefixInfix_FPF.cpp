#include <iostream>
#include <cstring>
using namespace std;
#define MAX 50
/* NO OF TESTED CASES: 2 valid prefix

*+a-bc/-de+-fgh
((a+(b-c))*((d-e)/((f-g)+h)))

*-A/BC-/AKL
((A-(B/C))*((A/K)-L))

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

void prefix_to_infix(char* prefix, char* infix)
{
    Stack s;
    // do either backwards walking OR strrev(prefix) and walk from 0 to len - 1;
    for (int i = strlen(prefix) - 1; i >= 0; i--)
    {
        char *operand2, *operand1;
        char res[MAX];
        char sym[2]; sym[0] = prefix[i]; sym[1] = '\0';
        switch (prefix[i])
        {
        case '+':
        case '-':
        case '*':
        case '/':
            operand1 = s.pop();
            operand2 = s.pop();

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
    char prefix[MAX], infix[MAX];
    cin >> prefix;
    prefix_to_infix(prefix, infix);
    cout << infix << endl;
}

