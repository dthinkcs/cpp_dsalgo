#include <iostream>
using namespace std;

class Node
{
  public:
    int coeff;
    int expo;
    Node* next;

    Node(int coeff, expo)
    {
      data = item;
      next = NULL;
    }

};

Node* mul(Node* a, Node* b)
{   Node *ptr1, *ptr3, *ptr, *result, *head, *r;
    result = new Node(); // create header NODE to generalize  code
    head = result;
    for ( ; a != NULL; a=a->next)
    {
      for (r = b; r! = NULL; r = r->next)
      {
        
        result->next = new Node((a->coeff) * (r->coeff), (a->expo) + (r->expo));
        
        result = result->next;
    
      }
    }
    
    result->next = NULL;
    result = head->next;
    delete (head); // delete header NODE
    // GOT IT RESULT NOW CONTAINS ALL
    ptr = result;
    
    while (ptr->next != NULL)
    {
      //ptr1 points to ptr
      ptr1 = ptr;  
      while (ptr1->next)
      {
        ptr3 = ptr1; // prevptr1 = ptr1 == ptr3
        ptr1  = ptr1->next; // ptr1 starts from ptr->next
        // if ptr and ptr1 are equal
        if (ptr->exp == ptr1->exp)
        {
          ptr-coeff = ptr->coeff + ptr1->coeff;
          ptr3->next = ptr1->next;
          delete ptr1;
          ptr1 = ptr3; // prevptr
        }
      }
      ptr=ptr-->next
    }
    
    return result;
}

int main()
{
  
  
}

