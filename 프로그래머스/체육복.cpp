#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int rsv_idx = 0, lost_idx = 0;
	vector<int> total;//학생별 가진 체육복 수.
	total.resize(n,1);

	sort(reserve.begin(), reserve.end());
	sort(lost.begin(), lost.end());

	//init total
	for (int i = 0; i < n; i++) {
		if (rsv_idx < reserve.size() && i == reserve[rsv_idx] - 1 ) {
			total[i]++;
			rsv_idx++;
		}
		if (lost_idx < lost.size() && i == lost[lost_idx] - 1) {
			total[i]--;
			lost_idx++;
		}
	}

	for (int i = 0; i < n; i++) {
		if (total[i] == 0) {
			if (i != 0 && total[i - 1] == 2) {
				total[i - 1] = 1;
				total[i] = 1;
			}
			else if (i != n - 1 && total[i + 1] == 2) {
				total[i + 1] = 1;
				total[i] = 1;
			}
		}
	}

	answer = n - count(total.begin(), total.end(), 0);
	

	return answer;
}