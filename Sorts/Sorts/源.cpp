#include<iostream>
using namespace std;

template<class T>void insert(T* a,int end) {
	T tmp = a[end];
	int i;
	for (i = end - 1; i >= 0 && a[i] >=tmp; i--) {
		a[i + 1] = a[i];
	}
	
	a[i + 1] = tmp;
}
template<class T>void insertSort(T* a, int n) {
	for (int i = 1; i < n;i++) {
		insert(a, i);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl<<"下一步？1:0"<<endl;
		int m;
		cin >> m;
		if (m) {
				continue;
			}
			else {
				break;
			}
	}
}
template<class T>void swap(T* a,T*b) {
	T t = *a;
	*a = *b;
	*b = t;
}
template<class T>void selectSort(T* a, int n) {
	bool sorted = false;
	for (int size = n; size > 1 && !sorted; size--) {
		int pos = 0;
		sorted = true;
		for (int i = 1; i < size; i++) {
			if (a[pos] <= a[i]) {
				pos = i;
			}
			else {
				sorted = false;
			}
		}
		swap(a + pos, a + size - 1);
		
		if (sorted) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl << "下一步？1:0" << endl;
		int m;
		cin >> m;
		if (m) {
			continue;
		}
		else {
			break;
		}
	}
}
template<class T>bool bubble(T* a, int n) {
	bool swaped = false;
	for (int i = 0; i < n - 1; i++) {
		if (*(a + i) > *(a + i + 1)) {
			swap(a + i, a + i + 1);
			swaped = true;
		}
	}
	return swaped;
}
template<class T>void bubbleSort(T* a, int n) {
	for (int i = n; i >1; i--) {
		bool b=bubble(a, i);
		if (!b) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cout << *(a + i) << " ";
		}
		cout << endl << "下一步？1:0" << endl;
		int m;
		cin >> m;
		if (m) {
			continue;
		}
		else {
			break;
		}	
	}
}
template<class T>void rank1(T* a, int n,int* r) {
	for (int i = 0; i < n; i++) {
		*(r+i) = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (*(a + i) >= *(a + j)) {
				*(r+i)= *(r + i) +1;
			}
			else {
				*(r + j)= *(r + j)+1;
			}
		}
	}
	
}
template<class T>void rearRange(T* a, int n, T* r) {
	for (int i = 0; i < n; i++) {
		while(*(r+i)!= i) {
			int tmp = *(r+i);
			swap(a + i, a + tmp);
			swap(r + i, r + tmp);
			for (int i = 0; i < n; i++) {
				cout << a[i] << " ";
			}
			cout << endl << "下一步？1:0" << endl;
			int m;
			cin >> m;
			if (m) {
				continue;
			}
			else {
				break;
			}
		}

	}
}
const int N = 1000;
int main() {
	int n,s;
	int a[N],r[N];
	cout << "输入序列的大小："<<endl;
	cin >> n;
	cout <<"输入序列："<<endl;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout <<"选择排序类型：插入排序、选择排序、冒泡排序、名次排序（分别对应1，2，3，4）"<<endl;
	cin >> s;
	switch (s)
	{
	case 1:
		insertSort(a, n);
		break;
	case 2:
		selectSort(a, n);
		break;
	case 3:
		bubbleSort(a, n);
		break;
	case 4:
		rank1(a, n, r);
		rearRange(a, n, r);
		break;
	default:
		cout << "选择1、2、3、4";
		break;
	}
	system("pause");
	return 0;
}