#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare_m(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

bool compare_sum(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second; //��������
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	map<string, vector<pair<int, int>>> music; //�帣, vector(�÷���Ƚ��, �ε���) ����.
	vector<pair<string, int>> summation;// �帣�� �÷��� �� Ƚ�� ����.
	
	for (int i = 0; i < genres.size(); i++) {
		music[genres[i]].push_back(make_pair(plays[i],i));
	}

	for (auto i = music.begin(); i != music.end(); i++) {
		int sum = 0;

		sort((i->second).begin(), (i->second).end(), compare_m); 

		for (int j = 0; j < i->second.size(); j++) {
			sum += i->second[j].first;
		}
		summation.push_back(make_pair(i->first,sum)); 
	}
	sort(summation.begin(), summation.end(),compare_sum);
	
	for (auto i = summation.begin(); i != summation.end(); i++) {
		answer.push_back(music[i->first][0].second);
		if(music[i->first].size()>1) answer.push_back(music[i->first][1].second);
	}

	return answer;
}
int main() {
	vector<int> res = solution({ "c","p","c","c","p" }, { 500,600,150,800,2500 });

	system("pause");
}