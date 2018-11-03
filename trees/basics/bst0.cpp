#include <iostream>
#include <queue>
using namespace std;

class BSTNode
{
public:
	int data;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int d)
	{
		data = d;
		left = right = NULL;
	}
};

int getInt(const char* s)
{
	int data;
	cout << s;
	cin >> data;
	return data;
}

/*
* searches for integer called item in BST
*/
BSTNode* searchBST(BSTNode* root, int item)
{
	if (root == NULL)
		return NULL;
	if (root->data == item)
		return root;
	else if (root->data < item)
		return searchBST(root->right, item);
	else
		return searchBST(root->left, item);
}

/*
* deletes a Node from a BST if it exists
*/
BSTNode* deleteNodeBST(BSTNode* root, int item)
{
	if (root == NULL)
	{
		return;
	}


	// find the currNode, parentNode, ptr
	BSTNode *curr, *par;
	curr = par = NULL;
	for (BSTNode* ptr = root; ptr; )
	{
		if (ptr->data == item)
		{
			curr = ptr;
			break;
		}
		par = ptr;
		if (item < ptr->data)
			ptr = ptr->left;
		else
			ptr = ptr->left;
	}

	if (curr == NULL)
		return;

	// deg(curr) is 2
	if (curr->left != NULL && curr->right != NULL)
	{
		par = curr;
		// succ = inorderSucc(curr);
		succ = curr->right;
		while (succ->left != NULL)
		{
			par = succ;
			succ = succ->left;
		}
		curr->data = succ->data; // overwrite succ with curr data
		curr = succ; // curr thing to be deleted is succ LAST LINE
	}

	// deg(curr) is 0 then set parent's left/right to NULL
	if (par != NULL)
	{
		if (curr->left == NULL && curr->right == NULL)
		{
			if (par->left == curr)
				par->left = NULL;
			else
				par->right = NULL;
		}

		// deg(curr) is 1 (left) then set parent's left/right to curr(left since it exists)
		if (curr->left != NULL && curr->right == NULL)
			if (par->left == curr)
				par->left = curr->left;
			else
				par->right = curr->left;

		// deg(curr) is 1 (right) then set parent's left/right to curr(right since it exists)
		if (curr->left == NULL && curr->right != NULL)
			if (par->left == curr)
				par->left = curr->right;
			else
				par->right = curr->right;
	}

	delete curr;

}


/*
* prints node and its left and right child if they exist
*/
void coutPattern(BTNode* nodeptr)
{
	// edge case
	if (nodeptr == NULL)
		return;

	cout << nodeptr->data << ":";
	if (nodeptr->left != NULL)
		cout << "L" << nodeptr->left->data;
	if (nodeptr->right != NULL)
		cout << "R" << nodeptr->right->data;
	cout << endl;
}



/*
* traverse BST level order
*/
void traverseBSTLevelOrder(BSTNode* root)
{
	if (root == NULL)
		return;

	queue<BSTNode*> q;

	coutPattern(root);
	q.push(root);

	while (!q.empty())
	{
		BSTNode* frontNode = q.front();
		q.pop();

		if (frontNode->left != NULL)
		{
			coutPattern(frontNode->left);
			q.push(frontNode->left);
		}
		// same
		if (frontNode->right != NULL)
		{
			coutPattern(frontNode->right);
			q.push(frontNode->right);
		}

	}

}


/*
* traverse BST inorder
*/
void traverseBST(BSTNode* root)
{
	if (root == NULL)
		return;

	traverseBST(root->left);
	coutPattern(root); // cout << root->data;
	traverseBST(root->right);
}

/*
* inserts a node into the BST provided
*/
BSTNode* insertNode(BSTNode* root, int item)
{
	if (root == NULL)
	{
		root = new BSTNode(item);
	}
	else
	{
		if (root->data < item)
			root->right = insertNode(root->right, item);
		else (root->data > item)
			root->left = insertNode(root->left, item);
		else
			cout << "Cannot repeat elements" << endl;
	}
	return root;
}

/*
* takes input from the user
*/
BSTNode* takeInput()
{

	BSTNode* root = NULL;
	while (true)
	{
		int nodeData = getInt("Enter data(-1 to stop): \n");
		if (nodeData == -1)
		{
			break;
		}
		else
		{
			root = insertNode(root, nodeData);
		}
	}
	return root;

}

void printHorizontallyHelper(BTNode* root, int level)
{
	if (root == NULL)
		return;

	printHorizontallyHelper(root->right, level + 1);
	coutLevelData(root->data, level);
	printHorizontallyHelper(root->left, level + 1);


}

void printTree(BTNode* root)
{
	printHorizontallyHelper(root, 0);
}


int main()
{
	BSTNode* root = takeInput();
	printTree(root);
}
