#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
vector<int> visited;//�湮 �� ������� ǥ��
stack<string> st;

//begin�� ��� ������Ʈ�� -> ���纸�� target�� ��������� �������� begin(����) update, stack �̿��Ͽ� ��Ʈ��ŷ.

int count_diff(string a, string b) {//�� ��Ʈ������ ���� �� ���� ���ĺ��� �ٸ���?
	if (a.size() != b.size()) return -1;
	int differ_cnt = 0;

	for (int i = 0; i < a.size(); i++) {
		if (a.c_str()[i] != b.c_str()[i])
			differ_cnt++;
	}
	
	return differ_cnt;
}

int dfs(string begin, string target, vector<string>words, int now_diff) {
	//��ü �ݺ�...dfs ��߰ڴ�
	int i;

	for (i = 0; i < words.size(); i++) {
		//�� �ܾ��� ���ĺ� ����=1 && �����ܰ�-target���̺��� ����i-targe���̰� �۰ų�,
		if (1 == count_diff(begin, words[i]) && now_diff > count_diff(target, words[i]) && visited[i] == 0) {
			//now_diff ������Ʈ, ���� �߰�, �湮 �ߴٴ� ǥ��(1)
			now_diff = count_diff(target, words[i]);
			begin = words[i];
			st.push(words[i]);
			//cout << "push " << words[i] << endl;
			visited[i] = 1;
			break;
		}
	}
	if (i == words.size()) {//�� ���Ҵµ� ���� ������ ������ �����ɷ�
		for (i = 0; i < words.size(); i++) {
			//�� �ܾ��� ���ĺ� ����=1 && �����ܰ�-target���̺��� ����i-targe���̰� ������ ������ ���ƾ���.
			if (1 == count_diff(begin, words[i]) && now_diff == count_diff(target, words[i]) && visited[i] == 0) {
				//now ������Ʈ(���� �߰�), �湮 �ߴٴ� ǥ��(1)
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
		//begin ��� ������Ʈ �ϴٰ� target�� �������� ��!
		int answer = st.size();
		return answer;
	}
	

	//�� ã�Ҵµ� target�� �ƴϰ� �� �� ����! ==> �ٸ� �� ���������� ���� pop, begin �缳��
	if (i == words.size()) {
		cout <<"pop " <<st.top()<<endl;
		st.pop();
		while (!st.empty()) {
			begin = st.top();
			for (i = 0; i < words.size(); i++) {//�� ���ư� ���� �ִ�?
				if (1 == count_diff(begin, words[i]) && now_diff >= count_diff(target, words[i]) && visited[i] == 0) {
					return dfs(begin, target, words, now_diff);
				}
			}
			if (i == words.size()) {
				cout << "pop " << st.top() << endl;
				st.pop();//������ pop
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

	//word�� target������ 0��ȯ
	//if (find(words.begin(), words.end(), target) == words.end()) return 0; ���� �̰ŷ� �ϰ��ʹµ� ���α׷��ӽ������� ���� x
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
