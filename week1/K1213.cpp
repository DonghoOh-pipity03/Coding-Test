#include <bits/stdc++.h>
using namespace std;

string input, output, s_tmp;
map<char, int> abc;
int oddCnt, tmp;
char oddChar;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> input;

	for (auto i : input) abc[i]++;

	for (auto i : abc) {
		if (i.second % 2 == 1) {
			oddChar = i.first;
			oddCnt++;
			if (oddCnt >= 2) {
				cout << "I'm Sorry Hansoo" << "\n";
				return 0;
			}
		}
		tmp = i.second / 2;
		while (tmp--) output += i.first;
	}

	s_tmp += output;
	if (oddCnt == 1) output += oddChar;
	reverse(s_tmp.begin(), s_tmp.end());
	output += s_tmp;

	cout << output << "\n";

	return 0;
}


/*
1. map에 철자를 모은다.
2. 철자 중 홀수개가 2개 이상이면 암쏘리를 출력한다.
3. 첫번째부터 끝까지 절반갯수만 이어주고, 다시 끝부터 처음까지 절반만 채워 출력한다.

개선 가능 부분
1. 문자열의 개수를 저장할 때는 map보단 배열을 사용해서 저장할 수 있다.
2. 홀수 체크
변수 % 2 == 1 -> 변수 & 1 (비트 연산으로 하는 방법)
*/

/*
#include<bits/stdc++.h>
using namespace std;
string s, ret;
int cnt[200], flag;
char mid;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	for(char a : s)cnt[a]++;
	for(int i = 'Z'; i >= 'A'; i--){
		if(cnt[i]){
			if(cnt[i] & 1){
				mid = char(i);flag++;
				cnt[i]--;	// 중간 홀수 문자 제거
			}
			if(flag == 2)break;
			for(int j = 0; j < cnt[i]; j += 2){	
				ret = char(i) + ret;	// 앞에 문자 추가하기	
				ret += char(i);	// 뒤에 문자 추가하기
			}
		}
	}
	if(mid)ret.insert(ret.begin() + ret.size() / 2, mid);	// 중간에 추가하기
	if(flag == 2)cout << "I'm Sorry Hansoo\n";
	else cout << ret << "\n";
}
*/