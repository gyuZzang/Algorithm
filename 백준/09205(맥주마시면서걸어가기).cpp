//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//
//int compare(pair<int, int>a, pair<int, int>b) {
//	return a.first + a.second < b.first + b.second;
//}
//
//int main() {
//	int t,n;//# of test case, # of conv store
//	vector<vector<pair<int, int>>> conv;
//	vector<pair<int, int>> home, dest;
//	int temp_r, temp_c;//home 0으로 땡기기
//	int num_of_beer=20;
//	pair<int, int> now;
//	pair<int, int> now_dest;
//	int visiting_conv=0;
//
//	cin >> t;
//	conv.resize(t);
//	home.resize(t);
//	dest.resize(t);
//
//	//init
//	for (int j = 0; j < t; j++) {
//		temp_r = temp_c= 0;
//		cin>>n;
//		conv[j].resize(n);
//		cin >> home[j].first >> home[j].second;
//		if (home[j].first != 0 || home[j].second != 0) {
//			temp_r = home[j].first;
//			temp_c = home[j].second;
//		}
//		for (int i = 0; i < n; i++) {
//			cin>>conv[j][i].first>>conv[j][i].second;
//			conv[j][i].first -= temp_r;
//			conv[j][i].second -= temp_c;
//		}
//		cin >> dest[j].first >> dest[j].second;
//		dest[j].first -= temp_r;
//		dest[j].second -= temp_c;
//	}
//
//
//	for (int j = 0; j < t; j++) {
//		//편의점 sorting - 집에서 가까운 순서대로,목적지에서 먼 순서대로
//		sort(conv[j].begin(),conv[j].end(),compare);
//		//cout<< conv[j][0].first<<" "<<conv[j][0].second<<endl;
//
//		//반복
//		now = home[j];
//		now_dest = dest[j];
//		visiting_conv = 0;
//			
//		while (1) {
//
//			//현재-dest< 1000면 그냥 바로 happy
//			if (abs(now_dest.first - now.first)+abs(now_dest.second- now.second) <= 1000) {
//				cout << "happy"<<endl;
//				break;
//			}
//			//갈 곳 없으면 sad
//			if (abs(conv[j][visiting_conv].first - now.first) + abs(conv[j][visiting_conv].second - now.second) > 1000) {
//				cout << "sad" << endl;
//				break;
//			}	
//
//			//현재->남은 맥주로 가능한 최대한 먼 편의점(못갈때까지 linear search)
//			for (; visiting_conv<n && abs(conv[j][visiting_conv].first-now.first)  + abs(conv[j][visiting_conv].second - now.second) <= 1000; visiting_conv++);
//
//			//now 업데이트
//			now = conv[j][visiting_conv-1];
//
//			//편의점 다들렸는데도 없으면 sad
//			if (visiting_conv == n && abs(now_dest.first - now.first) + abs(now_dest.second - now.second) >1000) {
//				cout << "sad" << endl;
//				break;
//			}
//
//			//맥주 개수 20으로 업데이트
//			num_of_beer = 20;
//
//		}
//
//	}
//
//	return 0;
//}