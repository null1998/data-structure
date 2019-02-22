#include<iostream>
#include<vector>
using namespace std;
struct Line{
	int s;
	int e;
	int w;
};

const int N = 6;
const int MAX = 1000;
void main() {
	int graph[N][N];
	int identify[N];
	vector<Line>lines;
	vector<Line>result;
	int s, e, w;
	for (int i = 0; i <N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = MAX;
		}
	}
	for (int i = 0; i < N; i++) {
		identify[i] = i;
	}
	cout << "输入起点、终点、权值"<<endl;
	for (int i = 0; i < 15; i++) {
		cin >> s >> e >> w;
		if (s == 0 && e == 0 && w == 0) {
			break;
		}
		if (s < 0 || s >= N || e < 0 || e >= N || w >= 1000||s==e) {
			cout << "出错";
			break;
		}
		graph[s][e] = w;
		graph[e][s] = w;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (graph[i][j] != MAX) {
				Line line;
				line.s = i;
				line.e = j;
				line.w = graph[i][j];
				lines.push_back(line);
			}
		}
	}
	while (!lines.empty()) {
		int min = 1000;
		int index = -1;
		for (int i = 0; i < lines.size(); i++) {
			if (lines.at(i).w < min) {
				min = lines.at(i).w;
				index = i;
			}
		}
		Line min_l = lines.at(index);
		if (identify[min_l.s] != identify[min_l.e]) {
			int mark = identify[min_l.e];
			for (int i = 0; i < N; i++) {
				if (identify[i] == mark) {
					identify[i] = identify[min_l.s];
				}
			}
			result.push_back(min_l);
		}
		lines.erase(lines.begin() + index);		
	}
	while (!result.empty()) {
		for (int i = 0; i < result.size(); i++) {
			cout << result.at(i).s << " "<< result.at(i).e<< " " <<result.at(i).w<<endl;
			result.erase(result.begin() + i);
		}
	}
	system("pause");
}