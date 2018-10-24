// ADD LEVELWISE OUTPUT
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"
using namespace std;

void postorder(TreeNode<int>* root)
{
    if (root == NULL)
        return;


    for (int i = 0; i < root->children.size(); i++)
        postorder(root->children[i]);
    cout << root->data;
}

void preorder(TreeNode<int>* root)
{
    if (root == NULL)
        return;

    cout << root->data;
    for (int i = 0; i < root->children.size(); i++)
        preorder(root->children[i]);
}

int numOfLeafNodes(TreeNode<int>* root)
{
    if (root == NULL)
        return 0;
    // ask every child tum bata do
    if (root->children.size() == 0)
        return 1;
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++ )
        ans += numOfLeafNodes(root->children[i]);
    return ans;

}

//    1
// 2  3  4
//   5 6

void printAtLevelK(TreeNode<int>* root, int k)
{
    // root-> gives TENSION
    // therefore edge case
    if (root == NULL)
        return;

    if (k == 0)
    {
        cout << root->data << "\t";
        return;
    }

    // CRUX: DELEGATE UNTIL YOU REACH k = 0
    for (int i = 0; i < root->children.size(); i++)
        printAtLevelK(root->children[i], k - 1);
}

/*
int height(TreeNode<int>* root)
{
    // return 1 + max(ofallthechildrem)
    vector<int> ansChild;
    ansChild.push_back(0);
    for (int i = 0; i < root->children.size(); i++)
        ansChild.push_back(height(root->children[i]));
    int* ansChildArr = &ansChild[0];

    return 1 + max_element(ansChildArr);
}
*/

int numNodes(TreeNode<int>* root)
{
    // 1 + numNodes(remainingchild)
    if (root == NULL)
        return 0;
    int numChildren = 0;


    for (int i = 0; i < root->children.size(); i++)
        numChildren += numNodes(root->children[i]);

    return 1 + numChildren;
}

int numNodes2(TreeNode<int>* root)
{
    // 1 + numNodes(remainingchild)
    if (root == NULL)
        return 0;
    int num = 1;

    for (int i = 0; i < root->children.size(); i++)
        num += numNodes(root->children[i]);

    return num;
}

int sumNodes(TreeNode<int>* root)
{
    // 1 + numNodes(remainingchild)
    if (root == NULL)
        return 0;

    int sumChildren = 0;

    for (int i = 0; i < root->children.size(); i++)
        sumChildren += sumNodes(root->children[i]); // RECURSE ON POINTERS NOT INTS sumNodes(root->children[i]->data);

    return root->data + sumChildren;
}

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
            // print the ith child
            cout << front->children[i]->data << ":";
            for (int j = 0; j < front->children[i]->children.size(); j++)
                cout << front->children[i]->children[j]->data << " ";
            cout << endl;

            // push th
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
    cout << numNodes(root);
    cout << sumNodes(root);
    cout << numOfLeafNodes(root);
}

