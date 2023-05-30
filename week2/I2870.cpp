// 2870
// 100 글자 -> 숫자로 표현 불가
// 아스키코드 65 97 -> c<65 이면 숫자
#include<bits/stdc++.h>
using namespace std;

int n;
string s, t;
vector<string> v;

// 토큰을 v에 추가하기
void go(){
	// 0 삭제
	while (1) {
		if (t.size() && t.front() == '0') t.erase(t.begin());
		else break;
	}
	// 토큰의 0을 다 삭제한 경우 -> 0으로 설정
	if (t.size() == 0) t = '0';
	v.push_back(t);
	t = "";
}

// string으로 된 숫자를 오름차순 정렬하는 함수
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n--) {
		cin >> s;
		// 숫자와 문자 분류하여 토큰에 추가 및 v에 추가
		for (auto i : s) {
			// 숫자면 토큰에 추가
			if (i < 65) t += i;
			// 문자일 때 문자는 무시되고 토큰을 v에 저장하는 시퀀스
			// (단, 토큰을 추가해야 하므로, 토큰에 문자가 있어야 함)
			else if(t.size()) go();
		}
		// 마지막 토큰을 v에 추가하는 용도
		if (t.size()) go();
	}
	sort(v.begin(), v.end(), cmp);
	for (auto i : v) cout << i << "\n";
	return 0;
}