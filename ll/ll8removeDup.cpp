/*
if (head == null)
  return null; 
while (current.next != null)
{ 
   if (current.data.equals(current.next.data)) 
   {
    current.next = current.next.next; 
   }
   else 
   {
    current = current.next; 
   } 
} 
return head;

*/

/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
***************/
node* eliminate_duplicate(node* head)
{
    //write your code here
  if(head==NULL)
    return NULL;
  if(head->next == NULL)
    return head;
  
  node* temp=head;
  
  while(temp->next!=NULL)
  {
    if(temp->data == (temp->next)->data)
    {	
      node* ptr = temp->next;
      
      if(ptr->next!=NULL)
      {
      	temp->next = ptr->next;
      	delete ptr;
      }
      else
      {
        delete ptr;
        temp->next = NULL;
       
      }
    }
    else
    temp=temp->next;
  }
  
  return head;
}
