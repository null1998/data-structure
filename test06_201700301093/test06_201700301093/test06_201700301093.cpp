#include<iostream>
using namespace std;

void swap(int* a,int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
template<class T>
class BST_Node {
public:
	T data;
	BST_Node<T>* leftChild;
	BST_Node<T>* rightChild;
	BST_Node() { data = NULL; leftChild = NULL; rightChild = NULL; }
};
template<class T>
class BS_Tree {
public:
	BST_Node<T>* root;
	BS_Tree() { root = NULL; }
	BST_Node<T>* insert_bst(T data, BST_Node<T>* root);
	int pre_order(BST_Node<T>* root, int m, int max);
	int in_order(BST_Node<T>* root, int m, int max);
};
template<class T>
BST_Node<T>* BS_Tree<T>::insert_bst(T data, BST_Node<T>* root) {
	if (root == NULL) {
		root = new BST_Node<T>();
		root->data = data;
		root->leftChild = NULL;
		root->rightChild = NULL;
		return root;
	}
	if (data < root->data) {
		root->leftChild = insert_bst(data, root->leftChild);
	}
	else if (data > root->data) {
		root->rightChild = insert_bst(data, root->rightChild);
	}
	return root;
}
template<class T>
int BS_Tree<T>::pre_order(BST_Node<T>* root, int m, int max) {
	if (root) {
		m++;
		cout << root->data;
		if (m<max) {
			cout << ",";
		}
		m = pre_order(root->leftChild, m, max);
		m = pre_order(root->rightChild, m, max);
	}
	return m;
}
template<class T>
int BS_Tree<T>::in_order(BST_Node<T>* root, int m, int max) {
	if (root) {
		m = in_order(root->leftChild, m, max);
		cout << root->data;
		m++;
		if (m<max) {
			cout << ",";
		}
		m = in_order(root->rightChild, m, max);
	}
	return m;
}
template<class T>
class Heap {
public:
	
	Heap() {}
	void create_heap(int s[],int index,int length);
	void create(int s[], int length);
	void sort_heap(int s[],int length);
};
template<class T>
void Heap<T>::create_heap(int s[], int index, int length) {
	int m_val_index = index;
	int left_child_index = 2 * m_val_index;
	int right_child_index = left_child_index + 1;
	if (left_child_index<=length&&s[left_child_index]>=s[index]) {
		m_val_index = left_child_index;
	}
	if (right_child_index<=length&&s[right_child_index]>=s[m_val_index]) {
		m_val_index = right_child_index;
	}
	if (m_val_index != index) {
		int* a = &s[index];
		int* b = &s[m_val_index];
		swap(a, b);
		create_heap(s, m_val_index, length);
	}
}
template<class T>
void Heap<T>::create(int s[], int length){
	for (int i = length / 2; i >= 1; i--) {
		create_heap(s, i, length);
	}
}
template<class T>
void Heap<T>::sort_heap(int s[], int length) {
	for (int i = length; i >= 1; i--)
	{
		int* a = &s[1];
		int* b = &s[i];
		swap(a, b);
		create_heap(s,1,i-1);
	}
}

int main() {
	int num;
	int n = 0;
	int mark = 0;
	int k = 0;
	int j;
	int count = 0;
	int* s = new int[n];
	int* s2 = new int[n];
	Heap<int>* heap = new Heap<int>();
	BS_Tree<int>* bstree = new BS_Tree<int>();
	cout << "Input" << endl;
	for (int i = 1; i <=20; i++) {
		cin >> num;
		if (num == 0) {
			break;
		}
		else {
			s[i] = num;
			count++;
		}
	}
	for (int i = 1; i <= count; i++) {
		s2[i] = s[i];
	}
	cout << "Output" << endl;
	heap->create(s,count);
	for (j = 1; j <= count; j++) {
		cout << s[j];
		if (j != count) {
			cout << ",";
		}
	}
	cout << endl;
	heap->sort_heap(s,count);
	for (j = 1; j <= count; j++) {
		cout << s[j];
		if (j != count) {
			cout << ",";
		}
	}
	cout << endl;
	for (j = 1; j <= count; j++) {
		bstree->root=bstree->insert_bst(s2[j], bstree->root);
	}
	for (j = 1; j <count; j++) {
		for (k = j + 1; k <= count; k++) {
			if (s2[k] == s2[j]) {
				mark++;
			}
		}
	}
	count -= mark;//减去重复的数字后的大小。
	bstree->pre_order(bstree->root, 0, count);
	cout << endl;
	bstree->in_order(bstree->root, 0, count);
	cout << endl << "End" << endl;
	system("pause");
	return 0;
}