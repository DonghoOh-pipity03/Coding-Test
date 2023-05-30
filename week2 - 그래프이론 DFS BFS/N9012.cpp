// 9012
#include<bits/stdc++.h>
using namespace std; 
int t;
string s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> s;
		int sum = 0;
		bool flag = true;
		if (s.size() % 2 == 1) flag = false;
		for (char i : s) {
			if (i == '(') sum--;
			else sum++;
			if (sum > 0) {
				flag = false;
				break;
			}
		}
		if (sum != 0) {flag = false;}

		if(flag)cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	return 0;
}

// 짝짓기 -> 스택