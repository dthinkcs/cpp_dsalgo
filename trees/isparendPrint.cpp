#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
#define MAX 50
class BTNode
{
    public:
    int data;
    BTNode* left;
    BTNode* right;

    BTNode (int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

};

bool isparentPrint(BTNode* root, int item)
{
  if (root == NULL)
    return false;
    
  if (root->data == item)
    return true;
    
   if (isparentPrint(root->left) || isparendPrint(root->right))
   {
      cout << root->data << endl; 
      return false;
   }
   
   return false;
}
