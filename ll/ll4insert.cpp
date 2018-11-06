//head is head of linked list,i is the index, data is data of your node
// Following is the node structure
/**************
 class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
 };
***************/

Node* insertNodeRec(Node *head, int i, int data) {

    if (head == NULL && i != 0)
      return head;
  	if (i == 0)
    {
      Node* newptr = new Node(data);
      newptr->next = head;
      head = newptr;
      return head;
    }
  	// head(BUG) instead of head->next(correct)
  	head->next = insertNodeRec(head->next, i - 1, data);
    return head;
}



