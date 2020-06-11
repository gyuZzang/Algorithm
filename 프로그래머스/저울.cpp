#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

using namespace std;

//프로그래머스 저울
int solution(vector<int> weight) {
	int answer = 0;

	sort(weight.begin(), weight.end());
	answer = weight[0];

	if (answer != 1) return 1;

	for (int i = 1; i < weight.size(); i++) {
		if (answer + 1 < weight[i])
			return answer+1;
		answer += weight[i];

	}
	return answer+1;
}

