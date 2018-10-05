#include <iostream>
using namespace std;
// TESTED CASES 3 elements, 6 elements, 7 elements, 2 elements

class Node
{
    public:
        int data;
        Node* next;

    Node(int item)
    {
        data = item;
        next = NULL;
    }
};

class LinkedList
{
    Node* head;

    public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(Node* h)
    {
        head = h;
    }

    void create();
    void traverse();
    int count_nodes();
    void split(Node** head1pp, Node** head2pp);
        void split2(Node** head1pp, Node** head2pp);

};


void LinkedList::create()
{
    int n, item;
    Node* ptr;

    cout << "Enter Number of Nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> item;
        if (head == NULL)
        {
            head = new Node(item);
            ptr = head;
        }
        else
        {
            ptr->next = new Node(item);
            ptr = ptr->next;
        }
    }
}

void LinkedList::traverse()
{
  for (Node* ptr = head; ptr; ptr=ptr->next)
    cout << ptr->data << "\t";
  cout << endl;
}

int LinkedList::count_nodes()
{
  int c = 0;
  for (Node* ptr = head; ptr; ptr=ptr->next)
    c++;
  return c;
}


void LinkedList::split(Node** head1pp, Node** head2pp)
{
    if (head == NULL)
    {
        *head1pp = *head2pp = head;
    }
    else
    {
        int two_thirds = (2 * count_nodes()) / 3;
        Node* ptr;
        int count = 1;
        for (ptr = head; ptr != NULL && count < two_thirds ; ptr=ptr->next)
            count++;
        *head1pp = head;
        *head2pp = ptr->next;
        // cutting the initial list
        ptr->next = NULL;
    }

}

/*
void LinkedList::split2(Node** head1pp, Node** head2pp)
{
    if (head == NULL)
    {
        *head1pp = *head2pp = NULL;
    }
    else
    {
        int two_thirds = (2 * count_nodes()) / 3;
        Node* ptr;
        int count = 1;

        *head1pp = new Node(head->data);
        Node* ptr1 = *head1pp;
        //count++; // Here lived NO BUG
        for (ptr = head->next; ptr != NULL && count < two_thirds ; ptr=ptr->next, ptr1=ptr1->next)
        {
            cout << "Count: " << count << "  " << "ptr->data: " << ptr->data << endl << endl;
            ptr1->next = new Node(ptr->data);
            count++;
        }
        // cout << ptr->data << endl << endl;
        *head2pp = new Node(ptr->data);
        Node* ptr2 = *head2pp;
        for (ptr = ptr->next; ptr ; ptr=ptr->next, ptr2=ptr2->next)
        {
            ptr2->next = new Node(ptr->data);
        }
        // cutting the initial list
        //ptr->next = NULL;
    }

}
*/
void LinkedList::split2(Node** head1pp, Node** head2pp)
{
    if (head == NULL)
    {
        *head1pp = *head2pp = NULL;
    }
    else
    {
        int two_thirds = (2 * count_nodes()) / 3;
        Node* ptr;
        int count = 1;

        *head1pp = new Node(head->data);
        Node* ptr1 = *head1pp;
        // count++; // Here lived NO BUG
        for (ptr = head; ptr->next != NULL && count < two_thirds ; ptr=ptr->next, ptr1=ptr1->next)
        {
            //cout << "Count: " << count << "  " << "ptr->data: " << ptr->data << endl << endl;
            ptr1->next = new Node(ptr->next->data);
            count++;
        }
        // cout << ptr->data << endl << endl;
        if (ptr->next == NULL)
        {
            *head2pp = NULL;
            return;
        }

        *head2pp = new Node(ptr->next->data);
        Node* ptr2 = *head2pp;
        for (ptr = ptr->next ; ptr->next ; ptr=ptr->next, ptr2=ptr2->next)
        {
            ptr2->next = new Node(ptr->next->data);
        }
        // cutting the initial list
        //ptr->next = NULL;
    }

}


int main()
{
    LinkedList l1;
    l1.create();
    l1.traverse();
    // cout << l1.count_nodes() << endl;

    Node *head1, *head2;
    l1.split2(&head1, &head2);
    LinkedList l2 = LinkedList(head1);
    LinkedList l3 = LinkedList(head2);
    l2.traverse();
    l3.traverse();
}
