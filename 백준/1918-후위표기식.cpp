#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <Windows.h>

using namespace std;


//백준 1918 후위 표기식
bool is_it_char(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
		return true;
	}
	else return false;
}

int number(char ch) {
	if (ch == '+' || ch == '-')
		return 1;
	else if (ch == '*' || ch == '/')
		return 2;
	else 
		return 0;

}


int main() {
	char input[101] = {};
	vector<char> res;
	stack<char>st_ch;
	char ch;
	cin >> input;

	for (int i = 0; i<strlen(input); i++) {
		ch = input[i];
		if (ch == '(')
		{
			st_ch.push(ch);
		}
		else if (ch == ')')
		{
			while (st_ch.top() != '(')
			{
				res.push_back(st_ch.top());
				st_ch.pop();
			}
			//()사이에 모든 기호 출력

			st_ch.pop();//'(' pop해주기
		}
		else if (is_it_char(ch)) {

			if (st_ch.empty())
			{
				st_ch.push(ch);
				continue;
			}
			
			while( !st_ch.empty() && number(ch) <= number(st_ch.top()) ) //push 하려는 기호가 우선순위 작으면 안에꺼 빼내 (와일문했다가 일단 이렇게 고침)
			{
				res.push_back(st_ch.top());
				st_ch.pop();
			

			}	st_ch.push(ch);
		}
		else res.push_back(ch);
	}
	while (!st_ch.empty())
	{
		res.push_back(st_ch.top());
		st_ch.pop();
	}

	for (int i = 0; i < res.size(); i++)
		cout << res[i];

	system("pause");
}

