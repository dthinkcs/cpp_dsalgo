#include <iostream>
using namespace std;
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
  //friend class LinkedList; 
};

class LinkedList
{
  Node* head;
  
  public:
    LinkedList()
    {
      head = NULL;  
    }
    void insert_tail(int item);
    // void insert_tail_efficient(int item); TODO
    int delete_head_int();
    void traverse();
};

void LinkedList::insert_tail(int item)
{
  Node* newptr = new Node(item);
  if (head == NULL)
    head = newptr;
  else
  {
    Node* ptr;
    for (ptr=head; ptr->next; ptr=ptr->next);

    ptr->next = newptr; // #pallu
  }
}

int LinkedList::delete_head_int()
{
  if (head == NULL) 
    return -999; // special value to indicate emptyness
  else
  {
    int val = head->data;
    
    Node* tmp = head;
    head = head->next;
    delete tmp;
    
    return val;
  }
}

void LinkedList::traverse()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    for(Node* ptr = head; ptr; ptr=ptr->next)
      cout << ptr->data << "\t";
    cout << endl;
  }
}



class Queue
{
  LinkedList lt;
  
  public:
    void enqueue(int n);
    int dequeue(); 
    void display();
};

void Queue::enqueue(int n)
{
  lt.insert_tail(n);  
}

// returns -999 if empty
int Queue::dequeue()
{
  return lt.delete_head_int();  
}

void Queue::display()
{
  lt.traverse(); 
}

int main()
{
  Queue s;
  s.enqueue(10);
  s.display();
  s.enqueue(20);
  s.display();
  s.dequeue();
  s.display();
  s.dequeue();
  s.display();

}
