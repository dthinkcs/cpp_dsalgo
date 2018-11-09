#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
#define MAX 50
class BTNode
{
    public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode (int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};



bool isparentPrint(BTNode* root, int item)
{
  if (root == NULL)
    return false;

  if (root->data == item)
    return true;

   if (isparentPrint(root->left, item) || isparentPrint(root->right, item))
   {
      cout << root->data << endl;
      return false;
   }

   return false;
}

bool ancestorsPrint(BTNode* root, int item)
{
  if (root == NULL)
    return false;

  if (root->data == item)
    return true;

   if (ancestorsPrint(root->left, item) || ancestorsPrint(root->right, item))
   {
      cout << root->data << "\t";
      return true;
   }

   return false;
}

BTNode* takeInput()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    BTNode* root = new BTNode(data);
    root->left = takeInput();
    root->right = takeInput();
    return root;
}

BTNode* takeInputLevelWise()
{
    int data;
    cin >> data;
    if (data == -1)
        return NULL;
    BTNode* root = new BTNode(data);
    queue<BTNode*> q;
    q.push(root); // enqueue root
    while (q.size() != 0)
    {
        BTNode* frontNode = q.front(); q.pop();

        int leftData;
        cin >> leftData;
        if (leftData != -1)
        {
            frontNode->left = new BTNode(leftData);
            q.push(frontNode->left);
        }

        int rightData;
        cin >> rightData;
        if (rightData != -1)
        {
            frontNode->right = new BTNode(rightData);
            q.push(frontNode->right);
        }

    }

    return root;
}

void printLevelWise(BTNode* root)
{
    if (root == NULL)
        return;
    queue<BTNode*> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode* frontNode = q.front(); q.pop();
        cout << frontNode->data; // USE THE POPPED NODE

        if (frontNode->left)
        {
            q.push(frontNode->left);
        }
        if (frontNode->right)
        {
            q.push(frontNode->right);
        }

    }
}

void postorderIterative(BTNode* root)
{
    stack<BTNode*> s;
    stack<int> out;

    s.push(root);
    while (!s.empty())
    {
        BTNode* curr = s.top(); s.pop();
        out.push(curr->data);

        if (curr->left)
            s.push(curr->left);

        if (curr->right)
            s.push(curr->right);
    }

    while (!out.empty())
    {
        cout << out.top() << " "; out.pop();
    }
}

BTNode* createBT(BTNode* root, int item)
{
    // root NULL
    if (root == NULL)
    {
        BTNode* newptr = new BTNode(item);
        root = newptr;
        return root;
    }

    char dir[MAX];
    cout << "Enter direction: ";
    cin >> dir;
    int len = strlen(dir);
    BTNode* curr = root, * prev = NULL;
    int i;
    for ( i = 0; i < len; i++)
    {
        if (curr == NULL)
            break;
        if (dir[i] == 'L')
        {
            prev = curr;
            curr = curr->left;
        }
        else if (dir[i] == 'R')
        {
            prev = curr;
            curr = curr->right;
        }
    }

    if (!(i == len && curr == NULL))
    {
        cout << "Invalid" << endl;
        return root;
    }

    if (dir[i - 1] == 'L')
    {
        prev->left = new BTNode(item);;
    }
    else
    {
        prev->right = new BTNode(item);;
    }
    return root;
    // direct enter

    // dir

}

void printTreeH(BTNode* root, int level)
{
    if (root == NULL)
        return;
    printTreeH(root->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "\t";
    cout << root->data << endl;
    printTreeH(root->left, level + 1);
}

void printTree(BTNode* root)
{
    printTreeH(root, 0);
}


void preorderIterative(BTNode* root)
{
    BTNode* curr = root;
    stack<BTNode*> s;
    while (true)
    {
        for (; curr; curr=curr->left)
        {
            cout << curr->data;
            s.push(curr);
        }

        if (s.empty())
            break;

        curr = s.top(); s.pop();
        curr = curr ->right;
    }
}

void inorderIterative(BTNode* root)
{
    BTNode* curr = root;
    stack<BTNode*> s;
    while (true)
    {
        for (; curr; curr=curr->left)
        {

            s.push(curr);
        }

        if (s.empty())
            break;

        curr = s.top(); s.pop();
        cout << curr->data;
        curr = curr ->right;
    }
}

// Iterative function to perform post-order traversal of the tree
void postorderIterative2(BTNode* root)
{
	// create an empty stack and push root node
	stack<BTNode*> stk;
	stk.push(root);

	// create another stack to store post-order traversal
	stack<int> out;

	// run till stack is not empty
	while (!stk.empty())
	{
		// we pop a node from the stack and push the data to output stack
		BTNode *curr = stk.top(); stk.pop();

		out.push(curr->data);

		// push left and right child of popped node to the stack
		if (curr->left)
			stk.push(curr->left);

		if (curr->right)
			stk.push(curr->right);
	}

	// print post-order traversal
	while (!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}

BTNode* copy(BTNode* rootSource)
{
    if (rootSource == NULL)
        return NULL;
    BTNode* rootNew = new BTNode(rootSource->data);
    rootNew->left = copy(rootSource->left);
    rootNew->right = copy(rootSource->right);
    return rootNew;
}

BTNode* mirror(BTNode* rootSource)
{
    if (rootSource == NULL)
        return NULL;
    BTNode* rootNew = new BTNode(rootSource->data);
    rootNew->left = mirror(rootSource->right);
    rootNew->right = mirror(rootSource->left);
    return rootNew;
}

bool areEqual(BTNode* root1, BTNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) && areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}


bool areMirror(BTNode* root1, BTNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    return (root1->data == root2->data) && areEqual(root1->left, root2->right) && areEqual(root1->left, root2->right);
}

int minimum(BTNode* root)
{
    if (root == NULL)
        return INT_MAX;
    return min(root->data, min(minimum(root->left), minimum(root->right)));

}

int maximum(BTNode* root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->data, max(maximum(root->left), maximum(root->right)));

}

bool isBST(BTNode* root)
{
    if (root == NULL)
        return true;
    return (maximum(root->left) < root->data && root->data < minimum(root->right)) && isBST(root->left) && isBST(root->right);
}

// path()

int main()
{
    BTNode* root = takeInputLevelWise();  // 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
    // 1 2 5 3 -1 -1 -1 4 -1 -1 -1
    /*
    root = createBT(root, 1);
    root = createBT(root, 2);
    root = createBT(root, 3);
    root = createBT(root, 4);
    root = createBT(root, 5);
    root = createBT(root, 6);
    */

    printTree(root);

    cout << endl << endl << endl;
    printTree(mirror(root));
    cout << areEqual(copy(root), root) << endl;
    cout << areMirror(mirror(root), root) << endl;


    cout << "PREORDER:"; preorderIterative(root);
    cout << "INORDER:"; inorderIterative(root);
    cout << "POSTORDER:"; postorderIterative(root);
    cout << endl;
    isparentPrint(root, 3);
    ancestorsPrint(root, 3);
}
