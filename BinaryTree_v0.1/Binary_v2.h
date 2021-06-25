#pragma once
#include <iostream>
#include <string>
using namespace std;
struct TreeNode
{
	int value;
	string name;
	TreeNode* left;
	TreeNode* right;

	//constructor
	TreeNode(int _value,string _name) :value(_value), name(_name),left(nullptr), right(nullptr){}
};

class BSTree
{
private:
	TreeNode *root;

	//Helpermethod for insert(int val)
	string SubTreeAsString(TreeNode *node);
	void Insert(int val, TreeNode *&node);
	bool Contains(int val, TreeNode *&node);
	void Remove(int val, TreeNode *&node);
	TreeNode*& FindMin(TreeNode*& node); // Helper method for Remove(int val)
public:
	BSTree() : root(nullptr) {}
	BSTree(TreeNode *rootNode):root(rootNode){}

	//member functions
	void Print();
	void Insert(int val);
	bool Contains(int val);
	void Remove(int val);
};

