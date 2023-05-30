#include<bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 0;

	while (1) {
		if (section.empty()) break;

		answer++;
		int roller_left = section.front();
		int roller_right = roller_left + m - 1;
		while (1) {
			if (!section.empty() && section.front() <= roller_right)section.erase(section.begin());
			else break;
		}
	}

	return answer;
}

int main() {
	vector<int> section = { 1, 2, 3, 4 };
	cout << solution(4 ,1, section);
	return 0;
}

// 1. 포인터 유형

// 피드백_벡터 맨 앞 삭제