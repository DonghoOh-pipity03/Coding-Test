// O 4949 - 짝짓기 - stack
#include<bits/stdc++.h>
using namespace std; 
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (1) {
		getline(cin, s);
		if (s == ".") break;

		bool flag = true;
		stack<char> stk;

		for (char i : s) {
			// ([ 추가
			if (i == '(' || i == '[') stk.push(i);
			// )] 삭제
			if ((i == ')' || i == ']')) {
				if ((stk.size() == 0) || (i == ')' && stk.top() != '(') || (i == ']' && stk.top() != '[')) {
					flag = false;
					break;
				}
				else stk.pop();
			}
		}
		if (stk.size()) flag = false;

		if (flag) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}

// 한 줄 입력 받기 
// getline(cin, s);