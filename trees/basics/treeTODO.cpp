#include <iostream>
using namespace std;

class BTNode
{
	int data;
	BTNode* left;
	BTNode* right;

	BTNode(int d)
	{
		data = d;
		left = NULL;
		rihgt = NULL;
	}
};

// create bt u
BTNode* createBT()
{
	int rootData; cout << "Enter root data (-1 to exit): ";
	cin >> rootData;
	if (rootData == -1)
		return NULL;

	BTNode* root = new BTNode(rootData);
	root->left = createBT();
	root->right = createBT();

}

// print bt
void printBT(BTNode* root)
{
	if (root == NULL)
		return;

	cout << root->data << endl;
	printBT(root->left);
	printBT(root->right);
}
