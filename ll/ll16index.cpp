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

int indexOfNRecursive(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
  if (head == NULL)
    return -1;
    if (n == head->data)
      return 0;
  int smallAns =  indexOfNRecursive(head->next, n);
  if (smallAns == -1)
    return -1;
  else
    return 1 + smallAns;
}


