// 1062
// 1회차 - 성공 (2시간) 
#include<bits/stdc++.h>
using namespace std;

int n, k, core, maxCnt = INT_MIN;
string s;
vector<int> v;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (k < 5) {
		cout << 0;
		return 0;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> s;
		int tmp = 0;
		for (int j = 0; j < s.length(); j++) {
			tmp |= (1 << int(s[j] - 'a'));
		}
		v.push_back(tmp);
	}

	core |= (1 << int('a' - 'a'));
	core |= (1 << int('n' - 'a'));
	core |= (1 << int('t' - 'a'));
	core |= (1 << int('i' - 'a'));
	core |= (1 << int('c' - 'a'));

	for (int i = 0; i < (1 << 26); i++) {
		if (core != (i & core)) continue; // 필수 단어가 포함되어 있지 않으면 넘기기
		int cnt = 0;
		bool flag = true;
		for (int j = 0; j < 26; j++) {
			if (1 << j & core) continue;// 필수 단어이면 넘기기
			else if (i & (1 << j)) {cnt++;}
			if (cnt > k - 5) {	// 포함된 문자가 초과되는 경우
				flag = false;
				break;
			}
		}
		if (cnt < k - 5) flag = false;	// 포함된 문자가 미달되는 경우
		if (!flag) continue;
		int wardCnt = 0;
		for (auto j : v) if (j == (j & i)) {wardCnt++;}
		maxCnt = max(maxCnt, wardCnt);
	}

	cout << maxCnt;
	return 0;
}

// 문제시작 8:31
// 코딩시작 8:33
// 중단 8:48~9:00
// 1차 완성 9:15
// 중단 9:49~10:05
// 성공 10:25


// 1. 요소의 인덱스를 나타내는 숫자와 2진법의 자리를 나타내는 숫자를 구별하지 못함

// 2. 비트를 포함하는지 검사하기
// t: 검사대상 2진수, c: 포함해야하는 2진수
// 
// 1개의 비트가 포함되어 있는지 검사하기
// t & c 
//
// 여러 개의 비트가 포함되어 있는지 검사하기
// c == (t&c)	// 포함시, true

// 개선점
// (강의의 해답을 이해하지 못함)