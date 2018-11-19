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
int cal(char op, char num1, char num2) {
	int result = 0;
	switch (op) {
	case '+':
		result = num1+num2;
		break;
	case '-':
		result = num1-num2;
		break;
	case '*':
		result = num1*num2;
		break;
	case '/':
		result = num1/num2;
		break;
	}
	return result;
}
int RPN(char* a) {
	LinkStack<int>* nums=new LinkStack<int>();
	LinkStack<char>* ops=new LinkStack<char>();
	for (int i = 0; i < 100 && a[i] != NULL; i++) {
		if (a[i] != '+'&&a[i] != '-'&&a[i] != '*'&&a[i] != '/'&&a[i] != '('&&a[i] != ')') {
			nums->push(a[i]-48);
		}
		else {
				if (ops->isEmpty()|| a[i] == '(') {
					ops->push(a[i]);
				}
				else if (a[i] == ')') {
					while (ops->getTop() != '(') {
						char op= ops->pop();
						char num2 = nums->pop();
						char num1 = nums->pop();
						nums->push(cal(op, num1, num2));
					}
					ops->pop();
				}
				else {
					int priority=comparePriority(ops->getTop(),a[i]);
					if (priority == 1) {
						ops->push(a[i]);
					}
					if (priority == 2 || priority == 3) {
						while (!ops->isEmpty()&&comparePriority(ops->getTop(), a[i]) != 1) {
							char op=ops->pop();
							char num2 = nums->pop();
							char num1 = nums->pop();
							nums->push(cal(op, num1, num2));
						}
						ops->push(a[i]);
					}
				}
		}

	}
	while(!ops->isEmpty()) {
		char op = ops->pop();
		char num2 = nums->pop();
		char num1 = nums->pop();
		nums->push(cal(op, num1, num2));
	}
	int result=nums->getTop();
	return result;
}

int main() {
	//2+3*(4+5)-6/4
	//9+(3+5)/2-2*3
	//2+3*4*(3+3)/2-9+8
	char a[100];
	cout << "Input"<<endl;
	cin >> a;
	cout << "Output" << endl;
	cout << RPN(a)+0<<endl<<"End"<<endl;
	system("pause");
	return 0;
}