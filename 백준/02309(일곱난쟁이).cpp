#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n[9];
	int sum = 0;
	int i, j;

	for (int i = 0; i < 9; i++) {
		cin >> n[i];
		sum += n[i];
	}

	for (i = 0; i < 9; i++) {
		for (j = i + 1; j < 9; j++) {
			if (sum - n[i] - n[j] == 100) {
				n[i] = n[j] = 101;
				sort(n, n + 9);

				for (int k = 0; k < 7; k++) {
					cout << n[k] << endl;
				}

				return 0;
			}
		}
	}
	
}