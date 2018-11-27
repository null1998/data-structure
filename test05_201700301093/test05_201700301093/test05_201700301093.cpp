#include<iostream>
using namespace std;

template<class T>
class BinaryTreeNode {
public:
	BinaryTreeNode<T>* leftChild;
	BinaryTreeNode<T>* rightChild;
	BinaryTreeNode<T>* link;//层次遍历时用来排队
	T data;
	BinaryTreeNode() { leftChild = NULL; rightChild = NULL;link=NULL; data = NULL; };
};
template<class T>
class Queue {
public:
	BinaryTreeNode<T>* top;
	Queue() { top = NULL; };
	void push(BinaryTreeNode<T>* node);
	BinaryTreeNode<T>* pop();
};
template<class T>
class BinaryTree {
public:
	BinaryTreeNode<T>* root;
	BinaryTree() { root = NULL; };
	BinaryTreeNode<T>** init(char* a,int count);
	BinaryTreeNode<T>* create_tree(BinaryTreeNode<T>** btns,int i);
	int pre_order(BinaryTreeNode<T>* root,int m,int max);
	int in_order(BinaryTreeNode<T>* root, int m, int max);
	int post_order(BinaryTreeNode<T>* root, int m, int max);
	void order(BinaryTreeNode<T>* root);
	void order1(BinaryTreeNode<T>* root, Queue<T>*q);
	void construct_tree(BinaryTreeNode<T>** pre_btns, BinaryTreeNode<T>** in_btns, int length);
	BinaryTreeNode<T>* construct(BinaryTreeNode<T>** pre_btns, BinaryTreeNode<T>** in_btns, int length);
};

template<class T>
void Queue<T>::push(BinaryTreeNode<T>* node) {
	if (top == NULL) {
		top = node;
	}
	else {
		BinaryTreeNode<T>* tmp = top;
		while (tmp->link!=NULL) {
			tmp = tmp->link;
		}
		tmp->link = node;
	}
}
template<class T>
BinaryTreeNode<T>* Queue<T>::pop() {
	BinaryTreeNode<T>* tmp = new BinaryTreeNode<T>();
	if (top->data!= NULL) {
		tmp->data = top->data;
		tmp->leftChild = top->leftChild;
		tmp->rightChild = top->rightChild;
		top = top->link;
	}
	return tmp;
}
template<class T>
int BinaryTree<T>::pre_order(BinaryTreeNode<T>* root,int m,int max) {
	if(root) {
		m++;
		cout << root->data ;
		if (m<max) {
			cout << ",";
		}
		m=pre_order(root->leftChild,m,max);
		m=pre_order(root->rightChild,m,max);
	}
	return m;
}
template<class T>
int BinaryTree<T>::in_order(BinaryTreeNode<T>* root, int m, int max) {
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
int BinaryTree<T>::post_order(BinaryTreeNode<T>* root, int m, int max) {
	if (root) {
		if (root->leftChild != NULL) {
			m = post_order(root->leftChild, m, max);
		}
		if (root->rightChild!= NULL) {
			m = post_order(root->rightChild, m, max);
		}
		m++;
		cout << root->data;
		if (m<max) {
			cout << ",";
		}
	}
	return m;
}
//利用层次遍历输出二叉树
template<class T>
void BinaryTree<T>::order(BinaryTreeNode<T>* root) {
	Queue<T>* q = new Queue<T>();
	q->push(root);
	BinaryTreeNode<T>* father_node = q->pop();
	cout << father_node->data;
	if (father_node->leftChild || father_node->rightChild) {
		cout << ",";
	}
	if (father_node->leftChild != NULL) {
		q->push(father_node->leftChild);
	}
	if (father_node->rightChild != NULL) {
		q->push(father_node->rightChild);
	}
	if (father_node->leftChild != NULL) {
		order1(father_node->leftChild, q);
	}
	
	while (q->top!= NULL) {
		cout << q->top->data;
		if (q->top->link != NULL) {
			cout << ",";
		}
		q->top = q->top->link;
	}
}
template<class T>
void BinaryTree<T>::order1(BinaryTreeNode<T>* root, Queue<T>*q) {
	BinaryTreeNode<T>* father_node = q->pop();
	cout<< father_node->data;
	if (father_node->leftChild!= NULL) {
		q->push(father_node->leftChild);
	}
	if (father_node->rightChild!=NULL) {
		q->push(father_node->rightChild);
	}
	if (q->top != NULL) {
		cout << ",";
	}
	if (father_node->leftChild == NULL) {
		return;
	}
	//order1(father_node->leftChild, q);
	//

}
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::construct(BinaryTreeNode<T>** pre_btns, BinaryTreeNode<T>** in_btns, int length) {
	BinaryTreeNode<T>* root = pre_btns[1];
	construct_tree(pre_btns, in_btns, length);
	return root;
}

template<class T>
void BinaryTree<T>::construct_tree(BinaryTreeNode<T>** pre_btns, BinaryTreeNode<T>** in_btns,int length) {
	int left_length = 0;
	int right_length = 0;
	for (int i = 1; i <= length; i++) {
		if (in_btns[i]->data != pre_btns[1]->data) {
			left_length++;
		}
		else {
			break;
		}
	}
	if (left_length != 0) {
		right_length = length - left_length - 1;
		pre_btns[1]->leftChild = pre_btns[2];
		BinaryTreeNode<T>** pre_right = new BinaryTreeNode<T>*[right_length + 1];
		BinaryTreeNode<T>** in_right = new BinaryTreeNode<T>*[right_length + 1];
		BinaryTreeNode<T>** pre_left = new BinaryTreeNode<T>*[left_length + 1];
		BinaryTreeNode<T>** in_left = new BinaryTreeNode<T>*[left_length + 1];
		for (int i = 1; i <= left_length; i++) {
			pre_left[i] = pre_btns[i + 1];
		}
		for (int i = 1; i <= left_length; i++) {
			in_left[i] = in_btns[i];
		}
		construct_tree(pre_left, in_left, left_length);
		if (right_length != 0) {
			pre_btns[1]->rightChild = pre_btns[2 + left_length];
			for (int i = 1; i <= right_length; i++) {
				pre_right[i] = pre_btns[i + 1 + left_length];
			}
			for (int i = 1; i <= right_length; i++) {
				in_right[i] = in_btns[i + left_length + 1];
			}
			construct_tree(pre_right, in_right, right_length);
		}
	}
	else {
		return;
	}

}
//用节点对象封装字符，输出节点数组。
template<class T>
BinaryTreeNode<T>** BinaryTree<T>::init(char* a,int count) {
	BinaryTreeNode<char>** btns=new BinaryTreeNode<char>*[count+1];
	for (int i = 1; i <=count; i++) { 
		BinaryTreeNode<char>* btn = new BinaryTreeNode<char>();
		btn->data = a[i-1];
		btns[i] = btn;
	}
	return btns;
}

//利用层次遍历重建树
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::create_tree(BinaryTreeNode<T>** btns,int count) {
	for (int j = 2; j <=count; j++) {	
		if (j % 2 == 0) {
			btns[j / 2]->leftChild = btns[j];
		}
		if (j % 2 == 1) {
			btns[j / 2]->rightChild = btns[j];
		}		
	}
	return btns[1];
}
int get_high(int length) {
	int tmp = length;
	int count = 1;
	int result = 0;
	while (tmp > 0) {
		tmp = tmp - count;
		count *= 2;
		result++;
	}
	return result;
}

int main() {
	int n = 0;
	char* a =new char[n] ;
	BinaryTree<char>* tree1 = new BinaryTree<char>();
	cout << "Input1" << endl;
	cin >> a;
	tree1->root = tree1->create_tree(tree1->init(a, strlen(a)),strlen(a));
	cout << "Output1"<<endl;
	tree1->pre_order(tree1->root,0,strlen(a));
	cout << endl;
	tree1->in_order(tree1->root, 0, strlen(a));
	cout << endl;
	tree1->post_order(tree1->root, 0, strlen(a));
	cout << endl << strlen(a);
	cout << endl << get_high(strlen(a) )<< endl;
	
	char*b = new char[n];
	char*c = new char[n];
	BinaryTree<char>* tree2 = new BinaryTree<char>();
	cout << "Input2" << endl;
	cin >> b;
	cin >> c;
	tree2->root=tree2->construct(tree2->init(b, strlen(b)), tree2->init(c, strlen(c)), strlen(b));
	cout << "OutPut2" << endl;
	tree2->post_order(tree2->root, 0, strlen(b));
	cout << endl;
	tree2->order(tree2->root);
	cout << endl<<"End"<<endl;
	system("pause");
	return 0;
}