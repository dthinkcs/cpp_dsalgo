// ADDED LEVELWISE OUTPUT
#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

void printTreeLevelWise(TreeNode<int>* root)
{
    if (root == NULL) // edge case
        return;



    // 1: 2 3 4
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
        cout << root->children[i]->data << " ";
    cout << endl;



    queue<TreeNode<int>*> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int>* front = q.front();
        q.pop();

        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ":";
            for (int j = 0; j < front->children[i]->children.size(); j++)
                cout << front->children[i]->children[j]->data << " ";
            cout << endl;

            q.push(front->children[i]);
        }

    }
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

TreeNode<int>* takeInputLevelWise()
{
    int rootData; cout << "Enter root data: " << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> q;
    q.push(root);

    while (q.size() != 0)
    {
        TreeNode<int>* front = q.front();
        q.pop();

        int numChild; cout << "Enter number of chilren of " << front->data << endl;
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData; cout << "Enter "<< i << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* childptr = new TreeNode<int>(childData);
            front->children.push_back(childptr);
            q.push(childptr);
        }
    }

    return root;
}



int main()
{
    TreeNode<int>* root = takeInputLevelWise();
    printTreeLevelWise(root);
}

