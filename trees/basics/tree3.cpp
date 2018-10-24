#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num of children of " << rootData << endl;
    cin >> n; // 0 is the base case

    for (int i = 0; i < n; i++)  // 0 is the base case
    {
        TreeNode<int>* child = takeInput(); // return root;
        root->children.push_back(child);
    }

    return root;
}

void printTree(TreeNode<int>* root)
{
	// root ko print and then
	// DELEGATE print to others
	//if (root == NULL)
	//	return;
    //.size() is the base CASE!!! NO EXPLICIT BASE CASE

    // edge case if user enters NULL || NOTE: THIS IS NOT A BASE CASE its an edge case
    if (root == NULL)
        return;
	cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
        cout <<root->children[i]->data << " "; // NOTE:: NOT printTree ONLY cout WHICH MEANS INTERMEIDATE CHILDREN ONLY
    cout << endl;

	for (int i = 0; i < root->children.size(); i++)
		printTree(root->children[i]);
}

int main()
{

    /*TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);
    
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    TreeNode<int>* root = takeInput();
    printTree(root);

    // TODO delete the tree

}
