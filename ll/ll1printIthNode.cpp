void printIthNode(Node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print output and don't return it.
     * Taking input is handled automatically.
     */

  int count = 0;
  Node* ptr;
  for (ptr = head; ptr!=NULL && count!= i; count++, ptr=ptr->next);
  if (ptr != NULL)
  	cout << ptr->data;
} 
  
