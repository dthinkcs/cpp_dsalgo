#include <iostream>
using namespace std;

class DNode
{
  public:
    int data;
    DNode* next;
    DNode* prev;

    DNode(int item)
    {
      data = item;
      next = NULL;
      prev = NULL;
    }

};

class DLinkedList
{
    public:
  DNode* head;

    DLinkedList()
    {
      head = NULL;
    }

    void traverse();

    void insert_head(int item);
    void insert_tail(int item);
    void insert_sorted(int item);
    void insert_pos(int item, int pos);
    void insert_before(int item_before, int item_new);
    void insert_after(int item_after, int item_new);
    void reverse();
    void delete_pos(int item, int pos);
    void deleteSpecific(int item);
    void concat(DLinkedList);

};

void DLinkedList::concat(DLinkedList l2)
{
    if (head == NULL)
    {
        head = l2.head;
    }
    else
    {
        DNode* ptr;
        for ( ptr = head; ptr->next; ptr=ptr->next);
        ptr->next = l2.head;
    }
}

void DLinkedList::traverse()
{
  for (DNode* ptr = head; ptr; ptr= ptr->next) // if (something) SAME AS if (something != 0)
    cout << ptr->data << " ";
  cout << endl;
}

void DLinkedList::insert_head(int item)
{
  DNode* newptr = new DNode(item);

  newptr->next = head;
  // newptr->prev = NULL;
  if (head != NULL)
    head->prev = newptr; //EXTRA PREV DNODE
  head = newptr;
}

void DLinkedList::insert_tail(int item)
{
  DNode* newptr = new DNode(item);
  if (head == NULL)
  {
    head = newptr; // pallu_tail
  }
  else // at least one element
  {
    DNode* ptr;
    for (ptr = head; ptr->next != NULL; ptr=ptr->next);

    ptr->next = newptr; // pallu_tail
    newptr->prev = ptr; //EXTRA PREV DNODE
    // if (ptr->next != NULL) {ptr->next->prev = newptr}

  }
}


void DLinkedList::insert_sorted(int item)
{
  DNode* newptr = new DNode(item);

  if (head == NULL || item <= head->data)
  {
    // arrow jiske baad enter karna hai that is head
    newptr->next = head;
    //newptr->prev = NULL;
    if (head != NULL)
        head->prev = newptr;
    head = newptr;
  }
  else
  {
    DNode* ptr;
    for (ptr = head; ptr->next != NULL && item > ptr->next->data; ptr=ptr->next);
    // arrow jiske baad enter that is ptr->next

    newptr->next = ptr->next;

    newptr->prev = ptr;
    if (ptr->next != NULL) // HERE YOU ARE LOOKING AT THE VALUE not THE LOCATION
        ptr->next->prev = newptr;

    ptr->next = newptr;
  }

}


void DLinkedList::insert_pos(int item, int pos)
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
    DNode* ptr;
    for (ptr = head; ptr->next != NULL && count != pos; ptr=ptr->next)
      count++;
    if (ptr->next == NULL && count != pos)
      cout << "Invalid Position" << endl;
    else
    {
      DNode* newptr = new DNode(item);

      newptr->next = ptr->next;

      newptr->prev = ptr;
      if (ptr->next != NULL) {ptr->next->prev = newptr;}

      ptr->next = newptr;
    }
  }
}

void DLinkedList::insert_before(int item_before, int item_new)
{
  if (head == NULL)
    cout << "Empty List! cannot insert" << endl;
  else if (head->data == item_before)
  {
    DNode* newptr = new DNode(item_new);
    newptr->next = head;
    head = newptr;
  }
  else
  {
    DNode* ptr;
    for (ptr = head; ptr->next != NULL && ptr->next->data != item_before; ptr=ptr->next);
    if (ptr->next == NULL)
    {
      cout << "Item not found in the list " << endl;
    }
    else
    {
      DNode* newptr = new DNode(item_new);
      // ptr->next ke baad insert || head is replaced by ptr->next
      newptr->next = ptr->next;

      newptr->prev = ptr;
      if (ptr->next != NULL) {ptr->next->prev = newptr;}

      ptr->next = newptr;
    }
  }
}

void DLinkedList::insert_after(int item_after, int item_new)
{
  if (head == NULL)
    cout << "Empty List! cannot insert" << endl;
  else
  {
    DNode* ptr;
    for (ptr = head; ptr != NULL && ptr->data != item_after; ptr=ptr->next); // pallu
    if (ptr == NULL) // pallu
    {
      cout << "Item not found in the list " << endl;
    }
    else
    {
      DNode* newptr = new DNode(item_new);
      // ptr->next ke baad insert || head is replaced by ptr->next
      newptr->next = ptr->next;

      newptr->prev = ptr;
      if (ptr->next != NULL) {ptr->next->prev = newptr;}


      ptr->next = newptr;
    }
  }
}

// ------------- inserts done only change 2 steps: GIVEN ptr->next ke baad insert ||
/*
newptr->next = ptr->next;

newptr->prev = ptr;
if (ptr->next) {ptr->next->prev = newptr};

ptr->next = newptr;
*/
// ------------- inserts done only change 2 steps: GIVEN ptr->next ke baad insert ||

void DLinkedList::reverse()
{
    if (head == NULL)
        cout << "Empty List" << endl;
    else
    {
        DNode* a = NULL;
        DNode* b = NULL;
        DNode* c = head;
        while (c != NULL)
        {
            a = b;
            b = c;
            c = c->next;

            b->next = a;
            b->prev = c; // EXTRA prev thing
        }
        head = b;
    }
}

/*
void DLinkedList::reverse_jagaad_dont_be_water_everytime()
{
    if (head == NULL)
        cout << "Empty List" << endl;
    else
    {
        for (curr = head; curr; curr = curr->next)
        {
            Node* tmp = curr->next;
            curr->next = curr->prev;
            curr->prev = tmp;
        }

    }
}*/


void DLinkedList::deleteSpecific(int item)
{
  if (head == NULL)
    cout << "Empty List! Cannot delete" << endl;
  else if (head->data == item)
  {
    DNode* tmp = head;
    head = head->next;
    delete tmp;
    if (head != NULL)
        head->prev = NULL;
  }
  else
  {
    DNode* ptr;
    for (ptr = head; ptr->next != NULL && ptr->next->data != item; ptr=ptr->next);
    if (ptr->next == NULL)
      cout << "Item not found in the list " << endl;
    else
    {
      // ptr->next ke baad delete || head is replaced by ptr->next #pallu
      DNode* tmp = ptr->next;
      ptr->next = ptr->next->next;
      delete tmp;
      if (ptr->next != NULL) // EXTRA PREV
        ptr->next->prev = ptr;
    }
  }
}
/*

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

  }
  else
  {
    Node* ptr;
    for ( ptr = head; ptr->next->next != NULL; ptr=ptr->next);
    // delete ptr->next

    delete ptr->next;
    ptr->next = NULL;

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

*/

/*
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
*/

int main(void)
{
  DLinkedList l1;
    l1.insert_sorted(1);
    l1.insert_sorted(2);
    l1.insert_sorted(3);
    l1.insert_sorted(4);

  // l1.insert_pos(, 1);
  l1.traverse();

    DLinkedList l2;
    l2.insert_sorted(9);
    l2.insert_sorted(9);
    l2.insert_sorted(9);
    l2.insert_sorted(9);

    l2.traverse();

    DLinkedList l3;
  int a, b, c, sum;
    DNode *ptr1, *ptr2, *ptrt1, *ptrt2;
    for (ptrt1 = l1.head; ptrt1->next; ptrt1=ptrt1->next);
    for (ptrt2 = l2.head; ptrt2->next; ptrt2=ptrt2->next);

    a = b = c = 0;
    for (ptr1 = ptrt1, ptr2 = ptrt2; ptr1 || ptr2 ; )
    {
        a = ptr1 ? ptr1->data : 0;
        b = ptr2 ? ptr2->data : 0;
        sum = (a + b + c) % 10;
        l3.insert_head(sum);

        //update
        c = (a + b + c) / 10;
        if (ptr1)
            ptr1=ptr1->prev;
        if (ptr2)
            ptr2=ptr2->prev;
    }

    if (c != 0)
        l3.insert_head(c);

    l3.traverse();

    l1.concat(l2);
    l1.traverse();
}
