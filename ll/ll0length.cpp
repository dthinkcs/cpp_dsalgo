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

int length(Node *head) {

  int count;
  Node* ptr;
  for (count = 0, ptr = head; ptr; count++, ptr=ptr->next);
  return count;
    
}

int length2(Node *head) {

  int count = 0;
  for (Node* ptr = head; ptr; ptr=ptr->next)
    count++;
  return count;
    
}


int length3(Node *head) {
    
  int count = 0;
  
  for (Node* ptr = head ; ptr ; count++, ptr=ptr->next);

  return count;
    
}

int length3buggy(Node *head) {
    
  int count = 0;
  
  for (Node* ptr = head ; ptr ; count++, ptr=ptr->next);

  return count;
    
}

