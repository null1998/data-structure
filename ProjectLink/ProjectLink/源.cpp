#include "Link.h" 
#include<iostream>
using namespace std;

template<class T> Chain<T>::~Chain() {
	ChainNode<T>* current;
	while (first)
	{
		current = first->link;
		delete first;
		first = current;
	}
}
template<class T> int Chain<T>::length()const {
	ChainNode<T>* current;
	current=first;
	int len = 0;
	while (current)
	{
		len++;
		current=current->link;
	}
	return len;

}

template<class T>bool Chain<T>::findNode(int k,T&x)const {
	if (k < 1) {
		return false;
	}
	ChainNode<T>*current;
	current= first;
	int index = 1;
	while (index < k&&current) {
		current = current->link;
		index++;
	}
	if (current) {
		x = current->data;
		return true;
	}
	return false;
}

template<class T> int Chain<T>::searchNode(const T& x)const {
	ChainNode<T>*current = first;
	int index = 1;
	while (current&&current->data != x) {
		current = current->link;
		index++;
	}
	if (current) {
		return index;
	}
	return 0;
}


template<class T>Chain<T>& Chain<T>::deleteNode(int k, T&x) {
	if (k < 1 || !first) {
		//throw OutOfBounds();
	}
	ChainNode<T>*p = first;
	if (k == 1) {
		first = first->link;
	}
	else {
		ChainNode<T>*q = first;
		for (int index = 1; index < (k-1)&&q; index++) {
			q = q->link;
		}
		if (!q || !q->link) {
			//throw OutOfBounds();
		}
		p = q->link;
		q->link = p->link;
	}
	x = p->data;
	delete p;
	return *this;
}
template<class T>Chain<T>& Chain<T>::insertNode(int k, const T&x) {
	if(k < 0) {
		//throw OutOfBounds();
	}
	ChainNode<T>*p = first;
	for (int index = 1; index < k&&p; index++) {
		p = p->link;
	}
	if (k > 0 && !p) {
		//throw OutOfBounds();
	}
	ChainNode<T>* y = new ChainNode<T>;
	y->data = x;
	if (k) {
		y->link = p->link;
		p->link = y;
	}
	else {
		y->link = first;
		first = y;
	}
	return *this;
}
template<class T>void Chain<T>::outPut(ChainNode<T>* first)const {
	ChainNode<T>*current;
	for (current = first; current; current = current->link) {
		cout << current->data << " ";
	}
}
template<class T>ChainNode<T>* Chain<T>::reverse(ChainNode<T>* first) {
	ChainNode<T>* pre=NULL;
	ChainNode<T>* link;
	while (first) {
		link=first->link;
		first->link = pre;
		pre = first;
		first = link;
	}
	return pre;
}
template<class T>
ChainNode<T>* Chain<T>::merge1(ChainNode<T>* first_a, ChainNode<T>* first_b, ChainNode<T>* first_c) {
	if (first_a == 0) {
		return first_b;
	}
	else if(first_b==0){
		return first_a;
	}
	first_c = NULL;
	if (first_a->data <= first_b->data) {
		first_c = first_a;
		first_a = first_a->link;
	}
	else {
		first_c = first_b;
		first_b = first_b->link;
	}
	ChainNode<T>* tmpNode = first_c;
	while (first_a&&first_b) {
		if (first_a->data <= first_b->data) {
			first_c->link = first_a;
			first_a = first_a->link;
		}
		else {
			first_c->link = first_b;
			first_b = first_b->link;
		}
		first_c = first_c->link;
	}
	if (first_a) {
		first_c->link = first_a;
	}
	if(first_b){
		first_c->link = first_b;
	}
	return tmpNode;
}

void main() {
	
	/*Chain<int>* list=new Chain<int>();
	list->insertNode(0, 1);
	list->insertNode(1, 3);
	list->insertNode(2, 5);
	
	Chain<int>* list1 = new Chain<int>();
	list1->insertNode(0, 2);
	list1->insertNode(1, 4);
	list1->insertNode(2, 6);     merge1≤‚ ‘
	
	Chain<int>* list2 = new Chain<int>();
	list2->first=Chain<int>::merge1(list->first, list1->first, list2->first);
	list2->outPut(list2->first);*/


	system("pause");
}