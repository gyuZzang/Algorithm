#include <string>
#include <vector>
#include<queue>

using namespace std;

//우선순위큐!!!!!!!!!!!!!!!!!!
int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> less;
	vector<int> great;
	int a, b, i;


	//K보다 작은 값들만 less에 저장
	for (i = 0; i<scoville.size(); i++) {
		if (scoville[i] < K) {
			less.push_back(scoville[i]);
		}
		else great.push_back(scoville[i]);
	}

	priority_queue<int, vector<int>, greater<int>> pri_q(less.begin(), less.end());

	if (pri_q.size() == 0) return 0;

	while (pri_q.size() > 1) {
		a = pri_q.top(); pri_q.pop();
		b = pri_q.top(); pri_q.pop();//제일 작은 원소 2개
		a = a + b * 2;
		if (a < K) {//순환해서 less의 적당한 자리에 insert
			pri_q.push(a);//자동으로 정렬되어 들어가는 구나
			//for (i = 0; i<less.size()&& less[i] < a; i++);
			//less.insert(less.begin() + i, a);
		}
		else great.push_back(a);
		answer++;
	}

	if (pri_q.size() == 1) {
		if (great.size() > 0) return answer + 1;
		else return -1;
	}

	return answer;
}

