#include <iostream>
#include <cmath> // min, max
#include <cctype> // tolower
#include <queue> 
#include <stack>
#include <bits/stdc++.h> // INT_MAX/MIN
#define MAX 50
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

BTNode* createTreeArrHelper(int* in, int* pre, int inS, int inE, int preS, int preE)
{
	if (inS > inE)
		return NULL;

	// find out where root is in InOrder
	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++)
	{
		if (in[i] == rootData) // rootData = pre[preS]
		{
			rootIndex = i;
			break; // IMPORTANT STEP in NON return code NON functional code;
		}

	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int rInS = rootIndex + 1;
	int rInE = inE;

	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS; // lInE - lInS + preS + 1;
	int rPreS = lPreE + 1;
	int rPreE = preE;

	BTNode* root = new BTNode(rootData);	// IMPORTANT induction step
	root->left = createTreeArrHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = createTreeArrHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root; // IMPORTANT induction step

}
// TESTED CASES: 1 int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7}; int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
BTNode* createTreeInPreArray(int* in, int* pre, int size)
{
	return createTreeArrHelper( in, pre, 0, size - 1, 0, size - 1);
}



bool areEqual(BTNode* root1, BTNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data) && areEqual(root1->left, root2->left) && areEqual(root1->right, root2->right);
}

bool areMirrorImages(BTNode* root1, BTNode* root2)
{
	if (root1 == NULL && root2 == NULL)
		return true;
	if (root1 == NULL || root2 == NULL)
		return false;

	return (root1->data == root2->data) && areMirrorImages(root1->left, root2->right) && areEqual(root1->right, root2->left);
	/*
	if (root1->data == root->data) && areMirrorImages(roo1->left, root2->right) && areEqual(root1->right, root2->left)
		return true;
	else
		return false;
		*/
}

BTNode* copyIntoAnother(BTNode* rootSource)
{
	if (rootSource == NULL)
		return NULL;

	BTNode* rootCopy = new BTNode(rootSource->data); // copy root
	rootCopy->left = copyIntoAnother(rootSource->left); // copy left
	rootCopy->right = copyIntoAnother(rootSource->right); // copy right
	return rootCopy; // new
}

void printTreeLevelWiseBST(BTNode* root) // same as BT
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



BTNode* createTreetakeInputString(int item, BTNode* root)
{
	BTNode* temp = new BTNode(item);
	if (root == NULL)
		return temp;

	char dir[MAX]; cout << "Give Direction to insert: ";
	cin >> dir;

	BTNode* prev = NULL;
	BTNode* curr = root;
	int i, len;
	for (i = 0, len = strlen(dir); i < len; i++)
	{
		if (curr == NULL)
			break;
		prev = curr;
		if (tolower(dir[i]) == 'l')
			curr = curr->left;
		else
			curr = curr->right;
	}
	if (tolower(dir[i - 1]) == 'l')
		prev->left = temp;
	else
		prev->right = temp;
	return root;
}

// TODO preorder2, inorder2, postorder2
// Iterative function to perform post-order traversal of the tree
void postorderIterative(BTNode* root)
{
	// create an empty stack and push root node
	stack<BTNode*> stk;
	stk.push(root);

	// create another stack to store post-order traversal
	stack<int> out; // integer stack for outputting

	// run till stack is not empty
	while (!stk.empty())
	{
		// we pop a node from the stack and push the data to output stack
		BTNode *curr = stk.top();
		stk.pop();

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

void preorderIterative(BTNode* root)
{
	BTNode* curr = root;
	BTNode* s[MAX]; int t = -1;
	while (true)
	{
		for (; curr != NULL; curr = curr->left)
		{
			cout << curr->data << " ";
			s[++t] = curr;
 		}

 		if (t != -1) // stack is NOT empty
 		{
 			curr = s[t--]; // curr = pop()
 			curr = curr->right;
 		}
 		else
 			return;
	}
}

void inorderIterative(BTNode* root)
{
	BTNode* curr = root;
	BTNode* s[MAX]; int t = -1;
	while (true)
	{
		for (; curr != NULL; curr = curr->left)
		{
			
			s[++t] = curr;
 		}

 		if (t != -1) // stack is NOT empty
 		{
 			curr = s[t--]; // curr = pop()
 			cout << curr->data << " "; // before going into right subtree print the node
 			curr = curr->right;
 		}
 		else
 			return;
	}
}

// Recursive function to print all ancestors of given node in a 
// binary tree. The function returns true if node is found in 
// subtree rooted at given root node
bool printAncestors(BTNode *root, int item)
{
    // base case
	if (root == NULL)
		return false;

    // return true if given node is found
	if (root->data == item)
		return true;

    // search node in left subtree
	bool left = printAncestors(root->left, item);

    // search node in right subtree if left subtree returns false
	bool right = false;
	if (!left)
		right = printAncestors(root->right, item);

	// if given node is found in either left or right subtree,
	// current node is an ancestor of given node
	if (left || right)
		cout << root->data << " ";

    // return true if node is found
	return left || right;
}

int findParent(BTNode* root, int item)
{
	if (root == NULL)
		return INT_MIN; // couldnt find parent;
	if (root->left != NULL) 
	{
		if (root->left->data == item)
			return root->data;
	}
	if (root->right != NULL)
	{
		if (root->right->data == item)
			return root->data;
	}
	//if (root->left->data == item || root->right->data == item)
	//	return root->data;//return root;
	
	
	int leftValue = findParent(root->left, item);
	int rightValue = findParent(root->right, item);
	
	if (leftValue == INT_MIN && rightValue == INT_MIN)
		return INT_MIN;
	else if (leftValue != INT_MIN)
		return leftValue;
	else 
		return rightValue;
}

BTNode* findParent2(BTNode* root, int item)
{
	if (root == NULL)
		return NULL;
	if (root->left != NULL)
	{
		if (root->left->data == item)
			return root;
	}
	if (root->right != NULL)
	{
		if (root->right->data == item)
			return root;
	}

	BTNode* leftIncoming = findParent2(root->left, item);
	BTNode* rightIncoming = findParent2(root->right, item);
	if (leftIncoming == NULL && rightIncoming == NULL)
		return NULL;
	else if (leftIncoming != NULL)
		return leftIncoming;
	else 
		return rightIncoming;
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

	BTNode* root = takeInputLevelWise(); // 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
	//int in[] = {4, 2, 5, 1, 8, 6, 9, 3, 7}; // todo add skewness EXAMPLE
	//int pre[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};
	//BTNode* root = createTreeInPreArray(in, pre, 9);
	printTree(root);
	//printTreeLevelWise(root);
	// printVertically you need depth/total_levels of a tree
	printHorizontally(root);

	// TODO createExpTreeFromPostfix(char* postfix)	and prefix and then evaluate(BTNode* rootExpTree)
	// TODO BST: insert, delete, search, traverse(inorder===ascending), findMin, findMax
	// TODO TBT: insert, delete, traverse, in_order_succ, in_oder_pre, POST_ _, PRE _ _
	// TODO: GFG BTNode* inorderSuccessor(BTNode* root);

	cout << "PREORDER:" << endl; // {4, 2, 5, 1, 8, 6, 9, 3, 7}
	preorderIterative(root); 
	cout << endl;
	cout << "INORDER:" << endl; // {1, 2, 4, 5, 3, 6, 8, 9, 7}
	inorderIterative(root); 
	cout << endl;
	cout << "POSTORDER:" << endl; // 4 5 2 8 9 6 7 3 1
	postorderIterative(root); 
	cout << endl<<endl;


	cout << "Number of Levels(depth of the tree): " << numOfLevels(root) << endl; 
	cout << "Number of Nodes: " << numOfNodes(root) << endl; 
	cout << "Number of Leaf Nodes: " << numOfLeaves(root) << endl;
	//cout << "Sum of Nodes: " << 
	//int item = getInt("Enter Item To be Searched: ");
	int item = 10;
	cout << (find(root, item) ? "Found" : "Cound Not Find") << item <<  endl;
	int item2 = getInt("Enter Child Value: ");
	int val = findParent(root, item2);
	BTNode* parent = findParent2(root, item2);
	if (val != INT_MIN)
	{
		cout << "Parent of "<< item2 << " : " << val << endl;
		cout << "Parent of "<< item2 << " : " << parent->data << endl;
		printAncestors(root, item2);

	}
	else 
		cout << " Child NOT found" << endl; 


}