#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> r1, vector<int> r2) {
	if (r1[0] == r2[0])
		return r1[1] < r2[1];
	else return r1[0] < r2[0];
}

int solution(vector<vector<int>> routes) {
	int answer = 0;
	int now = 0;
	vector<int> res;

	sort(routes.begin(), routes.end(), compare);//진입 시간(같으면 진출시간)에 따른 정렬

	now = routes[0][1];

	for (int i = 1; i < routes.size(); i++) {
		if (now < routes[i][0])
		{
			res.push_back(now);
			now = routes[i][1];
			continue;
		}
		else if (now > routes[i][1])
		{
			now = routes[i][1];
			continue;
		}

	}
	if (now != res.back())
		res.push_back(now);
	answer = res.size();
	return answer;
}

int main() {
	vector<vector<int>> a = { {5, 8},{0, 5},{0, 4},{2, 3},{4,5} };

	cout << solution(a);


	system("pause");
}