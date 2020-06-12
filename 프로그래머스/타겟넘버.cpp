#include <string>
#include <vector>

using namespace std;


int solution(vector<int> numbers, int target) {
	int answer = 0;
	int n = numbers.size();
	vector<vector<int>> res;

	res.resize(n);

	res[0].push_back(numbers[0]);
	res[0].push_back(-numbers[0]);



	for (int i = 1; i < n; i++) {

		for (int j = 0; j < res[i - 1].size(); j++) {
			res[i].push_back(res[i - 1][j] + numbers[i]);
		}
		for (int j = 0; j < res[i - 1].size(); j++) {
			res[i].push_back(res[i - 1][j] - numbers[i]);
		}
	}

	for (int i = 0; i < res[n - 1].size(); i++) {
		if (res[n - 1][i] == target) answer++;
	}

	return answer;
}