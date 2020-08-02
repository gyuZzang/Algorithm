#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	int element;
	int cnt=0;
	priority_queue<pair<int, int>,vector<pair<int ,int>>,greater<pair<int,int>>> pq; //(값, 인덱스)로 저장
	vector<pair<int, int>> vec; 
	vector<int> ans;

	cin >> N;
	ans.resize(N);

	//init!
	for (int i = 0; i < N; i++) {
		cin >> element;
		pq.push(make_pair(element, i));
	}
	


	int now = pq.top().first;

	//pq to vector
	for (int i = 0; i < N; i++){
		ans[pq.top().second] = cnt;
		vec.push_back(pq.top());
		pq.pop();
		if (i!=N-1&&now != pq.top().first) {
			now = pq.top().first;
			cnt++;
		}
	}

	//print ans
	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}

	system("pause");

}