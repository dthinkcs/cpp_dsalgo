#include <iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
	/* BUG IN DELETE ALTERNATE NODES
	~Node()
	{
		delete next;
	}
	*/
};

void traverse2(Node* head)
{
	if (head == NULL)
		return;
	cout << head->data << "\t";
	traverse2(head->next);
}

void traverse(Node* head)
{
	if (head == NULL)
	{
		cout << "EMPTY LIST" << endl;
		return;
	}
	traverse2(head);
	cout << endl;
}

Node* copy(Node* headSource)
{
	if (headSource == NULL)
		return NULL;
	Node* head = new Node(headSource->data);
	head->next = copy(headSource->next);
	return head;
}


Node* reverse(Node* head)
{
	Node* a = NULL;
	Node* b = NULL;
	while (head != NULL)
	{
		a = b;
		b = head;
		head = head->next;

		b->next = a;
	}
	head = b;
	return head;
}

bool isPalindromeHelper(Node* head1, Node* head2)
{
	if (head1 == NULL && head2 == NULL)
		return true;
	if (head1 == NULL || head2 == NULL)
		return false;

	if (head1->data != head2->data)
		return false;
	return isPalindromeHelper(head1->next, head2->next);
	
}



bool isPalindrome(Node* head)
{
	return isPalindromeHelper(head, reverse(copy(head)));
}


Node* takeInput()
{
	int data;
	cin >> data;
	if (data == -1)
		return NULL;
	Node* head = new Node(data);
	head->next = takeInput();
	return head;
	/*

	Node* head = NULL;
	Node* tail = NULL;
	while (data != -1)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = head;
		}
		else
		{
			tail->next = newNode;
			tail = tail->next;
		}
		cin >> data;
	}
	return head;
	*/
}

void deleteAll(Node* head)
{
	if (head == NULL)
		return;
	deleteAll(head->next);
	delete head;
}

Node* deleteDuplicates(Node* head)
{
	// if you delete duplicates ofcourse you don't delete head
	if (head == NULL)
		return NULL;
	// 1 2 3 1 1 2
	// 1 1 1 1 1 
	for (Node* i = head; i != NULL && i->next != NULL; i = i->next)
	{
		for (Node* j = i; j != NULL && j->next != NULL; )
		{
			if (i->data == j->next->data)
			{
				//delete j->next
				Node* tmp = j->next;
				j->next = tmp->next;
				delete tmp;
			}
			else
				j = j->next;
		}
	}
	return head;
}

bool isPrime(int n)
{
	if (n == 1)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

Node* deleteHead(Node* head)
{
	if (head == NULL)
		return NULL;
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return head;
}
// maybe CIRCULAR cannot be recursive unless global
Node* deletePrimes(Node* head)
{
	if (head == NULL)
		return NULL;
	if (isPrime(head->data))
	{
		head = deleteHead(head);
		return deletePrimes(head);
	}
	// now head is OK but the remaing body CAN be CUT
	head->next =  deletePrimes(head->next);
	return head;
}
// ---------------------------------------
int length(Node* head)
{
	if (head == NULL)
		return 0;
	return 1 + length(head->next);
}
// head1->data, head2->data
Node* mergeInterleaveNEW(Node* head1, Node* head2)
{
	
	if (head1 == NULL && head2 == NULL)
		return NULL;
	
	Node* head = NULL;
	Node* ptr = head; // Node* ptr = head; BUG AT BOTTOM
	Node* ptr1 = head1;
	Node* ptr2 = head2;

	if (head1 == NULL)
	{
		head = new Node(head2->data);
		ptr2 = ptr2->next;
	}
	else
	{
		head = new Node(head1->data);
		ptr1 = ptr1->next;
	}
	ptr = head; // THIS WAS MISSING! FIRST BUG IN PROGRAMMING: equality vs assignment
	
	int count = 1;
	while (ptr1 && ptr2)
	{
		if (count % 2 == 0)
		{
			ptr->next = new Node(ptr1->data);
			ptr1 = ptr1->next;
		}
		else 
		{
			ptr->next = new Node(ptr2->data);
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
		count++;
	}
	

	while (ptr1)
	{
		ptr->next = new Node(ptr1->data);
		ptr1 = ptr1->next;
		ptr = ptr->next;
	}
	while (ptr2)
	{
		ptr->next = new Node(ptr2->data);
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}

	return head;
}

Node* mergeNEW(Node* head1, Node* head2)
{
	if (head1 == NULL && head2 == NULL)
		return NULL;
	Node* ptr1 = head1; Node* ptr2 = head2; Node* head = NULL; Node* ptr = NULL;
	// cases for copying JUST THE FIRST GUY
	if (head1 == NULL) 	
	{
		head = new Node(head2->data); 
		ptr2 = ptr2->next;
		ptr = head;
	}
	else if (head2 == NULL)
	{
		head = new Node(head1->data);
		ptr1 = ptr1->next;
		ptr = head;
	}
	else 
	{
		if (head1->data < head2->data)
		{
			head = new Node(head1->data);
			ptr1 = ptr1->next;
			ptr = head;
		}
		else
		{
			head = new Node(head2->data); 
			ptr2 = ptr2->next;
			ptr = head;

		}

	}

	while (ptr1 && ptr2)
	{
		if (ptr1->data < ptr2->data)
		{
			ptr->next = new Node(ptr1->data);
			ptr1 = ptr1->next;
			ptr = ptr->next;
		}
		else
		{
			ptr->next = new Node(ptr2->data);
			ptr2 = ptr2->next;
			ptr = ptr->next;

		}
	}

	while (ptr1)
	{
		ptr->next = new Node(ptr1->data);
		ptr1 = ptr1->next;
		ptr = ptr->next;

	}

	while (ptr2)
	{
		ptr->next = new Node(ptr2->data);
		ptr2 = ptr2->next;
		ptr = ptr->next;
	}
	return head;

}

Node* mergeNONEW(Node* head1, Node* head2)
{
	Node* head = NULL;
	Node* ptr = NULL;
	Node* ptr1 = head1; // effectively tail 
	Node* ptr2 = head2;

	while (ptr1 && ptr2)
	{
		if (ptr1->data < ptr2->data)
		{
			if (head == NULL)
			{
				head = ptr1;
				ptr = head;
				ptr1 = ptr1->next;
			}
			else
			{
				ptr->next = ptr1;
				ptr = ptr->next;
				ptr1 = ptr1->next;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = ptr2;
				ptr = head;
				ptr2 = ptr2->next;// BUG ptr2 = ptr1->next;
			}
			else
			{
				ptr->next = ptr2;
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}

		}
	}

	if (ptr1 )
	{
		if (head == NULL)
		{
			head = ptr1;
		}
		else
		{
			ptr->next = ptr1;
		}

	}

	if (ptr2 )
	{
		if (head == NULL)
		{
			head = ptr2;
		}
		else
		{
			ptr->next = ptr2;
		}

	}	
	return head;

}

Node* merge(Node *head1, Node *head2) {
  	Node* head = NULL;
	Node* ptr = NULL;
	Node* ptr1 = head1; // effectively tail 
	Node* ptr2 = head2;

	while (ptr1 && ptr2)
	{
		if (ptr1->data < ptr2->data)
		{
			if (head == NULL)
			{
				head = ptr1;
				ptr = head;
				ptr1 = ptr1->next;
			}
			else
			{
				ptr->next = ptr1;
				ptr = ptr->next;
				ptr1 = ptr1->next;
			}
		}
		else
		{
			if (head == NULL)
			{
				head = ptr2;
				ptr = head;
				ptr2 = ptr2->next;
			}
			else
			{
				ptr->next = ptr2;
				ptr = ptr->next;
				ptr2 = ptr2->next;
			}

		}
	}

	if (ptr1 )
	{
		if (head == NULL)
		{
			head = ptr1;
		}
		else
		{
			ptr->next = ptr1;
		}

	}

	if (ptr2 )
	{
		if (head == NULL)
		{
			head = ptr2;
		}
		else
		{
			ptr->next = ptr2;
		}

	}	
	return head;

    
}

Node* midpoint(Node *head)
{
	if (head == NULL)
      return NULL;
  	if (head->next == NULL)
      return head;
  
  	Node* slowptr = head;
  	Node* fastptr = head->next;
  	for (; fastptr && fastptr->next; slowptr=slowptr->next, fastptr=fastptr->next->next);
  	return slowptr;
}


Node* mergeSort(Node *head) {
    //write your code here
	if (head == NULL || head->next == NULL)
      return head;
  	Node* leftHead = head;
  
  	Node* mid = midpoint(head);
  	Node* rightHead = mid->next;
  	mid->next = NULL;
  
  	leftHead = mergeSort(leftHead);
  	rightHead = mergeSort(rightHead);
  	head = merge(leftHead, rightHead);
  	return head;
  	
}


Node* insertSorted(Node* head, int item)
{
	Node* newptr = new Node(item);
	if (head == NULL)
	{
		head = newptr;
	}
	else if (item <= head->data )
	{
		newptr->next = head;
		head = newptr;
	}
	else
	{
		Node* ptr;
		for (ptr = head; ptr->next && ptr->next->data < item; ptr=ptr->next);
		newptr->next = ptr->next;
		ptr->next = newptr;
	}
	return head;
}

Node* deleteAlternateNodes(Node* head)
{

  if (head == NULL)
    return head;
  else
  {
    Node* ptr;
    for (ptr = head; ptr!= NULL && ptr->next != NULL; ptr=ptr->next)
    {
      Node* tmp = ptr->next;
      ptr->next = tmp->next;
      delete tmp;
    }

  }
  return head;
  /*
	if (head == NULL || head->next == NULL)
		return head;
	Node* temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		Node* ptr = temp->next;
		temp->next = ptr->next;
		delete ptr;
		temp = temp->next;
	}
  	return head;
  	*/
}

//---------- 

bool find(Node* head, int item)
{
	if (head == NULL)
		return false;
	if (head->data == item)
		return true;
	return find(head->next, item);
}

Node* findUnion(Node* head1, Node* head2)
{
	// copy one into the other
	Node* head = NULL;
	Node* ptr = NULL;
	for (Node* curr = head1; curr; curr = curr->next)
	{
		if (!head)
		{
			head = new Node(curr->data);
			ptr = head;
		}
		else
		{
			ptr->next = new Node(curr->data);
			ptr = ptr->next;
		}
	}

	for (Node* curr = head2; curr; curr = curr->next)
	{
		if (!find(head1, curr->data))
		{
			if (!head)
			{
				head = new Node(curr->data);
				ptr = head;
			}
			else
			{
				ptr->next = new Node(curr->data);
				ptr = ptr->next;
			}
		}
	}
	return head;


}

Node * findIntersection(Node * head1, Node * head2)
{
    // code here
    //head1 = removeDup(head1);
    //head2 = removeDup(head2);
    Node * head = NULL;
    Node * ptr = NULL;
    for (Node * curr = head2; curr ; curr = curr->next)
    {
        if (find(head1, curr->data))
        {
            Node* newptr = new Node(curr->data);
            if (head == NULL)
            {
                head = newptr;
                ptr = head;
            }
            else
            {
                ptr->next = newptr;
                ptr = ptr->next;
            }
        }
    }
    return head;
}

Node* reverse_sub(Node* head, int k)
{
	int count = 0;
	Node* a = NULL;
	Node* b = NULL;
	Node* c = head;

	while(c!= NULL && count != k)
	{
		a = b;
		b = c;
		c = c->next;

		count++;
	}

	return head;

}

Node* reverse_k(Node* head, int k);
{
	int count = 0;
	Node* a = NULL;
	Node* b = NULL;
	Node* c = head;

	while (true)
	{ // TODO reverse_sub
		if (count == k)
			count = 0;
		head->next = c;
		head = b;
		// 1 2 3 // 3 2 1
		// 1 2 3 4 5 6 // 3 2 1 6 5 4 

		if (c == NULL)
			return head;
	}
}

int main()
{
	Node* head1 = takeInput();
	traverse(head1);
	/*
	traverse(head);
	Node* head2 = copy(head);
	traverse(head2);
	Node* head3 = reverse(head);
	traverse(head3);
	*/
	//if (isPalindrome(head))
	//	cout << "YES PALINDROME!" << endl;
	//else 
	//	cout << "NOT A PALINDROME" << endl;

	//head = deleteDuplicates(head);
	//traverse(head);

	//head = deletePrimes(head);
	//traverse(head);
 
	// Node* head2 = reverse(copy(head));
	/*
	Node* head2 =  takeInput();
	traverse(head2);
	Node* head3 = mergeNEW(head, head2);
	traverse(head3);

	Node* head4 = mergeNONEW(head, head2);
	traverse(head4);
	*/
	//head = insertSorted(head, 5);

	//head = mergeSort(head);
	//traverse(head);

	//Node* head2 = deleteAlternateNodes(head);

	// traverse(head2);

	Node* head2 = takeInput();
	Node* head3 = findUnion(head1, head2);
	Node* head4 = findIntersection(head1, head2);

	traverse(head2);
	traverse(head3);
	traverse(head4);
	cout << "Enter k: ";
	cin >> k;
	reverse_k(head, k);

}
