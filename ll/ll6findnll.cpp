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

int indexOfNIter(Node *head, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
 /* if(head==NULL)
  {
    return -1;
  }
  if(head->data==n)
    return 0;
  int small = indexOfNIter(head->next,n);
  if(small==-1)
    return small;
  return small+1;*/
  if(head==NULL)
    return NULL;
  Node* temp=head;
  int count=0;
  for(;temp!=NULL;temp=temp->next,count++)
  {
    if(temp->data==n)
      return count;
  }
  return -1;
}


