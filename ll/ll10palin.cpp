
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
