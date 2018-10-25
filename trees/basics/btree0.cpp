#include <iostream>
#include <cmath>
#include <queue>
#include <bits/stdc++.h> 
using namespace std;

class BTNode
{
public:
	int data;
	BTNode* left;
	BTNode* right;

	BTNode(int data)
	{
		this->data = data;
		left = right = NULL;
	}
	~BTNode()
	{
		delete left;
		delete right;
	}
};


int getInt(const char* s)
{
	int data; 
	cout << s;
	cin >> data;
	return data;
}

// 3
// Test Input: 1 2 3 4 5 8 -1 -1 6 7 -1 -1 
// Input Test Case: 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
BTNode* takeInputLevelWise()
{
	int rootData = getInt("Enter root data(-1 for no data):\n ");
	if (rootData == -1)
		return NULL;

	BTNode* root = new BTNode(rootData);
	queue<BTNode*> q; // queue of BTNode* (NOT ints or floats)
	q.push(root); // enqueue to the rear of the queue
	while (q.size() != 0) // while q is not empty
	{
		// dequeue from the front of the queue
		BTNode* frontNode = q.front(); 
		q.pop();

		int leftChildData = getInt("Enter left child data(-1 for no data):\n");
		if (leftChildData != -1)
		{
			frontNode->left = new BTNode(leftChildData);
			q.push(frontNode->left);
		}
		int rightChildData = getInt("Enter right child data(-1 for no data):\n");
		if (rightChildData != -1)
		{
			frontNode->right = new BTNode(rightChildData);
			q.push(frontNode->right);
		}
	}
	return root;
}

// 2
BTNode* takeInput()
{
	int rootData = getInt("Enter data(-1 for no data): ");
	if (rootData == -1)
		return NULL;

	BTNode* root = new BTNode(rootData);
	root->left = takeInput();
	root->right = takeInput();
	return root; // BIT:: YOU FORGOT THIS but compiler made somehow corrected this

}


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

/* print the current node 
* then, print the left subtree
* then, print the right subtree
*/
void printTree(BTNode* root)
{
	if (root == NULL)
		return;


	coutPattern(root);  

	printTree(root->left);

	printTree(root->right); 
}

// Input Test Case: 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
void printTreeLevelWise(BTNode* root)
{
	if (root == NULL)
		return;
	
	coutPattern(root); //cout << root->data;
	queue<BTNode*> q;
	q.push(root);

	while (q.size() != 0)
	{
		BTNode* frontNode = q.front();
		q.pop();

		if (frontNode->left != NULL)
		{
			coutPattern(frontNode->left);
			q.push(frontNode->left);
		}
		if (frontNode->right != NULL)
		{
			coutPattern(frontNode->right);
			q.push(frontNode->right);
		}
	}
}

void preorder(BTNode* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}


void postorder(BTNode* root)
{
	if (root == NULL)
		return;

	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
} 

void inorder(BTNode* root)
{
	if (root == NULL)
		return;

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
} 

void prepostorder(BTNode* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	prepostorder(root->left);
	prepostorder(root->right);
	cout << root->data << " ";
}


void coutLevelData(int data, int level)
{
	for (int i = 0; i < level; i++)
		cout << "\t";
	cout << data << endl;
}

// base case: print nothing if root is null
// IHOP:
// print right tree (with (level + 1) spaces)
// cout myself (with level spaces)
// print left tree (with (level + 1) spaces)
void printHorizontallyHelper(BTNode* root, int level)
{
	if (root == NULL)
		return;

	printHorizontallyHelper(root->right, level + 1);
	coutLevelData(root->data, level);
	printHorizontallyHelper(root->left, level + 1);

		
}

void printHorizontally(BTNode* root)
{
	printHorizontallyHelper(root, 0);
}
//----------------------------------------------

// base case: root is NULL then do nothing and return
// IHOP etall:
// print myself with levels
// print left with level+1 spaces an
// need this for printVertically
int numOfLevels(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + max(numOfLevels(root->left), numOfLevels(root->right));
}
/*
void printVeritically(BTNode* root)
{
	if (root == NULL)
		return;
	int total_levels = numOfLevels(root); 

	for (int i = 0; i < total_levels; i+)
		cout << "\t";
	cout << root->data;

	cout << endl;
	
	// NOT GONNA WORK WITHOUT SOME LEVEL TRICKERY
	// Trick: Assume level increases only after FULL BINARY TREE
	// OR 
	// Print Level Order Wise AND SOMEHOW know when to press Enter
	// coz the queue keeps on forgetting where something came from 
	queue<BTNode*> q;
	q.push(root);

	while (q.size() != 0)
	{
		BTNode* frontNode = q.front();
		q.pop();

		if (frontNode->left != NULL)
		{
			coutPattern(frontNode->left);
			q.push(frontNode->left);
		}
		if (frontNode->right != NULL)
		{
			coutPattern(frontNode->right);
			q.push(frontNode->right);
		}
	}		
}
*/

int numOfNodes(BTNode* root)
{
	if (root == NULL)
		return 0;

	return 1 + numOfNodes(root->left) + numOfNodes(root->right);
}

int numOfLeaves(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return numOfLeaves(root->left) + numOfLeaves(root->right);
}

bool find(BTNode* root, int item)
{
	if (root == NULL)
		return false;

	if (root->data == item)
		return true;

	return find(root->left, item) || find(root->right, item); 
}

int getSumNodes(BTNode* root)
{
	if (root == NULL)
		return 0;

	return root->data + getSumNodes(root->left) + getSumNodes(root->right);
}


int getNumOfNonLeafNodes(BTNode* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 0;

	//f (root->one of them != NULL )
	return 1 + getNumOfNonLeafNodes(root->left) + getNumOfNonLeafNodes(root->right);
}


int getMinValue(BTNode* root)
{
	if (root == NULL)
		return INT_MAX;

	return min(root->data, min(getMinValue(root->left), getMinValue(root->right)));
}

int getMaxValue(BTNode* root)
{
	if (root == NULL)
		return INT_MIN;

	return max(root->data, max(getMaxValue(root->left), getMaxValue(root->right)));
}

// can be optimized later by returning pair of int like going down the lift with bucket and filling the water bottles while laudry is been done
int getDiameter(BTNode* root)
{
	if (root == NULL)
		return 0;

	return max(numOfLevels(root->left)+numOfLevels(root->right),  max(getDiameter(root->left), getDiameter(root->right)));
}

void printNodesLevelKBUGGY(BTNode* root, int k)
{
	if (root == NULL)
		return;

	if (k <= 1) // considering level starts from level 1
		cout << root->data;

	printNodesLevelKBUGGY(root->left, k - 1);
	printNodesLevelKBUGGY(root->right, k - 1);

}

void printNodesLevelK(BTNode* root, int k)
{
	if (root == NULL)
		return;

	if (k <= 1) // considering level starts from level 1
	{
		cout << root->data;
		return; // IMPORTANT STEP
	}

	printNodesLevelK(root->left, k - 1);
	printNodesLevelK(root->right, k - 1);

}


int main()
{
	/*
	BTNode* root = new BTNode(10);
	BTNode* node1 = new BTNode(20);
	BTNode* node2 = new BTNode(30);

	root->left = node1;
	root->right = node2;
	*/
	// Input Test Case: 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1

	BTNode* root = takeInputLevelWise();

	printTreeLevelWise(root);
	printHorizontally(root);
	// TODO printVertically you need depth/total_levels of a tree
	// TODO createTreetakeInputString
	// TODO createTreeInPreArray
	// TODO preorder2, inorder2, postorder2
	// TODO ancestorsOfgivenElement
	// BTNode* inorderSuccessor(BTNode* root);
	// BTNode* parent
	// TODO areEqual(BTNode* root1, BTNode* root2)
	// TOOD areMirrorImages(BTNode* root1, BTNode* root2)
	// TOOD copyIntoAnother(BTNode* rootSource, BTNode* rootDestination)
	// TODO createExpTreeFromPostfix(char* postfix)	and evaluate(BTNode* rootExpTree)
	// TODO BST: insert, delete, search, traverse(inorder===ascending), findMin, findMax
	// TODO TBT: insert, delete, traverse, in_order_succ, in_oder_pre, POST_ _, PRE _ _
	// TODO: GFG

	cout << "PREORDER:" << endl;
	preorder(root); 
	cout << endl;
	cout << "INORDER:" << endl;
	inorder(root); 
	cout << endl;
	cout << "POSTORDER:" << endl;
	postorder(root); 
	cout << endl<<endl;


	cout << "Number of Levels(depth of the tree): " << numOfLevels(root) << endl; 
	cout << "Number of Nodes: " << numOfNodes(root) << endl; 
	cout << "Number of Leaf Nodes: " << numOfLeaves(root) << endl;
	//cout << "Sum of Nodes: " << 
	int item = getInt("Enter Item To be Searched: ");
	cout << (find(root, item) ? "Found" : "Cound Not Find") << item <<  endl;



}
