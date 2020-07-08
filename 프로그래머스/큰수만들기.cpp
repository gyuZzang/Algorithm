#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	vector<char>num(number.begin(),number.end());
	int max=0, j=0;

	//k==1일때까지 or 남은인덱스==k일때까지 반복
	for (j=0 ; k != 1 && j+k<num.size() ; j++)
	{
		max = j;

		//max <- number의 j~j+k자리 중 가장 큰 수의 index
		for (int i = j+1; i <= k+j; i++) {
			max=num[max] >= num[i] ? max : i;
		}

		//max가 제일 처음 index면 j++
		if (max == j) continue;

		//max 이전의 index값들은 모두 지우고 k 업데이트
		num.erase(num.begin()+j, num.begin()+max);
		k -= (max-j);

	}

	//남은인덱스==k면 뒤에 k개 지움.
	if (j + k == num.size()) {
		num.erase(num.end() - k, num.end());
		string answer(num.begin(), num.end());
		return answer;
	}

	//k==1일 때, idx: num[j]<num[j+1]이면 num[j]지움, j가 맨뒤면 num[j]지움
	for ( ; j < num.size(); j++) {
		if (j == num.size() - 1 || num[j] < num[j + 1])
		{
			num.erase(num.begin() + j, num.begin() + j + 1);
			break;
		}
	}
	string answer(num.begin(), num.end());
	return answer ;
}

int main() {
	string res = solution("3331233",3);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i]<<" ";
	}
	system("pause");
}