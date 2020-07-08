#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
	vector<char>num(number.begin(),number.end());
	int max=0, j=0;

	//k==1�϶����� or �����ε���==k�϶����� �ݺ�
	for (j=0 ; k != 1 && j+k<num.size() ; j++)
	{
		max = j;

		//max <- number�� j~j+k�ڸ� �� ���� ū ���� index
		for (int i = j+1; i <= k+j; i++) {
			max=num[max] >= num[i] ? max : i;
		}

		//max�� ���� ó�� index�� j++
		if (max == j) continue;

		//max ������ index������ ��� ����� k ������Ʈ
		num.erase(num.begin()+j, num.begin()+max);
		k -= (max-j);

	}

	//�����ε���==k�� �ڿ� k�� ����.
	if (j + k == num.size()) {
		num.erase(num.end() - k, num.end());
		string answer(num.begin(), num.end());
		return answer;
	}

	//k==1�� ��, idx: num[j]<num[j+1]�̸� num[j]����, j�� �ǵڸ� num[j]����
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