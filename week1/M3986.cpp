#include <bits/stdc++.h>
using namespace std;
int n, answer;
string input;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> input;
		stack<char> stk;
		for (auto i : input) {
			if (stk.size() && stk.top() == i) stk.pop();
			else stk.push(i);
		}
		if (stk.size() == 0) answer++;
	}

	cout << answer << "\n";
	return 0;
}

// 1차 시도 코드_미완성
/*
#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string input;
char a, b;
int main() {
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	cin >> n;

	while (n--) {
		cin >> input;

	}
}

string fun(string _input) {
	a, b = ' ';
	for (int i = 0; i < _input.size(); i++) {
		b = i;
		if (a == b) {

		}
	}
}
*/
/*
내가 생각한 알고리즘
1. 입력받은 문자열을 재귀함수로 돌린다.
2. 재귀함수에서는 연속된 문자가 2개 있으면 삭제한다.
3. 최종적으로 모든 문자가 삭제되면 좋은 단어로 판단한다.

개선 가능한 부분 
1. 짝짓기, 폭발 문제 -> stack
*/

/*
* #include<bits/stdc++.h> 
using namespace std;  
int n, ret; 
string s; 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> s; 
		stack<char> stk;
		for(char a : s){
			if(stk.size() && stk.top() == a)stk.pop();
			else stk.push(a); 
		} 
		if(stk.size() == 0)ret++;
	}
	cout << ret << "\n"; 
}
*/