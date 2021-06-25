#include "Binary_v2.h"

string BSTree::SubTreeAsString(TreeNode * node)
{
	string leftStr = (node->left == nullptr) ? "{}" : SubTreeAsString(node->left);
	string rightStr = (node->right == nullptr) ? "{}" : SubTreeAsString(node->right);
	string result = "{" + to_string(node->value) + ", " + leftStr + ", " + rightStr + "}" ;
	return result;
}


void BSTree::Print()
{
	if (this->root == nullptr)
	{
		cout << "{}" << endl;
	}
	else
	{
		cout << this->SubTreeAsString(this->root) << endl;
	}
}

void BSTree::Insert(int val)
{
	this->Insert(val, this->root);
}



void BSTree::Insert(int val, TreeNode *& node)
{
	if (node == nullptr)//case: node=null->make ane node
	{
		node = new TreeNode(val, " ");//need to update value
	}
	else
	{
		if (val < node->value)
		{
			this->Insert(val, node->left);
		}
		else if (val > node->value)
		{
			this->Insert(val, node->right);
		}
		else
		{
			cout << "Warning: value already exist" << endl;
		}
	}
}

bool BSTree::Contains(int val)
{
	return Contains(val, this->root);
}


bool BSTree::Contains(int val, TreeNode *&node)
{
	if (node == nullptr)
	{
		return false;
	}
	else if (val == node->value)
	{
		return true;
	}
	else if (val < node->value)
	{
		return this->Contains(val, node->left);
	}
	else
	{
		return this->Contains(val, node->right);
	}
}

void BSTree::Remove(int val)
{
	this->Remove(val, this->root);
}
void BSTree::Remove(int val, TreeNode *& node)
{
	if (node == nullptr)
	{
		cout << "입력한 값이 트리에 없습니다." << endl;
		return;
	}
	else if (val == node->value)//값이 있으면
	{
		TreeNode *trash = nullptr;//trash 초기화
		if (node->left == nullptr&&node->right == nullptr)
		{
			trash = node;
			node = nullptr;
		}
		else if (node->left != nullptr&&node->right == nullptr)//왼쪽자식노드만 있고, 가르키는 노드가 부모노드의 왼쪽에 있을때
		{
			trash = node;
			node = node->left;
		}
		else if (node -> left == nullptr&&node->right != nullptr)//우측 자식노드가 있고 좌측은 없을 때
		{
			trash = node;
			node = node->right;
		}
		else//둘 다 있을때
		{
			TreeNode *&minNode = this->FindMin(node->right);
			node -> value = minNode->value;
			this->Remove(minNode->value, minNode);
		}

		//Free memory
		if (trash != nullptr)delete trash;
	}
	else if (val < node->value)//case: remove val from this node's left subtree
	{
		this->Remove(val, node->left);
	}
	else//case: remove val from this node's right subtree;
	{
		this->Remove(val, node->right);
	}
}

/// Search the subtree starting at node and return a pointer to the minimum-value node
/// The returned pointer will be a reference of an actual pointer in the tree, not a copy
TreeNode*& BSTree::FindMin(TreeNode*& node) {
	if (node == nullptr) {
		throw "Min value not found";
	}
	else if (node->left == nullptr) {
		return node;
	}
	else {
		return this->FindMin(node->left);
	}
}
