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

    Node(int item, Node* add)
    {
      data = item;
      next = add;
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

    LinkedList(Node* address)
    {
      head = address;
    }

    void traverse();
    void insertSorted(int item);
    //void deleteSpecific(int item);
    LinkedList merge(LinkedList l2);
    LinkedList mergeNoNew(LinkedList l2);
    //LinkedList merge2(LinkedList l2);
};

void LinkedList::traverse()
{
  for (Node* ptr = head; ptr; ptr=ptr->next)
    cout << ptr->data << "\t";
  cout << endl;
}

void LinkedList::insertSorted(int item)
{
  Node* newptr = new Node(item);
  if (head == NULL || item <= head->data)
  {
    newptr->next = head;
    head = newptr;
  }
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next && item > ptr->next->data; ptr=ptr->next);
    newptr->next = ptr->next;
    ptr->next = newptr;
  }
}

LinkedList LinkedList::merge(LinkedList l2)
{

  Node* head3 = NULL;

  if (head == NULL && l2.head == NULL)
    return LinkedList(head3);


  Node* ptr1 = head;
  Node* ptr2 = l2.head;
  if (head != NULL && l2.head == NULL)
    head3 = new Node(head->data);
  else if (head == NULL && l2.head != NULL)
    head3 = new Node(l2.head->data);
  else if (ptr1->data < ptr2 ->data)
  {
    head3 = new Node(ptr1->data);
    ptr1 = ptr1->next;
  }
  else
  {
    head3 = new Node(ptr2->data);
    ptr2 = ptr2->next;
  }

  Node* ptr3 = head3;
  while (ptr1 != NULL && ptr2 != NULL)  //  A bug once lied here!!!
  {
    if (ptr1->data < ptr2 ->data)
    {
      ptr3->next = new Node(ptr1->data);

      ptr1 = ptr1->next;
    }
    else
    {
      ptr3->next = new Node(ptr2->data);
      ptr2 = ptr2->next;
    }

    ptr3 = ptr3->next; //  A bug once lied here!!! BUG BUG BUG
  }

  while (ptr1 != NULL)
  {
    // copy from ptr1
    ptr3->next = new Node(ptr1->data);
    ptr1 = ptr1->next;
    ptr3 = ptr3->next; //  A bug once lied here!!! BUG BUG BUG
  }
  while (ptr2 != NULL)
  {
    // copy from ptr2
    ptr3->next = new Node(ptr2->data);
    ptr2 = ptr2->next;
    ptr3 = ptr3->next; //  A bug once lied here!!! BUG BUG BUG
  }

  LinkedList l3 = LinkedList(head3);
  return l3;

}

LinkedList LinkedList::mergeNoNew(LinkedList l2)
{

  Node* head3 = NULL;

  if (head == NULL && l2.head == NULL)
    return LinkedList(head3);
  else if (head != NULL && l2.head == NULL)
    head3 = head;
  else if (head == NULL && l2.head != NULL)
    head3 = l2.head;
  else
  {
      Node* ptr1 = head;
      Node* ptr2 = l2.head;
      Node* prevptr;
      if (ptr1->data < ptr2 ->data)
      {
        head3 = ptr1;
        prevptr = ptr1;
        ptr1 = ptr1->next;

      }
      else
      {
        head3 = ptr2;
        prevptr = ptr2;
        ptr2 = ptr2->next;

      }

      Node* ptr3 = head3;
      while (ptr1 != NULL && ptr2 != NULL)  //  A bug once lied here!!!
      {
        if (ptr1->data < ptr2 ->data)
        {
          prevptr->next = ptr1;

          ptr1 = ptr1->next;
        }
        else
        {
          prevptr->next = ptr2;
          ptr2 = ptr2->next;
        }

        prevptr = prevptr->next; //  A bug once lied here!!! BUG BUG BUG
      }

      if (ptr1 == NULL)
      {
        prevptr->next = ptr2;
      }

      if (ptr2 == NULL)
      {
          prevptr->next = ptr1;
      }

      LinkedList l3 = LinkedList(head3);
      return l3;
  }
}

/*
LinkedList LinkedList::merge2(LinkedList l2)
{

  Node* head3 = NULL;

  if (head == NULL && l2.head == NULL)
    return LinkedList(head3);
  else if (head != NULL && l2.head == NULL)
    head3 = head;
  else if (head == NULL && l2.head != NULL)
    head3 = l2.head;

  Node* ptr1 = head;
  Node* ptr2 = l2.head;
  if (ptr1->data < ptr2 ->data)
  {
    head3 = new Node(ptr1->data);
    ptr1 = ptr1->next;
  }
  else
  {
    head3 = new Node(ptr2->data);
    ptr2 = ptr2->next;
  }

  Node* ptr3 = head3;

  // BUGGY CODE with OR HERE In WHILE LOOP
  while (ptr1 != NULL || ptr2 != NULL)  //  A bug once lived here!!!
  {
    if ( ptr2 == NULL || ptr1->data < ptr2 ->data )
    {
      ptr3->next = new Node(ptr1->data);

      ptr1 = ptr1->next;
    }
    else if (ptr1 == NULL || ptr1->data >= ptr2 ->data )
    {
      ptr3->next = new Node(ptr2->data);
      ptr2 = ptr2->next;
    }

    ptr3 = ptr3->next; //  A bug once lived here!!! BUG BUG BUG
  }
    /*
  while (ptr1 != NULL)
  {
    // copy from ptr1
    ptr3->next = new Node(ptr1->data, ptr1->next);
    ptr1 = ptr1->next;
    ptr3 = ptr3->next;
  }
  while (ptr2 != NULL)
  {
    // copy from ptr2
    ptr3->next = new Node(ptr2->data, ptr2->next);
    ptr2 = ptr2->next;
    ptr3 = ptr3->next;
  }

  LinkedList l3 = LinkedList(head3);
  return l3;

}
*/

int main(void)
{
  LinkedList l1;
  LinkedList l2;

  l1.insertSorted(10);
  l1.insertSorted(30);
  l1.insertSorted(50);
  l1.traverse();

  l2.insertSorted(20);
  l2.insertSorted(40);
  l2.insertSorted(60);
    l2.insertSorted(80);

  l2.insertSorted(100);

  l2.traverse();

  LinkedList l3 = l1.mergeNoNew(l2);
  l3.traverse();
  cout << endl;
  l1.traverse();
  cout << endl;
  l2.traverse();


}
