#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
vector<int> visited;//방문 한 노드인지 표시
stack<string> st;

//begin을 계속 업데이트함 -> 현재보다 target에 가까워지는 방향으로 begin(현재) update, stack 이용하여 백트래킹.

int count_diff(string a, string b) {//두 스트링에서 서로 몇 개의 알파벳이 다른가?
	if (a.size() != b.size()) return -1;
	int differ_cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a.c_str()[i] != b.c_str()[i])
			differ_cnt++;
	}
	
	return differ_cnt;
}

int dfs(string begin, string target, vector<string>words, int now_diff) {
	//전체 반복...dfs 써야겠다
	int i;

	for (i = 0; i < words.size(); i++) {
		//두 단어의 알파벳 차이=1 && 이전단계-target차이보다 현재i-targe차이가 작거나,
		if (1 == count_diff(begin, words[i]) && now_diff > count_diff(target, words[i]) && visited[i] == 0) {
			//now_diff 업데이트, 스택 추가, 방문 했다는 표시(1)
			now_diff = count_diff(target, words[i]);
			begin = words[i];
			st.push(words[i]);
			//cout << "push " << words[i] << endl;
			visited[i] = 1;
			break;
		}
	}
	if (i == words.size()) {//다 돌았는데 차이 작은게 없으면 같은걸로
		for (i = 0; i < words.size(); i++) {
			//두 단어의 알파벳 차이=1 && 이전단계-target차이보다 현재i-targe차이가 작은거 없으면 같아야함.
			if (1 == count_diff(begin, words[i]) && now_diff == count_diff(target, words[i]) && visited[i] == 0) {
				//now 업데이트(스택 추가), 방문 했다는 표시(1)
				now_diff = count_diff(target, words[i]);
				begin = words[i];
				st.push(words[i]);
				cout <<"push " <<words[i]<<endl;
				visited[i] = 1;
				break;
			}
		}
	}

	if (begin == target) {
		//begin 계속 업데이트 하다가 target과 같아지면 끝!
		int answer = st.size();
		return answer;
	}
	

	//다 찾았는데 target도 아니고 갈 곳 없다! ==> 다른 길 있을때까지 스택 pop, begin 재설정
	if (i == words.size()) {
		cout <<"pop " <<st.top()<<endl;
		st.pop();
		while (!st.empty()) {
			begin = st.top();
			for (i = 0; i < words.size(); i++) {//더 나아갈 곳이 있니?
				if (1 == count_diff(begin, words[i]) && now_diff >= count_diff(target, words[i]) && visited[i] == 0) {
					return dfs(begin, target, words, now_diff);
				}
			}
			if (i == words.size()) {
				cout << "pop " << st.top() << endl;
				st.pop();//없으면 pop
			}
		}
	}
	else return dfs(begin, target, words, now_diff);

}


int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	int i;
	int now_diff = count_diff(begin, target);
	visited.resize(words.size(),0);

	//word에 target없으면 0반환
	//if (find(words.begin(), words.end(), target) == words.end()) return 0; 원래 이거로 하고팠는데 프로그래머스에서만 실행 x
	for (i = 0; i < words.size(); i++) {
		if (words[i] == target) break;
	}
	if (i == words.size()) return 0;


	answer=dfs(begin, target, words, now_diff);


	return answer;
}

int main() {
	cout << endl<<solution("hit", "cog", { "hot", "dot", "dog", "lot", "log", "cog" }) << endl;
	cout << endl << solution("hit", "cog", { "hot","dot","dog","lot","log" }) << endl;
	system("pause");
}
