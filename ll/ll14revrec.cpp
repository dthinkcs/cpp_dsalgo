/*
node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
 if(head==NULL || head->next == NULL)
   return head;
  
  node* small = reverse_linked_list_rec(head->next);
  node* temp = small;
  for(;temp->next!=NULL;temp=temp->next);
  temp->next = head;
  head->next = NULL;
 
  
  return small;
  
}
*/
node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
  if (head == NULL || head->next == NULL)
    return head;
  node* small = reverse_linked_list_rec(head->next);
  head->next->next = head;
  head->next = NULL;
  return small;
}


