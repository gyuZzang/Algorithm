#include <string>
#include <vector>
#include<queue>

using namespace std;

//�켱����ť!!!!!!!!!!!!!!!!!!
int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> less;
	vector<int> great;
	int a, b, i;


	//K���� ���� ���鸸 less�� ����
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
		b = pri_q.top(); pri_q.pop();//���� ���� ���� 2��
		a = a + b * 2;
		if (a < K) {//��ȯ�ؼ� less�� ������ �ڸ��� insert
			pri_q.push(a);//�ڵ����� ���ĵǾ� ���� ����
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

