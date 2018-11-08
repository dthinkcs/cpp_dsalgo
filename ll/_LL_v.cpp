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
				ptr2 = ptr1->next;
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


int main()
{
	Node* head = takeInput();
	traverse(head);
	/*
	traverse(head);
	Node* head2 = copy(head);
	traverse(head2);
	Node* head3 = reverse(head);
	traverse(head3);
	*/
	if (isPalindrome(head))
		cout << "YES PALINDROME!" << endl;
	else 
		cout << "NOT A PALINDROME" << endl;

	//head = deleteDuplicates(head);
	//traverse(head);

	//head = deletePrimes(head);
	//traverse(head);
 
	// Node* head2 = reverse(copy(head));
	Node* head2 =  takeInput();
	traverse(head2);
	Node* head3 = mergeNEW(head, head2);
	traverse(head3);

	Node* head4 = mergeNONEW(head, head2);
	traverse(head4);
}
