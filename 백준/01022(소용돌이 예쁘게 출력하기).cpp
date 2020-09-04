#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;

int main() {
	//1~9999^2  ==> int ����!

	int r1, r2, c1, c2;
	int R, C;
	vector<vector<int>> m;

	cin >> r1 >> c1 >> r2 >> c2;

	R = r2 - r1 + 1;
	C = c2 - c1 + 1;

	m.resize(R);
	for (int i = 0; i < R; i++) {
		m[i].resize(C);
	}

	//(r1,c1) ���ϱ�
	if (abs(r1) >= abs(c1)) {//������
		if (r1 > 0) {
			m[0][0] = pow(2 * r1 + 1, 2) - (r1 - c1);
		}
		else {
			m[0][0] = pow(2 * abs(r1) - 1, 2) + 2 * abs(r1) - (c1 + r1);
		}
	}
	else {//�����
		if (c1 > 0) {
			m[0][0] = pow(2 * c1 - 1, 2) + (c1 - r1);
		}
		else {
			m[0][0] = pow(2 * abs(c1) + 1, 2) - 2 * abs(c1) - (c1 - r1);
		}
	}
	//cout << m[0][0];
	int idx_r = r1;
	int idx_c = c1;
	int pm_c = idx_c < 0 ? 1 : -1;
	int pm_r = idx_r < 0 ? -1 : 1;

	for (int i = 0; i < R; i++) {
		idx_c = c1;
		if (i != 0) {//�� row�� ù column�� ����.
			if (idx_r < 0) {
				if (abs(idx_c) < abs(idx_r)) { //�ٸ� ����?�� ���� ��
					m[i][0] = m[i - 1][0] - (3 + abs(idx_r + 1) * 8);
				}
				else {//���� ����
					m[i][0] = m[i-1][0] + pm_c;
				}
			}
			else {
				if (abs(idx_c) <= abs(idx_r)) { //�ٸ� ����?�� ���� ��
					m[i][0] = m[i - 1][0] + (7 + abs(idx_r) * 8);
				}
				else {//���� ����
					m[i][0] = m[i - 1][0] + pm_c;
				}
			}
			idx_r++;
			pm_r= idx_r < 0 ? -1 : +1;
		}
		for (int j = 1; j < C; j++) {
			if (idx_c < 0) {
				if (abs(idx_c) > abs(idx_r)) { //�ٸ� ����?�� ���� ��
					m[i][j] = m[i][j - 1] - (5 + abs(idx_c + 1) * 8);

				}
				else {//���� ����
					m[i][j] = m[i][j - 1] + pm_r;
				}
			}
			else {
				if (idx_c!=idx_r && abs(idx_c) >= abs(idx_r)) { //�ٸ� ����?�� ���� ��
					m[i][j] = m[i][j - 1] + (1 + abs(idx_c) * 8);

				}
				else {//���� ����
					m[i][j] = m[i][j - 1] + pm_r;
				}
			}
			idx_c++;
		}
	}


	int max_num=m[0][0];
	int max_len;

	//��� ���̸� �ִ밪�� ���̿� ����
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			max_num = max(max_num, m[i][j]);
		}
	}
	max_len = to_string(max_num).size();

	//print
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%*d ", max_len, m[i][j]);
		}
		cout << endl;
	}
	////���� ���� ��
	//int n = 4;
	//printf("%*d\n", n, 1);
	//printf("%*d\n", n, 100);
}