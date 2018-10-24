
// array : size fixed
// linkedlist: access is stupid

// VVECTOR IS BEST OF BOST WORLDS HERE!
#include <iostream>
#include <vector>
#include "TreeNode.h"
using namespace std;


int main()
{
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* node1 = new TreeNode<int>(2);
    TreeNode<int>* node2 = new TreeNode<int>(3);

    root->children.push_back(node1);
    root->children.push_back(node2);

}
