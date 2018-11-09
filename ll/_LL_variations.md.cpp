// insertHead
// LL
Node* insertHead(Node* head, int item)
{
  Node* newptr = new Node(item);
 
  newptr->next = head; // L1
  head = newptr;      // L2
  
  
  return head;
}
// LL (cicular::this) 2 edge cases NULL, []->
Node* insertHead(Node* head, int item)
{
  Node* newptr = new Node(item);
  if (head == NULL)
    head = newptr;
  else {
    // find ptr_tail
    for (ptr = head; ptr->next != head; ptr = ptr->next);

    newptr->next = ptr->next;
    ptr->next = newptr;

    head = newptr; // same as ptr->next  ONLY DIFF
  }
  
  
  return head;
}

// DLL
DNode* insertHead(DNode* head, int item)
{
  DNode* head = new DNode(item);
  newptr->next = head;
  newptr->prev = NULL;             // L3
  if (newptr->next)                // L4
    newptr->next->prev = newptr;
  head = newptr;
  
  
  return head;
}

// DLL (circular: this this)
DNode* insertHead(DNode* head, int item)
{
  DNode* newptr = new DNode(item);
  if (head == NULL)
  {
    head = newptr;
  }
  else
  {
    DNode* ptr = head->prev; // ptr_tail
    
    newptr->next = ptr->next;
    newptr->prev = ptr;
    if (newptr->next)
      newptr->next->prev = newptr;
    ptr->next = newptr;
    
    head = newptr; // ONLY DIFF(in circular)
  }


  return head;
}



// LL
Node* deleteHead(Node* head)
{
  if (head == NULL)
    return NULL;
  else if (head->next == NULL)
  {
    delete head;
  }

  return head;
}

// LL
Node* deleteHead(Node* head)
{
  if (head == NULL)
    return NULL;
  else
  {
    Node* tmp = head;
    head = tmp->next;
    delete tmp;
  }

  return head;

}
// LL (cicular:this)
Node* deleteHead(Node* head)
{
  if (head == NULL)
    return NULL;
  else if (head->next == head)
  {
    delete head;
    return NULL;
  }
  else 
  {
    // find tail
    Node* ptr;
    for (ptr = head; ptr->next != head; ptr = ptr->next);

    Node* tmp = ptr->next;
    ptr->next = tmp->next;
    delete tmp;

    head = ptr->next;
  }

  return head;

}

// DLL
DNode* deleteHead(Node* head)
{
  if (head == NULL)
    return NULL;
  else (head->next == NULL)
  {
    delete head;
    return NULL;
  }
  else 
  {
    DNode* tmp = head;
    head = head->next;
    delete tmp;
    if (head)
      head->prev = NULL;


  }
  return head;
}

// DLL Circular
DNode* deleteHead(Node* head)
{
  if (head == NULL)
    return NULL ;
  else if (head->next == head)
  {
    delete head;
    return NULL;
  }
  else
  {
    ptr = head->prev; // tail


    DNode* tmp = ptr->next;
    ptr->next = ptr->next->next;
    delete tmp;
    if (ptr->next)
      ptr->next->prev = ptr;

    head = ptr->next;

  }
  return head;
}
