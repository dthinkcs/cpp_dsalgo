//head is the head of the linked list and n is  how many element you want to append from the last to the front
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

node* append_LinkedList(node* head,int n)
{
    //write your code here
  int count = 1;
  node* tail = head;
  for(;tail->next;count++,tail=tail->next);
  if(count<=n){
    return head;}
    else{
  int length = count;
  
  node * temp;
  tail->next = head;
  count=1;
  for(temp=head;count!=length-n;temp=temp->next,count++);
    head=temp->next;
  temp->next = NULL;
  return head;}
}
