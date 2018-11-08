#ifndef Link_H_
#define Link_H_

template<class T>
class ChainNode {
public:
	template<class T>
	friend class Chain;
private:
	T data;
	ChainNode<T>* link;
};

template<class T>
class Chain {
public:
	Chain() { first = 0; }
	~Chain();
	bool isEmpty()const { return first == 0; }
	int length()const;
	bool findNode(int k, T& x)const;
	int searchNode(const T& x)const;
	Chain<T>& deleteNode(int k, T&x);
	Chain<T>& insertNode(int k,const T&x);
	void outPut(ChainNode<T>* first)const;
	ChainNode<T>* reverse(ChainNode<T>* first);
	static ChainNode<T>* merge1(ChainNode<T>* first_a, ChainNode<T>* first_b, ChainNode<T>* first_c);
	ChainNode<T>* first;
	

};
#endif // !Link_H_
#pragma once
