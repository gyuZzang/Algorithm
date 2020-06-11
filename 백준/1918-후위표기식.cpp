#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>
#include <Windows.h>

using namespace std;


//���� 1918 ���� ǥ���
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
			//()���̿� ��� ��ȣ ���

			st_ch.pop();//'(' pop���ֱ�
		}
		else if (is_it_char(ch)) {

			if (st_ch.empty())
			{
				st_ch.push(ch);
				continue;
			}
			
			while( !st_ch.empty() && number(ch) <= number(st_ch.top()) ) //push �Ϸ��� ��ȣ�� �켱���� ������ �ȿ��� ���� (���Ϲ��ߴٰ� �ϴ� �̷��� ��ħ)
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

