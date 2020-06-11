#include <string>
#include <vector>
#include <iostream>
#include <Windows.h>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int n = prices.size();
	int cnt;
	for (int j = 0; j < n; j++) {
		cnt = 0;
		for (int i = j+1; i < n; i++) {
			cnt++;
			if (prices[j] <= prices[i]) {
				continue;
			}
			else break;
		}
		answer.push_back(cnt);
	}
	return answer;
}
int main() {
	vector<int> a = { 1,2,3,2,3 };
	vector<int> res = solution(a);
	for (int t = 0; t < res.size(); t++) {
		cout << res[t]<< ", ";
	}


	system("pause");
}