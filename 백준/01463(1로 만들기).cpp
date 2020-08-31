//#include<iostream>
//
//using namespace std;
//
//int num[6];
//
//void init_num() {
//	for (int i = 0; i < 6; i++) {
//		num[i] = 0;
//	}
//}
//
//
//int main() {
//	int N, sum;
//	cin >> N;
//	int res = N, cnt=0, save=0;
//	//1. 3으로 나눌 수 있으면 나눔
//	//2. -1해서 3으로 나눌 수 있으면 나눔
//	//3. 2로 나눌 수 있으면 나눔
//	//4. 다 안되면 -1.
//
//	//2, 3 순서가 '16'인 경우 적용 x
//
//	while (res!=1) {
//		N = res;
//		init_num();
//		sum = 0;
//		if (res == 16) {
//			cnt += 4;
//			break;
//		}
//		for (int i = 0; N > 0; i++) {
//			sum += num[i] = N % 10;
//			N /= 10;
//		}
//
//		if (sum % 3 == 0) {
//			res /= 3;
//		}
//		else if (sum % 3 == 1) {
//			res--;
//		}
//		else {
//			if (num[0] % 2 == 0) {
//				res /= 2;
//			}
//			else res--;
//		}
//
//		//cout << res << endl;
//		cnt++;
//
//	}
//	
//	cout << cnt;
//}