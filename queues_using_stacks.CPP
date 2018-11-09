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
    void disp();
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

void Stack::disp()
{
    for (int i = 0; i <= t; i++)
        cout << s[i] << "\t";
    cout << endl;
}


class Queue
{
    Stack s1, s2;

public:
    void enqueue(int item)
    {
        s1.push(item);
    }

    int dequeue()
    {
        while (!s1.isEmpty())
            s2.push(s1.pop());

        int tmp = s2.pop();

        while (!s2.isEmpty())
            s1.push(s2.pop());

        return tmp;
    }

    void disp()
    {
        s1.disp();
    }

};

int main()
{
    Queue q; int x;

    q.enqueue(10);
    q.disp();
    q.enqueue(20);
    q.disp();
    q.enqueue(30);
    q.disp();
    if ((x = q.dequeue()) != -999)
        cout << x << endl;
    else
        cout << "Empty" << endl;

    q.disp();

    q.enqueue(10);
    q.disp();
}
