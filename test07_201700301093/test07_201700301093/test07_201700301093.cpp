#include<iostream>
#include<queue>
#include<stack>
const int INF = 10000;
using namespace std;
class AdjacencyWGraph {	
public:
	int n, m,length;
	int a[10][10];
	int maze[10][10];
	int b[10];
	int distance[10];
	int count1, count2;
	queue<int> q;
	int mark[10];
	AdjacencyWGraph(int n, int m);
	void createWGraph(int vs, int vd, int w);
	void DFS(int pre);
	void BFS(queue<int> tmp);
	bool findShort(queue<int> tmp, int vd);
	void findShortW(int vs);
};
AdjacencyWGraph::AdjacencyWGraph(int n, int m) {
	this->n = n;
	this->m = m;
	for (int i = 0; i < n; i++) {
		this ->mark[i] = 0;
		this->distance[i] = INF;
		for (int j = 0; j < n; j++) {
			maze[i][j] = INF;
		}
	}
}
void AdjacencyWGraph::createWGraph(int vs, int vd, int w) {
	this->a[vs - 1][vd - 1] = w;
	this->a[vd - 1][vs - 1] = w;
	this->maze[vs - 1][vd - 1] = w;
	this->maze[vd - 1][vs - 1] = w;
	if (this->b[vs-1]==NULL)
	{
		this->b[vs-1] = 1;
	}
	if (this->b[vd-1] == NULL) {
		this->b[vd-1] = 1;
	}
}
void AdjacencyWGraph::DFS(int pre) {
	if (this->b[pre-1] != NULL&&this->mark[pre-1]==0) {
		this->q.push(pre);
		this->mark[pre-1] = 1;//标记，已经被访问
		count2++;
		for (int j = 0; j < this->n; j++) {
			if (this->a[pre - 1][j] != NULL &&this->mark[j] == 0) {
				DFS(j + 1);
			}
		}
	}
	
}
void AdjacencyWGraph::BFS(queue<int> p){
	queue<int> tmp;
	int pre;
	while (!p.empty()) {
		pre= p.front();
		if (this->b[pre - 1] != NULL &&this->mark[pre - 1] == 0) {
			this->q.push(pre);
			this->mark[pre - 1] = 1;//标记下已经被访问
			//访问完成，统计元素个数
			this->count1++;
		}
		for (int j = 0; j<this->n; j++) {
			if (a[pre - 1][j] != 0 && this->mark[j] == 0) {
				tmp.push(j + 1);//下轮要加入q的元素
			}
		}
		p.pop();
	}
	if (!tmp.empty()) {
		BFS(tmp);
	}	
}
//不加权的最短路径
bool AdjacencyWGraph::findShort(queue<int> p, int vd) {
	queue<int> tmp;
	int pre;
	while (!p.empty()) {
		pre = p.front();
		if (this->b[pre-1] != NULL &&this->mark[pre - 1] == 0) {
			this->q.push(pre);
			this->mark[pre - 1] = 1;//标记下已经被访问						
		}
		for (int j = 0; j<this->n; j++) {
			if (a[pre - 1][j] != 0 && this->mark[j] == 0) {
				if (j+1 == vd) {
					while (!tmp.empty()) {
						tmp.pop();
					}
					this->q.push(j+1);
					this->mark[j] = 1;//标记下已经被访问
					return true;		
				}
				tmp.push(j + 1);//下轮要加入q的元素
			}
		}
		p.pop();
	}
	if (!tmp.empty()) {
		BFS(tmp);
	}
}
//加权的最短路径
void AdjacencyWGraph::findShortW(int vs) {
	distance[vs-1] = 0;
	for (int i = 0; i < n; i++) {
		int min = INF;
		int minindex=0;
		for (int j = 0; j < n; j++) {
			if (mark[j] != 1 && distance[j] < min) {
				min = distance[j];
				minindex = j;
			}
		}
		
			mark[minindex] = 1;
		
		
		for (int j = 0; j < n; j++) {
			if (mark[j] != 1 && distance[j] > (distance[minindex] + maze[minindex][j])) {
				distance[j] = distance[minindex] + maze[minindex][j];
			}
		}
	}
	
}
int main() {

	int n, m,vs,vd,w;
	char ch;
	cout << "Input" << endl;
	cin >>n>>ch>> m;
	AdjacencyWGraph* g = new AdjacencyWGraph(n, m);
	for (int i = 0; i < m; i++) {
		cin>> vs>>ch>>vd>>ch>> w;
		g->createWGraph(vs, vd, w);
	}
	cout << "Output" << endl;
	queue<int> p;
	p.push(1);
	g->BFS(p);
	for (int i = 0; i < g->count1; i++) {
		cout << g->q.front();
		g->q.pop();
		if (i != g->count1 - 1) {
			cout << ",";
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		g->mark[i] = 0;
	}//清除标记



	g->DFS(1);
	for (int i = 0; i < g->count2; i++) {
		cout << g->q.front();
		g->q.pop();
		if (i != g->count2 - 1) {
			cout << ",";
		}
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		g->mark[i] = 0;
	}//清除标记

	 
	g->findShortW(1);
	if (g->distance[n-1] != INF) {
		cout << g->distance[n-1];
	}
	else {
		cout << "0";
	}
	cout<<endl << "End" << endl;
	system("pause");
	return 0;
}




















































































































































































































































































































































































































