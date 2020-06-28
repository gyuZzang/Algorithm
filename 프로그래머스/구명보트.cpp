#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
	int answer = 0;
	int idx_H = people.size()-1, idx_L = 0; //�ε��� ���, ����Ʈ �ʱ�ȭ

	//����
	sort(people.begin(), people.end());


	for (; idx_H >= idx_L; idx_H--) {//�� �ε����� ��ġ�� �ʴ� ������ �񱳹ݺ�
		if (people[idx_L] + people[idx_H] > limit) { //������� ū��� ��>0 �̸� ����Ʈ++
			answer++;
			continue;
		}
		answer++;//�� 0���� ���ų� �۾Ƶ�++
		idx_L++;
		
	}

	return answer;
}

int main() {
	cout<<solution({ 70,50,80,50 }, 100);
	system("pause");
}