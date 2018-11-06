void printIthNode(Node *head, int i) {


  int count = 0;
  Node* ptr;
  for (ptr = head; ptr!=NULL && count!= i; count++, ptr=ptr->next);
  if (ptr != NULL)
  	cout << ptr->data;
} 
  
void printIthNode2(Node *head, int i) {

  int count = 0;
  Node* ptr;
  for (ptr = head; ptr!=NULL && count!= i; count++, ptr=ptr->next);
  if (count == i)
  	cout << ptr->data;
} 

