/**********
 * Following is the Node class that is already written.
 
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
 
*********/

Node* deleteNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  	if (head == NULL)
      return NULL;
  	else if (i == 0)
    {
        Node* tmp = head;
  		head = head->next;
  		delete tmp;
    }
  	else
    {
		int count = 1; // 1 for index 2 for position
      	Node* ptr;
      	for (ptr = head; ptr != NULL && count != i ; count++, ptr = ptr->next);
      
        if (ptr != NULL)
        {
          Node* tmp = ptr->next;
          if (ptr->next) // AnalyZE!!! REALLY IMPORTANT !!!HERE LIED A BUG
          	ptr->next = tmp->next;
          delete tmp;
        }
      	
    }
  	return head;
}



