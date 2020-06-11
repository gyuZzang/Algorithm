#include <string>
#include <vector>
#include <windows.h>
#include <iostream>

using namespace std;

int solution(int n) {
	int answer = 1;
	int sum = 0;

	for (int i = 1; i <= n / 2 + 1; i++) {
		sum = 0;
		for (int j = i; sum <=n; j++) {
			if (sum == n)
			{
				answer++;
				break;
			}
			else sum += j;
		}
	}
	return answer; 
}

int main() {
	int n;
	cin >> n;
	cout << solution(n);

	system("pause");
}