#include<bits/stdc++.h>
using namespace std;


int main() {
	string input;
	getline(cin, input);

	int answer = 1;
	for (auto i : input) {
		if (i == ' ') answer++;
	}
	 
	if (input.front() == ' ') answer--;
	if (input.back() == ' ') answer--;

	cout << answer;
	return 0;
}

// 공백 개수 세기와 오류
// 문자열 앞뒤 접근방법