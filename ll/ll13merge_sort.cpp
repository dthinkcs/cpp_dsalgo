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

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  
node* merge(node *head1, node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	node* head = NULL;
	node* ptr = NULL;
	node* ptr1 = head1; // effectively tail 
	node* ptr2 = head2;

	while (ptr1 && ptr2)
	{
		if (ptr1->data < ptr2->data)
		{
			if (head == NULL)
			{
				head = ptr1;
				ptr = head;
				ptr1 = ptr1->next;
			}
			else
			{
				ptr->next = ptr1;
				ptr = ptr->next;
				ptr1 = ptr1->next;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = ptr2;
				ptr = head;
				ptr2 = ptr2->next;
			}
			else
			{
				ptr->next = ptr2;
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}

		}
	}

	if (ptr1 )
	{
		if (head == NULL)
		{
			head = ptr1;
		}
		else
		{
			ptr->next = ptr1;
		}

	}

	if (ptr2 )
	{
		if (head == NULL)
		{
			head = ptr2;
		}
		else
		{
			ptr->next = ptr2;
		}

	}	
	return head;

    
}

node* midpoint(node *head)
{
	if (head == NULL)
      return NULL;
  	if (head->next == NULL)
      return head;
  
  	node* slowptr = head;
  	node* fastptr = head->next;
  	for (; fastptr && fastptr->next; slowptr=slowptr->next, fastptr=fastptr->next->next);
  	return slowptr;
}


node* mergeSort(node *head) {
    //write your code here
	if (head == NULL || head->next == NULL)
      return head;
  	node* leftHead = head;
  
  	node* mid = midpoint(head);
  	node* rightHead = mid->next;
  	mid->next = NULL;
  
  	leftHead = mergeSort(leftHead);
  	rightHead = mergeSort(rightHead);
  	head = merge(leftHead, rightHead);
  	return head;
  	
}
