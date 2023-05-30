// 4659
#include<bits/stdc++.h>
using namespace std;

string s;
int lcnt, vcnt;
bool isVowel(int i) { return (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u'); }
int main() {
	while (1) {
		cin >> s;
		if (s == "end") break;
		lcnt = vcnt = 0;
		bool flag = 0;
		bool hasVowel = 0;
		int preChar = -1;

		for (int i = 0; i < s.size(); i++) {
			int idx = s[i];
			// 모음 검사
			if (isVowel(idx)) hasVowel = 1, lcnt = 0, vcnt ++;
			else lcnt ++, vcnt = 0;
			// 삼연벙 검사
			if (lcnt == 3 || vcnt == 3) flag = 1;
			// 2 연속 검사
			if ( i >= 1 && (preChar == idx) && (idx != 'e' && idx != 'o')) {
				flag = 1;
			}
			preChar = idx;
		}
		if (hasVowel == 0) flag = 1;
		if (!flag) { cout << "<" + s + "> " << "is acceptable." << endl; }
		else{ cout << "<" + s + "> " << "is not acceptable." << endl;}
	}
	return 0;
}
