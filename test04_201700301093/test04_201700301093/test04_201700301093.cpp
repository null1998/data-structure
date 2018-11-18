#include<iostream>
using namespace std;

template<class T>
class ChainNode{
public:
	void setData(T data) { this->data = data; }
	T getData() { return this->data; }
	ChainNode<T>* link=NULL;
private:
	T data=NULL;		 
};

template<class T>
class LinkStack {
public:
	void push(T data);
	T pop();
	bool isEmpty() { return top->getData()==NULL; }
	T getTop() { return top->getData(); }
	ChainNode<T>* top=new ChainNode<T>();
};

template<class T>
void LinkStack<T>::push(T data) {
	ChainNode<T>* newNode = new ChainNode<T>();
	newNode->setData(data);
	if (top == NULL) {
		top = newNode;
	}
	else {
		newNode->link = top;
		top = newNode;
	}
}
template<class T>
T LinkStack<T>::pop() {
	T element;
	if (!this->isEmpty()) {
		element = top->getData();
		top = top->link;
	}
	return element;
}
int comparePriority(char a,char b) {
	char op[6] = {'+','-','*','/','(',')'};//3是大于，2是等于，1是小于，0是不比较
	int pri[6][6] = {
		{2,2,1,1,1,3},
		{2,2,1,1,1,3},
		{3,3,2,2,1,3},
		{3,3,2,2,1,3},
		{1,1,1,1,1,0},
		{0,0,0,0,0,0}
	};
	int i, j;
	for (int k = 0; k < 6; k++) {
		if (a == op[k]) {
			i = k;
		}
		if (b == op[k]) {
			j = k;
		}
	}
	return pri[i][j];
}
char* toRPN(char* a) {
	LinkStack<char>* s=new LinkStack<char>();
	int j=0;
	char* b = new char[j];
	for (int i = 0; i < 100 && a[i] != NULL; i++) {
		if (a[i] != '+'&&a[i] != '-'&&a[i] != '*'&&a[i] != '/'&&a[i] != '('&&a[i] != ')') {
			b[j] = a[i];
			j++;
		}
		else {
				if (s->isEmpty()|| a[i] == '(') {
					s->push(a[i]);
				}
				else if (a[i] == ')') {
					while (s->getTop() != '(') {
						b[j] = s->pop();
						j++;
					}
					s->pop();
				}
				else {
					int priority=comparePriority(s->getTop(),a[i]);
					if (priority == 1) {
						s->push(a[i]);


					}
					if (priority == 2 || priority == 3) {
						while (!s->isEmpty()&&comparePriority(s->getTop(), a[i]) != 1) {
							b[j] = s->pop();
							j++;
						}
					}
				}
		}

	}
	while(!s->isEmpty()) {
		b[j] = s->pop();
		j++;
	}
	return b;
}
int calculate(char* b) {
	LinkStack<char>* num=new LinkStack<char>();
	int tmp=0;
	for (int i = 0; i < 100 && b[i] != NULL; i++) {
		switch (b[i]) {
		 case '+':
			 tmp=(num->pop() + 0) + (num->pop() + 0);
			 num->push(tmp);
			 continue;
		 case '-':
			 tmp = (num->pop() + 0) - (num->pop() + 0);
			 num->push(tmp);
			 break;
		 case '*':
			 tmp = (num->pop() + 0) * (num->pop() + 0);
			 num->push(tmp);
			 break;
		 case '/':
			 tmp = (num->pop() + 0) / (num->pop() + 0);
			 num->push(tmp);
			 break;
		 default:
			 num->push(b[i]);
			 break;
		}
	}
	return tmp;
}
int main() {
	char* a = "2+3*(4+5)-6/4";
	char* b = toRPN(a);
	cout << calculate(b);
	system("pause");
}