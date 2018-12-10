/*************
 Following is the Node structure already written.
 
 template <typename T>
 class Node {
	public:
	T data;
	Node* next;
 
	Node(T data) {
        next = NULL;
        this->data = data;
	}
 
	~Node() {
        if (next != NULL) {
            delete next;
        }
	}
 };
 
 *************/


Node<int> *rearrangeEvenOdd(Node<int> *head) {
	Node<int>* head2 =  head->next;
	Node<int>* ptr;
	for (ptr = head; ptr && ptr->next; ptr=ptr->next) {
		Node<int>* tmp = ptr->next;
		ptr->next = ptr->next->next;
		if (tmp->next) 
			tmp->next = tmp->next->next; 
      	else
          break; // HERE WAS A BUG
	}

	ptr->next = head2;

	return head;
}
