node* sort(node* head)
{
    for (node* i = head; i && i->next; i = i->next) {
        for(node* j = i; j && j->next ; j = j->next){
            if (j->next->data < i->data )
            {
                int tmp = j->next->data;
                j->next->data = i->data;
                i->data = tmp;
            }
        }   
    }
    return head;
}

bool findNode(node* head, int item)
{
    if (head == NULL)
        return false;
    if (head->data == item)
        return true;
    return findNode(head->next, item);
}

node* removeDup(node* head)
{
    for (node* i = head; i && i->next; i = i->next )
    {
        for (node *j = i; j->next;  )
        {
            if (i->data == j->next->data)
            {
                node* tmp = j->next;
                j->next = tmp->next;
                delete tmp;
            }
            else
                j = j->next;
        }     
    }
    return head;
}

node* findIntersection(node* head1, node* head2)
{
    // code here
    //head1 = removeDup(head1);
    //head2 = removeDup(head2);
    node* head = NULL;
    node* ptr = NULL;
    for (node* ptr2 = head1; ptr2 ; ptr2 = ptr2->next)
    {
        if (findNode(head2, ptr2->data))
        {
            node* newptr = new node(); newptr->data = ptr2->data;
            if (head == NULL)
            {
                head = newptr;
                ptr = head;
            }
            else
            {
                ptr->next = newptr;
                ptr = ptr->next;
            }
        }
    }
    return sort(removeDup((head)));
}


// https://practice.geeksforgeeks.org/problems/intersection-of-two-linked-list/1
//https://www.geeksforgeeks.org/union-and-intersection-of-two-linked-lists/
