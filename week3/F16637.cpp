// 16637 - 1차: 이론 실패
#include<bits/stdc++.h>
using namespace std;

vector <int> num;
vector<char> oper;
int answer = INT_MIN;

int operate(int a, int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
}

void solve(int _curIndex, int _curValue) {
	//cout << "curIndex: " << _curIndex << " curValue: " << _curValue << '\n';
	// 종료
	if (_curIndex == num.size()-1) {  
		answer = max(answer, _curValue);
		return;
	}
	// 경우1
	solve(_curIndex + 1, operate(_curValue, num[_curIndex+1], oper[_curIndex]));
	// 경우2
	if (_curIndex != num.size() - 2) {
		int temp = operate(num[_curIndex+1], num[_curIndex + 2], oper[_curIndex+1]);
		int temp2 = operate(_curValue, temp, oper[_curIndex]);
		solve(_curIndex + 2, temp2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n = 0;
	string s = "";

	cin >> n >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) num.push_back(s[i] - '0');
		else oper.push_back( s[i] );
	}

	solve(0, num[0]);
	cout << answer;

	return 0;
}



// (완전 탐색을 할 때는 인덱스를 기반으로 해야한다.)
// 
// <환경>
// 1. 연산은 왼쪽에서 오른쪽으로, 순서대로 진행된다.
// 2. 단 1차원 괄호로 묶을 수 있다.
// 
// =>
// 
// 그러므로 i, i+1, i+2의 상황에서
// i, i+1 먼저 계산하는 경우 1
// i+1, i+2 먼저 계산하는 경우 2
// 이 두가지로 나뉘어진다.
//
// 전체적으로 왼쪽에서 오른쪽까지 DFS 완전탐색을 하게 된다.