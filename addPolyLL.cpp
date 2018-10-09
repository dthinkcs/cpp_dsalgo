class Node
{
	int data;
	Node* next;
};


Node* merge(LinkedList l1, LinkedListl2)
{
	Node *head1, *ptr1 = l1.head;
	Node *head2, *ptr2 = l2.head;
	Node* head3; 

	while (ptr1 && ptr2)
	{
		if (ptr1->data < ptr2->data)
		{	
			// take it in
			if (!head3)
				head3 = new Node(ptr1->data);
			else
				ptr3 = new Node(ptr1->data);

			// advance ptr1
			ptr1=ptr1->next;
		}
		else
		{
			if (!head3)
				head3 = new Node(ptr2->data);
			else
				ptr3 = new Node(ptr2->data);


			ptr2=ptr2->next;
		}
		// else addition if equal
		// {}
		ptr3=ptr3->next;
	}
}
