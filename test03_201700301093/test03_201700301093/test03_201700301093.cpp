#include<iostream>
using namespace std;

template<class T>
class ChainNode {
public:
	void setData(T data) {
		this->data = data;
	}
	T getData() {
		return data;
	}
	ChainNode<T>* link = NULL;//注意要初始化为NULL否则在用变量作判断时均为非零，导致死循环。（只有64位会出现，32位编译则不会）
private:
	T data = NULL;


};

template<class T>
class Chain {
public:
	Chain() {};
	~Chain();
	bool insert(T data);
	int findIndex(T data, ChainNode<T>* first);
	static ChainNode<T>* merge(ChainNode<T>* first_a, ChainNode<T>*first_b);
	static void outPut(ChainNode<T>* first);
	ChainNode<T>* first;
};

template<class T>
Chain<T>::~Chain() {
	ChainNode<T>* current;
	while (first) {
		current = first->link;
		delete first;
		first = current;
	}
}
template<class T>
bool Chain<T>::insert(T data) {
	ChainNode<T>* newNode = new ChainNode<T>;
	newNode->setData(data);
	ChainNode<T>* tmp;
	if (!first) {
		first = newNode;
	}
	else {
		if (data>first->getData()) {
			tmp = first;
			while (tmp->link&&tmp->link->getData() <= data) {
				tmp = tmp->link;
			}
			if (!tmp->link) {
				tmp->link = newNode;
			}
			else {
				newNode->link = tmp->link;
				tmp->link = newNode;
			}
		}
		else {
			newNode->link = first;
			first = newNode;
			return true;
		}
	}
}
template<class T>
int Chain<T>::findIndex(T data, ChainNode<T>* first) {
	ChainNode<T>* current;
	int i;
	for (current = first, i = 1; current; current = current->link, i++) {
		if (current->getData() == data) {
			return i;
		}
	}
	if (!current) {
		return 0;
	}
}
template<class T>
ChainNode<T>* Chain<T>::merge(ChainNode<T>*first_a, ChainNode<T>*first_b) {
	ChainNode<T> *first_c, *tmp;;
	if (!first_a) {
		first_c = first_b;
	}
	else if (!first_b) {
		first_c = first_a;
	}
	if (first_a->getData() <= first_b->getData()) {
		first_c = first_a;
		first_a = first_a->link;
	}
	else {
		first_c = first_b;
		first_b = first_b->link;
	}
	tmp = first_c;
	while (first_a&&first_b) {
		if (first_a->getData() <= first_b->getData()) {
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
	if (first_b) {
		first_c->link = first_b;
	}
	return tmp;
}
template<class T>
void Chain<T>::outPut(ChainNode<T>* first) {
	ChainNode<T>* current;
	for (current = first; current; current = current->link) {
		cout << current->getData();
		if (current->link) {
			cout << ",";
		}
	}
}

int main() {
	Chain<int>* chain = new Chain<int>();
	int n;
	cout << "Input1" << endl;
	for (int i = 1; i<100; i++) {
		cin >> n;
		if (n == 0) {
			cout << "Output1" << endl;
			Chain<int>::outPut(chain->first);
			break;
		}
		chain->insert(n);
	}
	cout << endl << "Input2" << endl;
	cin >> n;
	chain->insert(n);
	cout << "Output2" << endl;
	Chain<int>::outPut(chain->first);
	cout << endl << "Input3" << endl;
	cin >> n;
	cout << "Output3" << endl << chain->findIndex(n, chain->first) << endl << "Input4" << endl;
	cin >> n;
	cout << "Output4" << endl << chain->findIndex(n, chain->first) << endl << "Input5" << endl;
	Chain<int>* chain2 = new Chain<int>();
	for (int i = 1; i<100; i++) {
		cin >> n;
		if (n == 0) {
			cout << "Output5" << endl;
			Chain<int>::outPut(chain2->first);
			cout << endl;
			Chain<int>::outPut(Chain<int>::merge(chain->first, chain2->first));
			cout << endl << "End" << endl;
			break;
		}
		chain2->insert(n);
	}
	//	chain->insert(2);
	//	chain->insert(1);
	//	chain->insert(3);
	//	chain->insert(0);
	//	chain->insert(2);
	//	chain->insert(3);
	//	chain->outPut(chain->first);
	system("pause");
	return 0;
}
