#include<iostream>
#include<vector>

using namespace std;

int main() {

	int N, M;
	vector<vector<int>> m;
	vector<vector<int>> max;
	int r = 0, c = 0;

	//init var
	cin >> N >> M;
	m.resize(N);
	max.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		max[i].resize(M, 0);
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

	//오른쪽 or 아래탐색 --> 최대 사탕 개수 계속 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i == 0 && j == 0) max[i][j] = m[i][j];
			else if (i == 0) max[i][j] = max[i][j - 1] + m[i][j];
			else if (j == 0) max[i][j] = max[i - 1][j] + m[i][j];
			else {
				max[i][j] = max[i - 1][j] > max[i][j - 1] ? max[i - 1][j] + m[i][j] : max[i][j - 1] + m[i][j];
			}
		}
	}

	cout << max[N - 1][M - 1];

	return 0;

}