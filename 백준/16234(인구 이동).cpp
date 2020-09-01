#include<iostream>
#include<vector>
#include<queue>
#include<stack>
//delay q ���� ���� ��ü N*N for������ ����!

using namespace std;

int check_diff(int a, int b, int L, int R) {//���� �� -> 1��ȯ
	int diff = abs(a - b);
	if (diff <= R && diff >= L) return 1;
	else return 0;
}

int main() {
	int N, L, R; //n�� grid. l�̻� r����
	vector<vector<int>> m;
	vector<vector<pair<int, int>>> unions; //���� ���� ����Ʈ(r,c)
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
	int dc[] = { 0,0,-1,1 }; //�����¿� ����

	//�� ���� ���! unions ������ ���ͷ� �ϰ� �� unions���� clear. + union_cnt�� ���ǹ� �ϼ�
	//�� �ƴϾ���.
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

		//check union area ��� ť�� empty�� �� ����!
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
						//���⼭ �����¿� bfs��! �����ȿ� ��� q�� �ְ� (union�������� üũ ��) union ����, �ƴϸ� ��� ť��!
						for (int i = 0; i < 4; i++) {
							int nr = tmp.first + dr[i];
							int nc = tmp.second + dc[i];

							if (nr >= 0 && nc >= 0 && nr < N && nc < N ) {
								if (check_diff(m[tmp.first][tmp.second], m[nr][nc], L, R)) {//lr ���� �ȿ� ������
									check++;
									if (visited[nr][nc] == 0) {
										visited[nr][nc] = 1;
										st.push({ nr,nc });//q�� Ǫ��
									}

								}
							}
						}

						if(check!=0) {
							//2���̻�(union)�ΰ� Ȯ���Ǹ� union�� push, q����������� ���� union
							if (unions.size() == union_idx) {
								unions.push_back({ tmp });
							}
							else {
								unions[union_idx].push_back(tmp);
							}
						}
					}//union �ϳ� ��!
					if (unions.size() > union_idx) {
						union_idx++;
					}

				}
			}
		}
			
		if (unions.empty()) break;
		for (int i = 0; i < unions.size(); i++) {//���� union���� ��� �� ������Ʈ ��
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
		for (int i = 0; i < N; i++) {//visited reset�ϰ�  
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
