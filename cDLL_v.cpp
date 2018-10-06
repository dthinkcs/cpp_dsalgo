#include <iostream>
using namespace std;

class DNode
{
  public:
    int data; 
    DNode* next;
    DNode* prev;
    
    DNode(int item)
    { // IMP
      data = item;
      next = this;
      prev = this;
    }
};

class CDLinkedList
{
  DNode* head;
  public:
    CDLinkedList()
    {
      head = NULL;
    }
    void traverse();
    void traverse_opp();
    void insert_head(int);
    void insert_pos(int, int);
    void insert_tail(int);
    void delete_speific();
    void delete_head();
};



void CDLinkedList::insert_tail(int item)
{
  DNode* newptr = new DNode(item);
  
  if (head == NULL)
  {
    head = newptr;
  }
  else
  {
    DNode* ptr = head->prev;
    //for (ptr = head; ptr->next != head; ptr=ptr->next);
    // NOT GENERIC CODE
    //ptr->next = newptr;
    //newptr->next = head;
    //newptr->prev = ptr;
    newptr->next = ptr->next;
    newptr->prev = ptr;
    ptr->next->prev = newptr;
    ptr->next = newptr;
  }
    
}

void CDLinkedList::insert_head(int item)
{
  DNode* newptr = new DNode(item);
  if (head == NULL) 
    head = newptr; // handled in constructor
  else
  {
    // EPIPHANY:: ptr->next is BOTH head AND head->prev here !!!
    // EPIPHNY :: we also have to change head->next
    
    newptr->next = head;
    newptr->prev = head->prev;
    
    // BUG WAS HERE: non generic code was here if (head->next == head){head->next = newptr} (NOT ALWAYYS )  
    DNode* tail = head->prev;
    head->prev = newptr;
    tail->next = newptr;
  
    
    head = newptr;
  }
}

void CDLinkedList::insert_pos(int item, int pos)
{
  DNode* newptr = new DNode(item);

  if (pos < 1)
    cout << "Invalid Position" << endl;
  else if (head == NULL && pos != 1)
    cout << "Invalid Position" << endl;
  else if (pos == 1)
  {
    insert_head(item);
  }
  else
  {

    int count = 2;
    DNode* ptr;
    for (ptr = head; ptr->next != head && count != pos ; count++, ptr=ptr->next);
    if (pos == count) // only when both are true
    {
      // GENERIC EVEN if tail == ptr
      newptr->next = ptr->next;
      newptr->prev = ptr;
      ptr->next->prev = newptr;
      ptr->next = newptr;      
    }
    else
    {
      cout << "Invalid Position" << endl;
    }
  }
}

void CDLinkedList::delete_head()
{
  if (head == NULL)
  {
    cout << "Empty List! Nothing to delete" << endl;
  }
  else if (head->next == head)
  {
    delete head;
    head = NULL;
  }
  else
  { // at least 2 elements

    // find tail
    DNode* tail = head->prev;
    //for (ptr=head; ptr->next != head; ptr=ptr->next);
    // replication
    // modification
    head = head->next;
    delete tail->next;
    // adjustmentS
    tail->next = head;
    head->prev = tail;
    
  }
}


void CDLinkedList::traverse()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    cout << "Normal: ";
    
    DNode* ptr = head;
    do 
    {
      cout << ptr->data << "\t";
      ptr=ptr->next;
    }
    while(ptr != head);
    
    cout << endl;
  }
}


void CDLinkedList::traverse_opp()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    cout << "OPPOSITE : ";
    // find tail and store it in ptrt
    DNode* ptrt = head->prev;
    do
    {
      cout << ptrt->data << "\t";
      ptrt=ptrt->prev;
    }
    while(ptrt != head->prev);
        
    cout << endl;
  }
}




int main() 
{
  CDLinkedList cdll1;
  /*
  cdll1.insert_tail(10);
  cdll1.insert_tail(20);
  cdll1.insert_tail(30);
  cdll1.insert_tail(40);
  */
    cdll1.insert_head(10);
    cdll1.insert_head(20);
    cdll1.insert_head(30);
    //cdll1.insert_head(40);
    cdll1.delete_head();
  cdll1.traverse();
  cdll1.traverse_opp();
  
      cdll1.delete_head();
  cdll1.traverse();
  cdll1.traverse_opp();
  
        cdll1.delete_head();
  cdll1.traverse();
  cdll1.traverse_opp();



  return 0;
}
