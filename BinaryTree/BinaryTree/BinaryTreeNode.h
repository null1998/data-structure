#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_
template<class T>
class BinaryTreeNode {
public:
	BinaryTreeNode();
	BinaryTreeNode(T t);
	void setData(T t);
	T getData();
	void setLeftChild(BinaryTreeNode<T>* t);
	void setRightChild(BinaryTreeNode<T>* t);
	BinaryTreeNode<T>* getLeftChild();
	BinaryTreeNode<T>* getRightChild();
private:
	T data;
	BinaryTreeNode<T> *leftChild,*rightChild;
};
#endif // !BINARYTREENODE_H_
#pragma once
