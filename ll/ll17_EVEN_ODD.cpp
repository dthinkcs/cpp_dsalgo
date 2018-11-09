/ Following is the node structure
/**************
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    Arrange elements in a given Linked List such that, all even numbers are placed after odd numbers. Respective order of elements should remain same.
You don't need to print the elements, instead return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 4 5 2 -1
Sample Output 1 :
1 5 4 2 

};
***************/

node* arrange_LinkedList(node* head)
{ 
  node *temp = head, *prev=temp, *curr=head, *p; 
  while (temp!=NULL) 
  { 
    if ((temp->data) % 2 != 0) 
    { 
      if(curr==temp)
      { 
        p=curr; 
        curr=curr->next;
        prev=temp; 
        temp=temp->next; 
      } 
      else if(curr==head) 
      { 
        head=temp; 
        prev->next=temp->next; 
        head->next=curr; 
        p=head; 
        temp=prev->next; 
      } 
      else
      { 
        p->next=temp; 
        p=temp; 
        prev->next = temp->next; 
        temp->next=curr; 
        temp=prev->next; 
      } 
    }
    else
    { 
      prev = temp; 
      temp = temp->next; 
    } 
  } 
      
  return head; 
}
