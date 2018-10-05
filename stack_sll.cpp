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
    void insert_head(int item);
    int delete_head_int();
    void traverse_opp();
    void traverse_opp_helper(Node* ptr);

};

void LinkedList::insert_head(int item)
{
  Node* newptr = new Node(item);
  newptr->next = head;
  head = newptr;
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

void LinkedList::traverse_opp_helper(Node* ptr)
{
  if (ptr == NULL)
    return;
  else
  {
    traverse_opp_helper(ptr->next);
    cout << ptr->data << "\t";
  }
}

void LinkedList::traverse_opp()
{
  if (head == NULL)
    cout << "Empty!" << endl;
  else
  {
    traverse_opp_helper(head);
    cout << endl; 
    // SOLVED// pressing enter can be considered SLIGHT BUG
  }
}



class Stack
{
  LinkedList lt;
  
  public:
    void push(int n);
    int pop(); 
    void display();
};

void Stack::push(int n)
{
  lt.insert_head(n);  
}

// returns -999 if empty
int Stack::pop()
{
  return lt.delete_head_int();  
}

void Stack::display()
{
  lt.traverse_opp(); 
}

int main()
{
  Stack s;
  s.push(10);
  s.display();
  s.push(20);
  s.display();
  s.pop();
  s.display();
  s.pop();
  s.display();
  s.pop();
  s.display();
}
