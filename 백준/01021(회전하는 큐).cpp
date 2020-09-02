#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
#include<string>

//deque�� ���ϴ�!
using namespace std;

int main() {
	
	int N, M;
	int start_point=0;
	int target_idx;
	int ans = 0;
	int moving_cnt;
	deque<int> q;
	vector<pair<int,int>> seq; //{��, �ε���}
	cin >> N >> M;
	
	seq.resize(M);
	q.resize(N);


	for (int i = 0; i < M; i++) {
		cin >> seq[i].first;
		seq[i].second = seq[i].first - 1;
		for (int j = 0; j < i; j++)
		{
			if (seq[i].first > seq[j].first)
				seq[i].second--;

		}
	}	
	
	for (int i = 1; i <= N; i++){
		q[i-1]=i;
	}
	
	//ȸ�� ť  ����
	for(int i=0;i<M;i++) {

		target_idx = seq[i].second;

		//ȸ���� ĭ �� ���, q���� �̱�.
		moving_cnt = min(N - abs(start_point - target_idx), abs(start_point - target_idx));
		q.erase(q.begin()+target_idx);
		
		start_point = target_idx;
		N--;		
		//idx N�ʰ�->�ѹ��� ����
		if (start_point!=0 && start_point >= N) start_point %= N;
		ans += moving_cnt;
	}

	cout << ans;

}