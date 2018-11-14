#include <iostream>
#include <cmath>
using namespace std;

class DNode
{
    public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int d)
    {
        data = d;
        next = prev = NULL;
    }
};

class Node
{
public:
    int numOfOcc;
    int num;
    Node* prev;
    Node* next;

    Node(int nO, int n)
    {
        numOfOcc = nO;
        num = n;
        prev = next = NULL;
    }
};

DNode* takeInput()
{
    int data;
    cin >> data;

    DNode* head = NULL;
    DNode* ptr =  NULL;
    while (data != -1)
    {
        if (head == NULL)
        {
            head = new DNode(data);
            head->prev = NULL;

            ptr = head;
        }
        else
        {
            ptr->next = new DNode(data);
            ptr->next->prev = ptr;

            ptr = ptr->next;
        }

        cin >> data;
    }

    return head;
}

/*
DNode* takInputRec()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    DNode* head = NULL;
    head->next = takeInputRec()
    head-
}
*/

void printForward(DNode* head)
{
    if (head == NULL)
        return;
    cout << head->data;
    printForward(head->next);
}

void printForward(Node* head)
{
    if (head == NULL)
        return;
    cout << head->numOfOcc << ", " << head->num << "\t";
    printForward(head->next);
}

void printBackwardH(DNode* tail)
{
    if (tail == NULL)
        return;
    cout << tail->data;
    printBackwardH(tail->prev);
}

void printBackward(DNode* head)
{
    DNode* ptr;
    for (ptr = head; ptr && ptr->next; ptr=ptr->next);

    printBackwardH(ptr);
}

int binaryToDecimal(DNode* head)
{
    if (head == NULL)
    {
        return 0;
    }

    DNode* ptrTail;
    for (ptrTail = head; ptrTail->next;  ptrTail=ptrTail->next);

    int res = 0;
    int k = 0;
    for ( ; ptrTail; ptrTail = ptrTail->prev )
    {
        res = res + ((ptrTail->data) * pow(2, k++));
    }


    return res;

}

Node* occurencesNodes(DNode* head)
{
    if (head == NULL)
        return NULL;

    Node* headNew = NULL; Node* ptrNew = NULL;

    int prev_value = head->data;
    int curr_value = head->data;
    int occurences = 0;
    for (DNode* i  = head; i; i = i->next)
    {
        curr_value = i->data;
        if (curr_value == prev_value)
            occurences++;
        else
        {

            if (headNew == NULL)
            {
                headNew = new Node(occurences, prev_value);
                ptrNew = headNew;
            }
            else
            {
                ptrNew->next = new Node(occurences, prev_value);
                ptrNew->prev = ptrNew;
                ptrNew = ptrNew->next;
            }

            occurences = 1; // current i value has 1
        }

        prev_value = curr_value; // update

    }

    if (headNew == NULL)
    {
        headNew = new Node(occurences, prev_value);
        ptrNew = headNew;
    }
    else
    {
        ptrNew->next = new Node(occurences, prev_value);
        ptrNew->prev = ptrNew;
        ptrNew = ptrNew->next;
    }

    return headNew;
}






int main(void)
{

    DNode* head = takeInput();
    // take ither way like mod10 SHIT

    printForward(head); cout << endl;
    Node* ninja = occurencesNodes(head); cout << endl;
    printForward(ninja); cout << endl;

    cout << binaryToDecimal(head) << endl;

}
