#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N, L; //N:# of grid(2~100), L:length of slope(1~N)
	vector<vector<int>> m;
	vector<vector<int>> slope;
	int j,k; //index of forloop
	int ans=0;

	cin >> N >> L;

	m.resize(N);
	slope.resize(N+1);//index==N에는 지나갈 수 있는지 여부

	for (int i = 0; i < N; i++) {
		m[i].resize(N);
		slope[i].resize(N+1, 0);
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}
	slope[N].resize(N + 1, 0);

	//start checking!
	for (int i = 0; i < N; i++) {
		//row
		for (j = 1; j < N; j++) {
			if (abs(m[i][j - 1] - m[i][j]) > 1) {//1이상 차이나면 불가능
				slope[i][N] = -1;
				//cout << i << "번째 row 실패!" << endl;
				break;
			}
			if (m[i][j - 1] > m[i][j]) {//작아지면
				for (k = 0; k < L && j+k<N && m[i][j] == m[i][j + k] && slope[i][j+k] == 0; k++); //slope 놓을 자리 확인
				if (k == L) {
					for (k = 0; k < L; k++) slope[i][j + k] = 1;
					j += L-1;
				}
				else {
					slope[i][N] = -1;
					//cout << i << "번째 row 실패!" << endl;
					break;
				}
			}
			else if (m[i][j - 1] < m[i][j])//커지면
			{
				for (k = 1; k <= L && j-k>=0 && m[i][j-1] == m[i][j - k] && slope[i][j-k] == 0; k++); //slope 놓을 자리 확인
				if (k == L + 1) {
					for (k = 1; k <= L; k++) slope[i][j - k] = 1;
				}
				else {
					slope[i][N] = -1;
					//cout << i << "번째 row 실패!" << endl;
					break;
				}
			}
		}
		//가로세로 겹쳐서 생각 안하는 듯 아마? => 초기화 해줘야함
		for (j = 0; j < N; j++) {
			slope[i][j] = 0;
		}
		//col
		for (j = 1; j < N; j++) {
			if (abs(m[j - 1][i] - m[j][i]) > 1) {//1이상 차이나면 불가능
				slope[N][i] = -1;
				//cout << i << "번째 col 실패!" << endl;
				break;
			}
			if (m[j - 1][i] > m[j][i]) {//작아지면
				for (k = 0; k < L && j + k < N && m[j][i] == m[j + k][i] && slope[j + k][i] == 0; k++); //slope 놓을 자리 확인
				if (k == L) {
					for (k = 0; k < L; k++) slope[j + k][i] = 1;
					j += L-1;
				}
				else {
					slope[N][i] = -1;
					//cout << i << "번째 col 실패!" << endl;
					break;
				}
			}
			else if (m[j - 1][i] < m[j][i])//커지면
			{
				//TO DO: 예제 1의 4번째 col에서 slope 1겹쳐도 cnt 안되는 듯?
				for (k = 1; k <= L && j - k >= 0 && m[j-1][i] == m[j - k][i] && slope[j - k][i] == 0; k++); //slope 놓을 자리 확인
				if (k == L + 1) {
					for (k = 1; k <= L; k++) slope[j - k][i] = 1;
				}
				else {
					slope[N][i] = -1;
					//cout << i << "번째 col 실패!" << endl;
					break;
				}
			}
		}
		//가로세로 겹쳐서 생각 안하는 듯 아마? => 초기화 해줘야함
		for (j = 0; j < N; j++) {
			slope[j][i] = 0;
		}

		
	}

	//count usable road 
	for (int i = 0; i < N; i++) {
		if (slope[i][N]==0) ans++;
		if (slope[N][i]==0) ans++;
	}

	cout << ans;
}