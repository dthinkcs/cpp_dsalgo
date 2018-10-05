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

    void traverse();

    void insert_head(int item);
    void insert_tail(int item);
    void insert_sorted(int item);
    void insert_pos(int item, int pos);

    void delete_pos(int item, int pos);
};

void LinkedList::traverse()
{
  for (Node* ptr = head; ptr; ptr= ptr->next) // if (something) SAME AS if (something != 0)
    cout << ptr->data << " ";
  cout << endl;
}

void LinkedList::insert_head(int item)
{
  Node* newptr = new Node(item);

  newptr->next = head;
  head = newptr;
}

void LinkedList::insert_tail(int item)
{
  Node* newptr = new Node(item);
  if (head == NULL)
  {
    head = newptr; // pallu_tail
  }
  else // at least one element
  {
    Node* ptr;
    for (ptr = head; ptr->next != NULL; ptr=ptr->next);

    ptr->next = newptr; // pallu_tail
  }
}


void LinkedList::insert_sorted(int item)
{
  Node* newptr = new Node(item);

  if (head == NULL || item <= head->data)
  {
    // arrow jiske baad enter karna hai that is head
    newptr->next = head;
    head = newptr;
  }
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != NULL && item > ptr->next->data; ptr=ptr->next);
    // arrow jiske baad enter that is ptr->next
    newptr->next = ptr->next;
    ptr->next = newptr;
  }

}


void LinkedList::insert_pos(int item, int pos)
{
  if (pos < 0)
    cout << "Invalid Position" << endl;
  else if (pos == 1)
    insert_head(item);
  else if (head == NULL && pos != 1)
    cout << "Empty List and invalid position" << endl;
  else
  {

    int count = 2;
    Node* ptr;
    for (ptr = head; ptr->next != NULL && count != pos; ptr=ptr->next)
      count++;
    if (ptr->next == NULL && count != pos)
      cout << "Invalid Position" << endl;
    else
    {
      Node* newptr = new Node(item);
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
  }
}

void LinkedList::insert_before(int item_before, int item_new)
{
  if (head == NULL)
    cout << "Empty List! cannot insert" << endl;
  else if (head->data == item_before)
  {
    Node* newptr = new Node(item_new);
    newptr->next = head;
    head = newptr;
  }
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != NULL && ptr->next->data != item_before; ptr=ptr->next);
    if (ptr->next == NULL)
    {
      cout << "Item not found in the list " << endl;
    }
    else
    {
      Node* newptr = new Node(item_new);
      // ptr->next ke baad insert || head is replaced by ptr->next
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
  }
}

void LinkedList::insert_after(int item_after, int item_new)
{
  if (head == NULL)
    cout << "Empty List! cannot insert" << endl;
  else
  {
    Node* ptr;
    for (ptr = head; ptr != NULL && ptr->data != item_before; ptr=ptr->next); // pallu
    if (ptr == NULL) // pallu
    {
      cout << "Item not found in the list " << endl;
    }
    else
    {
      Node* newptr = new Node(item_new);
      // ptr->next ke baad insert || head is replaced by ptr->next
      newptr->next = ptr->next;
      ptr->next = newptr;
    }
  }
}

void LinkedList::deleteSpecific(int item)
{
  if (head == NULL)
    cout << "Empty List! Cannot delete" << endl;
  else if (head->data == item)
  {
    Node* tmp = head;
    head = head->next;
    delete tmp;
  }
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != NULL && ptr->next->data != item; ptr=ptr->next);
    if (ptr->next == NULL)
      cout << "Item not found in the list " << endl;
    else
    {
      // ptr->next ke baad delete || head is replaced by ptr->next #pallu
      Node* tmp = ptr->next;
      ptr->next = ptr->next->next;
      delete tmp;
    }
  }
}

void LinkedList::deleteHead()
{
  if (head == NULL)
    cout << "Empty List! Cannot Delete" << endl;
  else
  {
    // general code if head is 'long'
    Node* tmp = head;
    head = head->next;
    delete tmp;
  }
}

void LinkedList::deleteTail()
{
  if (head == NULL)
    cout << "Empty List! Cannot Delete" << endl;
  else if (head->next == NULL)
  {
    delete head; // deleting address pointed by head
    head = NULL
    /* general code
    Node* tmp = head;
    head = head->next;
    delete tmp;
    */
  }
  else
  {
    Node* ptr;
    for ( ptr = head; ptr->next->next != NULL; ptr=ptr->next);
    // delete ptr->next

    delete ptr->next;
    ptr->next = NULL;
    /* generel code

    Node* tmp = ptr->next;
    ptr->next= ptr->next->next;
    delte tmp;
    */
  }
}

void LinkedList::deleteAlternateEven()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    Node* ptr;
    for (ptr = head; ptr->next != NULL; ptr=ptr->next)
    {
      Node* tmp = ptr->next;
      ptr->next = tmp->next;
      delete tmp;
    }
  }
}

void LinkedList::deleteAlternateOdd()
{
  if (head == NULL)
    cout << "Empty List" << endl;
  else
  {
    Node* tmp = head;
    head = head->next;
    delete tmp;

    // deleteAlternateEven();

    Node* ptr;
    for (ptr = head; ptr->next != NULL; ptr=ptr->next)
    {
      Node* tmp = ptr->next;
      ptr->next = tmp->next;
      delete tmp;
    }

  }

}

void LinkedList::splitTwoThirds()
{

}

void LinkedList::reverse()
{

}

void LinkedList::sort()
{

}

void LinkedList::mergeInPlace()
{

}

void LinkedList::merge()
{

}

void LinkedList::mergeAlternate()
{

}


void LinkedList::


int main(void)
{
  LinkedList l1;
  l1.insert_head(20);
  l1.insert_head(10);
  l1.insert_tail(30);
  l1.insert_sorted(50);
  l1.insert_pos(40, 10);
  l1.traverse();
}

