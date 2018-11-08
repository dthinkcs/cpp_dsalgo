//head is the head of you linked list
// Following is the node structure
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
/*
node* copy(node* headSource)
{
  if (headSource == NULL)
    return NULL;
  node* head = new node(headSource->data);
  head->next = copy(headSource->next);
  return head;
 
}

node* reverse(node* head)
{
  node* a = NULL;
  node* b = NULL;
  node* c = head;
  while (c != NULL)
  {
    a = b;
    b = c;
    c = c->next
      
    b->next = a;
    
  }
  head = b;
  return head;
}

bool check_palin(node* head1, node* head2)
{
  if (head1 == NULL && head2 == NULL)
    return true;
  if (head1 == NULL || head2 == NULL)
    return false;
  return check_palin(head1->next, head2->next);
}

bool check_palindrome(node* head)
{
	node* head2 = copy(head);
  	head2 = reverse(head2);
  	return check_palin(node* head, node* head2);
}
*/


// find the center of the list 
// 1 2 3 3 2 1
// compare 1 2 3 and reverse_of(3 2 1)
// Reverse the second list and compare two sublists. The time is O(n) * and space is O(1).

bool check_palindrome(node* head) 
{
	node*j,*i=head,*temp=head; 
	while(temp!=NULL && temp->next!=NULL) { 
		i=i->next; 
		temp=temp->next->next; 
	} 
	j=i; 
	node*smallhead = reverse_linked_list(i);
	temp = head; 
	
	while(temp!=NULL && smallhead!=NULL) 
	{ 
		if(temp->data==smallhead->data) 
		{ 
			temp=temp->next; 
			smallhead=smallhead->next; 
		} 
		else 
			return false; 
	} 
	return true; 
}

node *reverse_linked_list(node *head) 
{ 
	if(head==NULL||head->next==NULL) 
		return head; 
	node* smallhead = reverse_linked_list(head->next); 
	head->next->next=head;
	head->next=NULL; 
	return smallhead; 
} 
