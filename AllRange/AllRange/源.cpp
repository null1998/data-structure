#include<iostream>

using namespace std;

void swap(int* a,int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
bool isSwap(int str[],int bg,int ed ) {
	for (int i = bg; i <ed; i++) {
		if (str[i] == str[ed]) {
			return false;
		}		
	}
	return true;
}
void allRange(int str[],int bg,int max) {
	if (bg == max) {
		for (int i = 0; i < max; i++) {
			cout << str[i];
			if (i != max - 1) {
				cout << "£¬";
			}
		}
		cout << endl;
	}
	else {
		for (int i = bg; i < max; i++) {
			if (isSwap(str, bg, i)) {
				swap(str+bg,str+i);
				allRange(str, bg + 1, max);
				swap(str+bg, str+i);
			}
		}
	}
}
const int N = 20;
int main() {
	int max = 0;
	int j;
	int a[N];
	cout << "Input"<<endl;
	for (int i = 0; i < 20; i++) {
		cin >> j;
		if (j < 0) {
			break;
		}
		if (j == 0) {
			cout << "OutPut"<<endl;
			break;
		}
		a[i] = j;
		max++;
	}
	
	if (max == 1) {
		return 0;
	}
	allRange(a, 0, max);
	cout << "End"<<endl;
	return 0;
}