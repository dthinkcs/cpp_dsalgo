node* midpoint_linkedlist(node *head)
{
	  if (head == NULL)
      return NULL;
  	if (head->next == NULL)
      return head;
    // if (head == NULL || head->next == NULL) return head;
  
  	node* slowptr = head;
  	node* fastptr = head->next;
  	for (; fastptr && fastptr->next; slowptr=slowptr->next, fastptr=fastptr->next->next);
  	return slowptr;
}
