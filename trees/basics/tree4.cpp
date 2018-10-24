// add level wise input
#include <iostream>
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise()
{
    int rootData;
    cout << "Enter data: " << endl;
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);
    // NOW PUT IT(root && its children) IN QUEUE
    queue<TreeNode<int>*> q;
    q.push(root);
    while (q.size() != 0)
    {
        TreeNode<int>* front = q.front();
        q.pop();

        cout << "Enter num of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData; cout << "Enter " << i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            q.push(child);
        }
    }
    return root; // IMPORTANT STEP

}


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
    TreeNode<int>* root = takeInputLevelWise();
    printTree(root);

    // TODO delete the tree

}

