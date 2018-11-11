#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include"BinaryTreeNode.h"
template<class T>
class BinaryTree {
public:
	BinaryTreeNode<T>* getRoot();
	void createTree(BinaryTreeNode<T>* t);
	static void preOrder(BinaryTreeNode<T>* t);
private:
	BinaryTreeNode<T>* root;
};
#endif // !BINARYTREE_H_
#pragma once
