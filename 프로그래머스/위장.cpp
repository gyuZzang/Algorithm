#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	map<string, vector<string>> type_to_clothes; 

	//옷종류별로 옷 배열(벡터) 저장.
	for (int i = 0; i < clothes.size(); i++) {
		type_to_clothes[clothes[i][1]].push_back(clothes[i][0]); 
	}

	//조합 계산= 전체곱(종류별 옷 수+1)-1
	for (auto i = type_to_clothes.begin(); i != type_to_clothes.end(); i++) {
		answer *= (i->second.size() + 1);
	}

	return answer-1;
}