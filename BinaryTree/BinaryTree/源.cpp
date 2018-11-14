#include"BinaryTreeNode.h"
#include"BinaryTree.h"
#include<iostream>
using namespace std;
template<class T>
BinaryTreeNode<T>::BinaryTreeNode() {}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(T t) {
	data = t;
}
template<class T>
void BinaryTreeNode<T>::setData(T t) {
	data = t;
}
template<class T>
T BinaryTreeNode<T>::getData() {
	return data;
}
template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T>* t) {
	leftChild = t;
}
template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T>* t) {
	rightChild = t;
}
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLeftChild(){
	return leftChild;
}
template<class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRightChild() {
	return rightChild;
}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot() {
	return root;
}
template<class T>
void BinaryTree<T>::createTree(BinaryTreeNode<T>*t) {
	if (root == NULL) {
		root = t;
	}
}
template<class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>*t) {
	if (t) {
		cout <<t->getData()<<" ";
		preOrder(t->getLeftChild());
		preOrder(t->getRightChild());
	}
}
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* t) {
	if (t) {
		inOrder(t->getLeftChild());
		cout << t->getData() << " ";
		inOrder(t->getRightChild());
	}
}
template<class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>*t) {
	if (t) {
		postOrder(t->getLeftChild());
		postOrder(t->getRightChild());
		cout << t->getData() << " ";
	}
}
int main() {
	BinaryTreeNode<int>* t1 = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>* t2 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>* t3 = new BinaryTreeNode<int>(3);
	t1->setLeftChild(t2);
	t1->setRightChild(t3);
	BinaryTree<int>* tree1 = new BinaryTree<int>();
	tree1->createTree(t1);
	BinaryTree<int>::postOrder(tree1->getRoot());
	system("pause");
	return 0;
}