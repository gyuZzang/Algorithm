#include<iostream>
#include<vector>
#include<queue>
#include<stack>
//delay q 쓰지 말고 전체 N*N for문으로 돌기!

using namespace std;

int check_diff(int a, int b, int L, int R) {//범위 내 -> 1반환
	int diff = abs(a - b);
	if (diff <= R && diff >= L) return 1;
	else return 0;
}

int main() {
	int N, L, R; //n개 grid. l이상 r이하
	vector<vector<int>> m;
	vector<vector<pair<int, int>>> unions; //연합 연결 리스트(r,c)
	vector<vector<int>> visited;
	//queue<pair<int, int>> q;
	stack<pair<int, int>> st;
	queue<pair<int, int>> delay_q;
	pair<int, int> tmp;
	int check=0;
	int union_idx = 0;
	int sum = 0;
	int ans = 0;
	int dr[] = { 1,-1,0,0 };
	int dc[] = { 0,0,-1,1 }; //상하좌우 순서

	//더 좋은 방법! unions 일차원 벡터로 하고 매 unions마다 clear. + union_cnt로 조건문 완성
	//이 아니었따.
	cin >> N >> L >> R;

	//init var
	m.resize(N);
	visited.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(N);
		visited[i].resize(N, 0);
		for (int j = 0; j < N; j++) {
			cin >> m[i][j];
		}
	}
	while(1){
		//unions clear.
		for (int i = 0; i < unions.size(); i++) {
			unions[i].clear();
		}
		unions.clear();
		union_idx = 0;

		//check union area 대기 큐가 empty될 때 까지!
		for (int k = 0; k < N; k++) {
			for (int l = 0; l < N; l++) {
				if (visited[k][l] == 0) {
					pair<int, int> start = { k,l };
					st.push(start);
					visited[start.first][start.second] = 1;

					while (!st.empty()) {
						tmp = st.top();
						st.pop();
						check = 0;
						//여기서 상하좌우 bfs로! 범위안에 들면 q에 넣고 (union마지막값 체크 후) union 형성, 아니면 대기 큐에!
						for (int i = 0; i < 4; i++) {
							int nr = tmp.first + dr[i];
							int nc = tmp.second + dc[i];

							if (nr >= 0 && nc >= 0 && nr < N && nc < N ) {
								if (check_diff(m[tmp.first][tmp.second], m[nr][nc], L, R)) {//lr 범위 안에 있으면
									check++;
									if (visited[nr][nc] == 0) {
										visited[nr][nc] = 1;
										st.push({ nr,nc });//q에 푸쉬
									}

								}
							}
						}

						if(check!=0) {
							//2개이상(union)인게 확정되면 union에 push, q비워질때까지 같은 union
							if (unions.size() == union_idx) {
								unions.push_back({ tmp });
							}
							else {
								unions[union_idx].push_back(tmp);
							}
						}
					}//union 하나 끝!
					if (unions.size() > union_idx) {
						union_idx++;
					}

				}
			}
		}
			
		if (unions.empty()) break;
		for (int i = 0; i < unions.size(); i++) {//같은 union끼리 평균 값 업데이트 후
			for (auto j : unions[i]) {
				//cout << "{" << j.first << "," << j.second <<"}"<< endl;
				sum += m[j.first][j.second];
			}
			sum /= unions[i].size();
			for (auto j : unions[i]) {
				m[j.first][j.second] = sum;
			}
			sum = 0;
		}
		for (int i = 0; i < N; i++) {//visited reset하고  
			for (int j = 0; j < N; j++) {
				//cout << m[i][j] << ' ';
				visited[i][j] = 0;
			}
			//cout << endl;
		}
		ans++;
		//cout << endl;
	}
		

	cout << ans;

}
