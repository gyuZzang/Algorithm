#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

stack<int> st;
vector<int> shortest;
vector<int> visited;
vector<vector<int>> ll;//linkedlist처럼 구현


void set_distance(int i) {
	for (int j = 0; j < ll[i].size(); j++) {
		int now = ll[i][j];
		if (st.size() <= shortest[now] && visited[now]==0) {//사이클 방지
			shortest[now] = st.size();
			st.push(now);
			visited[now] = 1;
			set_distance(now);
			visited[now] = 0;
			st.pop();
		}
	}
}

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	int r, c;

	//최단거리 초기화
	shortest.resize(n, 20000);
	shortest[0] = 0;
	ll.resize(n);
	visited.resize(n,0);

	//ll 초기화, 최단거리 setting
	for (int i = 0; i < edge.size(); i++) {
		r = edge[i][0] - 1;
		c = edge[i][1] - 1;

		ll[r].push_back(c);
		ll[c].push_back(r);

		if (r == 0)
			shortest[c] = 1;
		if (c == 0)
			shortest[r] = 1;
	}

	st.push(0);
	visited[0] = 1;
	set_distance(0);


	//answer에 최댓값
	for (int j = 0; j < n; j++) {
		cout << shortest[j] << " ";
		answer = answer < shortest[j] ? shortest[j] : answer;
	}

	int num = 0;
	for (int j = 0; j < n; j++)
		if (shortest[j] == answer)num++;
	//최단거리의 최대값
	return num;
}

int main(void) {

	cout << solution(6, { { 3,6 }, { 4,3 }, { 3,2 },{1,3},{1,2},{2,4},{5,2} });
	system("pause");
}