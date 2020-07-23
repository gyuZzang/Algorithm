#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	vector<int> less;
	vector<int> greater;
	int a, b, i;


	//K보다 작은 값들만 less에 저장
	for (i = 0; i<scoville.size(); i++) {
		if (scoville[i] < K) {
			less.push_back(scoville[i]);
		}
		else greater.push_back(scoville[i]);
	}

	sort(less.begin(), less.end());

	if (less.size() == 0) return 0;

	while (less.size() > 1) {
		a = less[0], b = less[1]; //제일 작은 원소 2개
		less.erase(less.begin(), less.begin() + 2);
		a = a + b * 2;
		if (a < K) {//순환해서 less의 적당한 자리에 insert
			for (i = 0; i<less.size()&& less[i] < a; i++);
			less.insert(less.begin() + i, a);
		}
		else greater.push_back(a);
		answer++;
	}

	if (less.size() == 1) {
		if (greater.size() > 0) return answer + 1;
		else return -1;
	}

	return answer;
}

int main() {
	cout << solution({ 1, 2, 3, 9, 10, 12 }, 7);

	system("pause");
}