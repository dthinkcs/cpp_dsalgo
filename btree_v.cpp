#include <iostream>
using namespace std;

class BTNode
{
public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode(int item)
    {
        data = item;
        left = right = NULL;
    }
};

void printTreeSimple(BTNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << endl;

    printTreeSimple(root->left);
    printTreeSimple(root->right);

}

// 10: L20 R30
void printTree(BTNode* root)
{
    if (root == NULL)
        return;

    cout << root->data << ":";

    if (root->left != NULL)
        cout << "L" << root->left->data << " ";
    if (root->right != NULL)
        cout << "R" << root->right->data;
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BTNode* takeInput()
{
    int input;
    cin >> input;
    if (input == -1)
        return NULL;
    BTNode* root = new BTNode(input);

    root->left = takeInput();
    root->right = takeInput();

    return root;
}

/*
BTNode* takeInputLEVELWISE()
{
    // TODO
*/

void preorder(BTNode* root)
{
  if (root==NULL)
    return;

  cout << root->data << "\t";
  preorder(root->left);
  preorder(root->right);

}

void inorder(BTNode* root)
{
  if (root==NULL)
    return;

  inorder(root->left);
  cout << root->data << "\t";
  inorder(root->right);
}

void postorder(BTNode* root)
{
  if (root==NULL)
    return;
  // IHOP: assume you have done postorder for left and right then finally print current
  postorder(root->left);
  postorder(root->right);
  cout << root->data << "\t";
}

int main()
{
    /*
    BTNode* root = new BTNode(10);
    root->left = new BTNode(20);
    root->right = new BTNode(30);

    //printTreeSimple(root);
    */
    BTNode* root = takeInput();

    printTree(root);

        postorder(root);
    inorder(root);
    preorder(root);

}
