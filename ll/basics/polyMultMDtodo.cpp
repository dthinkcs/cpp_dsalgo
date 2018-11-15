#include <iostream>
using namespace std;

class Node
{
  public:
  int coeff;
  int expo;
  Node* next;
  public:
  Node (int c, int e)
  {
    coeff = c;
    expo = e;
    next = NULL;
  }
};

/* attach after ptr->next OR if ptr is NULL attach it to ptr;BUG; need double pointers
Node* attach(Node* ptr)
{
  if (ptr == NULL)
    ptr = new
}
*/

void traverse(Node* start)
{
    for (Node* ptr = start; ptr; ptr=ptr->next)
        cout << ptr->coeff << "x^" << ptr->expo << "\t";
    cout << endl;
}

Node* multiply(Node* poly1start, Node* poly2start)
{
  Node* poly3start = NULL;
  for (Node* i = poly1start; i; i = i->next)
  {
    for (Node* j = poly2start; j; j = j->next) // [3x*2 + 7x + 1][2x + 2]
    {
      Node* newptr = new Node(i->coeff * j->coeff, i->expo + j->expo);
      Node* ptr;
      if (poly3start == NULL)
      {
        poly3start = newptr;
        ptr = poly3start;
      }
      else
      {
        ptr->next = newptr;
        ptr = ptr->next;
      }
    }
  }
  traverse(poly1start);
  traverse(poly2start);
  traverse(poly3start);


  // [3x^2 + 7x + 1] * [2x + 2] == [6x^3 + 6x^2 + 14*x^2 + 14x + 2x + 2]

  for (Node* i = poly3start; i->next; i = i->next)
  {
    // keep looking for j->next->expo insde soj is till6x^3 + 6x^2 + 14*x^2 + 14x + 2x but j->next is till 2x^0
    for (Node* j = i; j->next; )
    {
      if (i->expo == j->next->expo)
      {
        // delete j->next and UPDATE i->coeff
        i->coeff += j->next->coeff; // TODO if THE FINAL VALUE is zero //this value is zero
        Node* tmp = j->next;
        j->next = tmp->next;
        delete tmp;
      }
      else
        j = j->next;
    }
  }
  traverse(poly3start);

  // TODO remove if THE FINAL VALUES are zero 

  return poly3start;
}

Node* initializePoly(Node* poly1start)
{
  // 3x*2 + 7x + 1
  poly1start = new Node(3, 2);
  poly1start->next = new Node(7, 1);
  poly1start->next->next = new Node(1, 0);

  return poly1start;
}

Node* initializePoly2(Node* poly2start)
{
  // 2x + 2
  poly2start = new Node(2, 1);
  poly2start->next = new Node(2, 0);

  return poly2start;
}

int main() {
  Node* poly1start = NULL;
  poly1start = initializePoly(poly1start);
  Node* poly2start = NULL;
  poly2start = initializePoly2(poly2start);

  Node* poly3start = multiply(poly1start, poly2start);
}
