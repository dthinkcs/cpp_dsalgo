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
    void delete_tail();
    void delete_specific(int item);

};



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

void CDLinkedList::delete_tail()
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
    DNode* tail_before = head->prev->prev;
    //for (ptr=head; ptr->next != head; ptr=ptr->next);
    // replication
    // modification
    delete tail_before->next;
    // adjustmentS
    tail_before->next = head;
    head->prev = tail_before;
    
  }
}


void CDLinkedList::delete_specific(int item)
{
  if (head == NULL)
    cout << "Empty List! Nothing to delete" << endl;
  else if (head->data == item)
  {
      delete_head();
  }
  else
  { // we have checked head already so we can check from  ptr->next (where ptr==next)
    DNode* ptr;
    for (ptr = head; ptr->next != head && ptr->next->data != item; ptr=ptr->next);
    if (ptr->next == head)
      cout << "Couldnt Find Item" << endl;
    else
    {
      // delete ptr->next  ; since must not be head
      // MUST CHANGE head->prev
      // MAY BE YOU DONT NEED THIS
      //if (ptr->next->next == head)
      //{
      //  head->prev = ptr;
        
      //  delete ptr->next;
      //  ptr->next = head;
        
      //}
      //else
      
      //{
        
        // UNTIL YOU ARE AT THE EDGES DONT CARE CIRCULAR
        DNode* tmp = ptr->next;
        ptr->next = tmp->next;
        delete tmp;
        ptr->next->prev = ptr;
      //}
    }
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

    cdll1.insert_head(10);
    cdll1.insert_head(20);
    cdll1.insert_head(30);
    cdll1.insert_head(40);
    cdll1.insert_head(50);

      cdll1.delete_specific(30);
  cdll1.traverse();
  cdll1.traverse_opp();
  
      cdll1.delete_specific(10);
  cdll1.traverse();
  cdll1.traverse_opp();
  
        cdll1.delete_specific(50);
  cdll1.traverse();
  cdll1.traverse_opp();
  
          cdll1.delete_specific(20);
  cdll1.traverse();
  cdll1.traverse_opp();
  
  cdll1.delete_specific(40);
  cdll1.traverse();
  cdll1.traverse_opp();

}
