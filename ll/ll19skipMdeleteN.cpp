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
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list. That is, in the given linked list you need to delete N nodes after every M nodes.
Input format :

Line 1 : Linked list elements (separated by space and terminated by -1)

Line 2 : M

Line 3 : N

Sample Input 1 :
1 2 3 4 5 6 7 8 -1
2
2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
1 2 3 4 5 6 7 8 -1
2
3
Sample Output 2 :
1 2 6 7

***************/
node* skipMdeleteN(struct node *head, int M, int N) 
{ 
	// retain M nodes
	if(M == 0) {
	 return NULL;
	} 
	node *curr = head, *t;
	int count; 
	while (curr) 
	{ 
		for (count = 1; count<M && curr!= NULL; count++)
		  curr = curr->next; 
		// we are done if curr is NULL
		if (curr == NULL) 
			return head; 
		// take t to be the next thing
		t = curr->next; 
		for (count = 1; count<=N && t!= NULL; count++) 
		{
			 node *temp = t; 
			 t = t->next; 
			 free(temp); 
		} 
		// update curr->next AT LAST
		curr->next = t; 
		// for the while loop update
		curr = t; 
	} 
	return head; 
}
