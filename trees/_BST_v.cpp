#include <iostream>
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

BSTNode* insertBST(BSTNode* root, int item)
{
  if (root == NULL)
  {
    root = new BSTNode(item);
    return root;
  }
  
  if (item < root->data)
    root->left = insertBST(root->left, item);
  else 
    root->right = insertBST(root->right, item);
  
  return root;
}

// do test cases here
BSTNode* deleteBST(BSTNode* root, int item)
{
  
  BSTNode * ptr = NULL,  * curr = NULL, * par = NULL, * succ = NULL;
  for( ptr = root; ptr; )
  {
    if (ptr->data == item)
    {
      curr = ptr;
      break;
    }
    par = ptr;//  curr; //ptr;
    if (item < ptr->data)
      ptr = ptr->left;
    else
      ptr = ptr->right;
  }
  
  if (curr == NULL)
    return root;
    
  if (curr->left && curr->right)
  {
    par = curr;
    succ = curr->right; 
    for ( ; succ->left; succ=succ->left)
    {
      par = succ;
    }
    curr->data = succ->data; // overwrite curr->data with succ->data
    
    curr = succ; // change curr to succ
    
    
  }
  
  if (par)
  {
    if (!curr->left && !curr->right) 
      if (par->left == curr)
        par->left = NULL;
      else 
        par->right = NULL;

    
    if (curr->left && !curr->right) 
      if (par->left == curr)
        par->left = curr->left;
      else 
        par->right = curr->left;

    
    if (!curr->left && curr->right) 
      if (par->left == curr)
        par->left = curr->right;
      else 
        par->right = curr->right;

  }
  
  delete curr;
  return root;
}

BSTNode* search(BSTNode* root, int item)
{
  if (root == NULL)
    return NULL;
  if (root->data == item)
     return root;
  if (item < root->data)
    return search(root->left, item);
  else
    return search(root->right, item);
}

int main()
{
  BSTNode* root = NULL;
  root = insertBST(root, 50);
  insertBST(root, 40);
  insertBST(root, 60);
  insertBST(root, 45);
  insertBST(root, 35);
  
  deleteBST(root, 45);
}
