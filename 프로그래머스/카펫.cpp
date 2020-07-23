#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;
	int i,q;
	brown = brown / 2 - 2; //= w+h of yellow
	for (i = 1; i <= yellow; i++) {
		if (yellow%i == 0 && yellow/i+i==brown) {
			answer.push_back(yellow / i+2);
			answer.push_back(i+2);
			break;
		}
	}

	return answer;
}
