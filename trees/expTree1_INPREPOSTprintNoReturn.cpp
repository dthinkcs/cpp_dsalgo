#include <iostream>
#include <cstring>
#include <cmath>
#include <cctype>
#include <stack>
using namespace std;
#define MAX 50

class BTNode
{
public:
	char data;
	BTNode* left;
	BTNode* right;

	BTNode(char data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}

	~BTNode()
	{
		delete left;
		delete right;
	}
};


BTNode* postfixToBT(char* postfix)
{
	stack<BTNode*> s;
	for (int i = 0; postfix[i]; i++)
	{
		if (isdigit(postfix[i]))
		{
			s.push(new BTNode(postfix[i]));
		}
		else
		{
			BTNode* root = new BTNode(postfix[i]);
			BTNode* operand2 = s.top(); s.pop();
			BTNode* operand1 = s.top(); s.pop();
			root->left = operand1;
			root->right = operand2;
			s.push(root);
		}
	}
	
	// printTree(s.top());
	return s.top();
}

int eval(BTNode* root)
{
	
	if (root == NULL)
		return 0;
	if (isdigit(root->data))
		return root->data - '0';
	else
	{
		switch (root->data)
		{
			case '/':
				return eval(root->left) / eval(root->right);
			case '*':
				return eval(root->left) * eval(root->right);
			case '+':
				return eval(root->left) + eval(root->right);
			case '-':
				return eval(root->left) - eval(root->right);

		}
	}
}

BTToPrefix(Node* root)
{

}

int main()
{
	char postfix[MAX];
	cin >> postfix;
	BTNode* root = postfixToBT(postfix);
	cout << "Evaluation" : eval(root) << endl;
	cout << "PREFIX: " << BTToPrefix(root); cout << endl;
	cout << "INNFIX: " << BTToInfix(root) << endl;
	cout << "POSTFX: " << BTToPostfix(root) << endl;
}
