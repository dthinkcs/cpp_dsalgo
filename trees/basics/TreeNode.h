#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;    //  vector<TreeNode*<int> children; means all the subnodes must have int

    TreeNode(T data)
    {
        this->data = data;
    }
};
