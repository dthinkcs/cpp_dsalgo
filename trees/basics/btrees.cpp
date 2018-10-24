#include<iostream>
using namespace std;

class Node
{
    public:
    char data;
    Node *lchild,*rchild;
};


class Tree
{
    Node *root;

    public:

    Tree()
    {
     root=NULL;
    }

    void createNode();
    void inorder();
    void inorderhelper(Node*);
    void inorder2();
    void postorder();
    void preorder();
    void getParent();
    void getDepth();
    void getAncestors();
    void getLeafNodeCount();
};

void Tree::createNode()
{
    Node *temp = new Node;
    Node *prev, *curr=root;

    cout << "Enter data: ";
    cin >> temp->data;
    temp->lchild = temp->rchild = NULL;

    if (root == NULL)
        root = temp;
    else
    {
        char dir[20];

        cout<<"Enter path: ";
        cin >> dir;
        int i;
        for(i = 0; dir[i] !='\0' && curr != NULL; i++)
        {
            prev=curr;
            if(dir[i] == 'L' || dir[i] == 'l')
                curr = curr->lchild;
            else
                curr = curr->rchild;
        }

        if ((curr == NULL) && dir[i] =='\0')
        {
            if(dir[i-1]=='L'||dir[i-1]=='l')
                prev->lchild = temp;
            else
                prev->rchild = temp;
        }
        else
        {
            cout<<"Not possible!";
        }
    }
}

void Tree::inorderhelper(Node* ptr)
{
    if (ptr == NULL)
        return;
    inorderhelper(ptr->lchild);
    cout << ptr->data;
    inorderhelper(ptr->rchild);

}


void Tree::inorder2()
{
    inorderhelper(root);
}


void Tree::inorder()
{
    Node *s[20], *curr;
    int top = -1;

    if(root == NULL)
        cout << "Tree EMPTY!";
    else
    {
        curr = root;
        while (true)
        {
            for (; curr; curr = curr->lchild)
            {
                s[++top]=curr;
            }

            if (top < 0)
            {
                break;
            }
            else
            {
                curr = s[top--];
                cout << curr->data;
                curr = curr->rchild;

            }

        }
    }

}

void Tree::preorder()
{

    Node *s[20], *curr;
    int top=-1;

    if(root==NULL) cout<<"Tree EMPTY!";

    else
    {
        while(true)
        {
            for(curr = root; curr != NULL; curr = curr->lchild)
            {
                cout<<curr->data;
                s[++top]=curr;
            }

            if(top < 0)
            {
                break;
            }
            else
            {
                curr = s[top--];
                curr = curr->rchild;

            }

        }
    }

}

/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
    a) Push root's right child and then root to stack.
    b) Set root as root's left child.
2.2 Pop an item from stack and set it as root.
    a) If the popped item has a right child and the right child
       is at top of stack, then remove the right child from stack,
       push the root back and set root as root's right child.
    b) Else print root's data and set root as NULL.
2.3 Repeat steps 2.1 and 2.2 while stack is not empty.
*/

void Tree::postorder()
{
    Node *s[20], *curr;
    int top=-1;

    if(root==NULL)
        cout<<"Tree EMPTY!";
    else
    {
        while(true)
        {
            for(curr = root; curr; curr = curr->lchild)
            {
                s[++top]=curr;
            }

            if(top < 0)
            {
                break;
            }
            else
            {
                curr=s[top--];
                cout<<curr->data;
                curr=curr->rchild;

            }

        }
    }
}

void Tree::getParent()
{
}
void Tree::getDepth()
{
}
void Tree::getAncestors()
{


}

void Tree::getLeafNodeCount()
{

}

int main()
{
 char ch;
 Tree t;
 do{

	cout<<"\t\t\tMENU***\n";
	cout<<"1. Add Node\n2. Inorder Traversal\n3. Postorder Traversal"
	    <<"\n4. Preorder Traversal\n5. Parent of a Node\n6. Depth"
	    <<"\n7. Ancestors of a Node\n8. Number of leaf Nodes";
	cout<<"\nEnter choice - ";
	cin >> ch;
	switch(ch)
	{
	 case '1': t.createNode();
               break;
	 case '2': t.inorder();	        
                break;
	 case '3': t.postorder();      
     break;
	 case '4': t.preorder();      break;
	 case '5': t.getParent();      break;
	 case '6': t.getDepth();        break;
	 case '7': t.getAncestors();     break;
	 case '8': t.getLeafNodeCount();
	}
  }
  while(ch!=27);
}
