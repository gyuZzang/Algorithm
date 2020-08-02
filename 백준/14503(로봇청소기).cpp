#include <iostream>
#include <vector>

#define CLEAN 2;
#define condition cond!=0&&m[r][c]==0
#define LeftSide if(d==0&&c!=1)c--; else if(d==1&&r!=1)r--; else if(d==2&&c<M-2)c++; else if(d==3&&r<N-2) r++; else cond=0;
#define GoBack if(d==0&&r<N-2)r++; else if(d==1&&c!=1)c--; else if(d==2&&r!=1)r--; else if(d==3&&c<M-2)c++; else cond=0;


using namespace std;

void print_m(vector<vector<int>>m, int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int N, M; //세로 가로
	int r, c;//위치
	int d;//방향
	int cond = 1;

	int cnt = 0;

	vector<vector<int>> m;

//init
	cin >> N >> M >> r >> c >> d;
	m.resize(N);
	for (int i = 0; i < N; i++) {
		m[i].resize(M);
		for (int j = 0; j < M; j++) {
			cin >> m[i][j];
		}
	}

//start to move
	while (1) {
		int org_r = r;
		int org_c = c;
		//clean r,c
		m[r][c] = CLEAN;
		cnt++;
		
		//find'
		int i;
		for(i=0;i<4;i++) {//4side
			LeftSide;
			if (condition) {
				//turn
				cond = 1;
				d = (d + 3) % 4;
		
				//cout << cnt << endl;
				//print_m(m, N, M);				
				//cout << "go" <<d<<endl;

				break;
			}

			else {
				//turn
				r = org_r;
				c = org_c;
				cond = 1;
				d = (d + 3) % 4;	
				//cout << "left" <<r<<c<<d<< endl;
				if (i == 3){
					GoBack;
					if (cond != 0 && m[r][c] !=1) {
						//cout << "back" << endl;
						i = -1;
						cond = 1;
						org_c = c; org_r = r;
						continue;
					}
					else {
						cout << cnt;
						system("pause");
						return 0;
					}
				}
				continue;
			}
			
		}
		

	}


}