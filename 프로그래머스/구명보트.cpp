#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx_H = people.size()-1, idx_L = 0; //인덱스 헤비, 라이트 초기화

	//정렬
	sort(people.begin(), people.end());


	for (; idx_H >= idx_L; idx_H--) {//두 인덱스가 겹치지 않는 선에서 비교반복
		if (people[idx_L] + people[idx_H] > limit) { //작은사람 큰사람 합>0 이면 구명보트++
			answer++;
			continue;
		}
		answer++;//합 0보다 같거나 작아도++
		idx_L++;
		
	}

	return answer;
}

int main() {
	cout<<solution({ 70,50,80,50 }, 100);
	system("pause");
}