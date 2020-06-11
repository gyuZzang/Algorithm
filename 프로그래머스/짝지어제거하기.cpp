#include<iostream>
#include<string>
#include<vector>
#include<Windows.h>
using namespace std;

int solution(string s)
{
	int answer = 0;
	vector<char> c(s.begin(),s.end());

	vector<char>::iterator i=c.begin();
	while (i < c.end()-1) {
		if (*i == *(i+1)) {
			i= c.erase(i);
			i = c.erase(i);
			i = c.begin(); continue;
		}
		else i++;

	}
	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	if (c.empty()) answer=1;
	cout << answer << endl;

	return answer;
}
int main() {
	string s = "cbcb";
	solution(s);

	system("pause");
}