node* rev_linkedlist_itr(node* head)
{
    //write your iterative code here
 if(head==NULL || head->next == NULL )
   return head;
  node *prev = NULL;
  node* cur = head;
  node* c = head->next;
  while(cur!=NULL)
  {
    cur->next = prev;
    prev= cur;
    cur= c;
    if (c)
      c=c->next;
    
  }
  head = prev;
  return head;
    
}
