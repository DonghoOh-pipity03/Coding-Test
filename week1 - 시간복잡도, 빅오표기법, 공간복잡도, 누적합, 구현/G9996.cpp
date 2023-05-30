#include <bits/stdc++.h>
using namespace std;
int fileCnt, pos;
string pattern, pre, suf, fileName;
int main() {
	cin >> fileCnt;
	cin >> pattern;
	pos = pattern.find("*");
	pre = pattern.substr(0, pos);
	suf = pattern.substr(pos + 1, pattern.size());
	for (int i = 0; i < fileCnt; i++) {
		cin >> fileName;
		if (pre.size() + suf.size() > fileName.size()) cout << "NE" << endl;
		else if (pre == fileName.substr(0, pos) && 
			suf == fileName.substr(fileName.size() - suf.size(), fileName.size())) cout << "DA" << endl;
		else cout << "NE" << endl;
	}
}

// 1차 코드
/*
#include <bits/stdc++.h>
using namespace std;
int fileCnt, pos;
string pattern, pre, suf, token, ret, temp;
int main() {
	cin >> fileCnt;
	cin >> pattern;
	for (int i = 0; i < 2; i++) {
		pos = pattern.find("*");
		token = pattern.substr(0, pos);
		i == 0 ? pre += token : suf += token;
		pattern.erase(0, pos + 1);
	}
	for (int i = 0; i < fileCnt; i++) {
		cin >> temp;
		if (pre.length() + suf.length() > temp.length()) {
			cout << "NE" << endl;
			continue;
		}
		if (pre != temp.substr(0, pre.length())) {
			cout << "NE" << endl;
			continue;
		}
		if (suf != temp.substr(temp.length() - suf.length(), temp.length())) {
			cout << "NE" << endl;
			continue;
		}
		cout << "DA" << endl;
	}
	return 0;
}
*/

/*
내가 생각한 알고리즘
1. 파일 갯수 입력받기
2. 패턴 입력받기
3. 앞뒤 문자 추출하기
4. for문으로 돌면서 앞뒤 문자 비교하기

개선점
1. 문제 잘못 읽음: *가 하나인 것을 캐치하지 못하고 어렵게 생각함
2. cpp버전 cplit 작성할 줄 알기: find, substr, erase
3. 예외사항을 캐치하지 못함 
(ab*ba -> aba -> 불가 -> 길이로 판단함)
4. string.size()와 string.length()와 같다
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n;
string s, ori_s, pre, suf;
int main(){
	cin >> n;
	cin >> ori_s;
	int pos = ori_s.find('*');
	pre = ori_s.substr(0, pos);
	suf = ori_s.substr(pos + 1);
	for(int i = 0; i < n; i++){
		cin >> s;
		if(pre.size() + suf.size() > s.size()){
			cout << "NE\n";
		}else{
			if(pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
			else cout <<"NE\n";
		}
	}
	return 0;
}
*/