#include <iostream>
using namespace std;

class DNode
{
  public:
    int expo;
    int coeff;
    DNode* next;
    DNode* prev;

    DNode(int e, int c)
    { // IMP
      expo = e;
      coeff = c;
      next = this;
      prev = this;
    }
};


void attach(DNode* newptr, DNode* ptr)
{
    if (newptr == NULL || ptr == NULL)
        return;
    newptr->next = ptr->next;
    newptr->prev = ptr;
    ptr->next->prev = newptr;
    ptr->next = newptr;

}


void insertPoly(DNode* poly)
{
    DNode* ptr = poly;
    int n, coeff;
    cout << "Enter degree of polynomial: ";
    cin >> n;

    for (int i = n; i >= 0; i--)
    {
        cout << "Enter coeff of exponent " << i << " :";
        cin >> coeff;

        if (coeff != 0)
        {
            DNode* newptr = new DNode(i, coeff);
            // insert after ptr->next
            attach(newptr, ptr);
        }
        ptr=ptr->next; // THIS WAS MISSING (BUG!!!) without this this made the code equivalent to adding to head;
    }
}

void display(DNode* poly)
{
    DNode* ptr = poly->next;
    if (ptr == NULL)
    {
        cout << "EMPTY!" << endl;
        return;
    }

    do
    {
        cout << ptr->coeff << "x^" << ptr->expo  << "\t";
        ptr = ptr->next;
    } while (ptr != poly);
    cout << endl;
}


void add(DNode* poly1, DNode* poly2, DNode* poly3)
{
    DNode* poly1copy = poly1;
    DNode* poly2copy = poly2;

    while (poly1->next != poly1copy && poly2->next != poly2copy)
    {
        if (poly1->next->expo > poly2->next->expo)
        {

            DNode* newptr = new DNode(poly1->next->expo, poly1->next->coeff);
            attach (newptr, poly3);
            // increment
            poly1 = poly1->next;

        }
        else if (poly1->next->expo < poly2->next->expo)
        {
            DNode* newptr = new DNode(poly2->next->expo, poly2->next->coeff);
            // attach
            attach (newptr, poly3);
            // increment
            poly2 = poly2->next;

        }
        else
        {
            // if addition result != 0 then add the new DNode
            int result = poly1->next->coeff + poly2->next->coeff;
            if (result != 0)
            {
                DNode* newptr = new DNode(poly1->next->expo, result);
                // attach
                attach (newptr, poly3);

            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        poly3 = poly3->next;
    }

    while (poly1->next != poly1copy)
    {
        DNode* newptr = new DNode(poly1->next->expo, poly1->next->coeff);
        // attach
        attach (newptr, poly3);
        // increment
        poly1 = poly1->next;
        poly3 = poly3->next;
    }

    while (poly2->next != poly2copy)
    {
        DNode* newptr = new DNode(poly2->next->expo, poly2->next->coeff);
        // attach
        attach (newptr, poly3);
        // increment
        poly2 = poly2->next;
        poly3 = poly3->next;

    }
}


int main()
{
    DNode* poly1 = new DNode(0, 0);
    DNode* poly2 = new DNode(0, 0);
    DNode* poly3 = new DNode(0, 0);
    insertPoly(poly1);
    display(poly1);
    insertPoly(poly2);
    display(poly2);

    add(poly1, poly2, poly3);
    display(poly3);

}
