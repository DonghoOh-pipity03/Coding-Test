#include<bits/stdc++.h>
using namespace std;

int n, a[44], ret = INT_MAX;
string s;

void go(int here) {
	if (here == n + 1) {	 // 탐색 행 탐색 완료
		int sum = 0;
		for (int i = 1; i <= (1 << (n - 1)); i *= 2) { //(왼쪽->오른쪽) 검색
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (a[j] & i)cnt++; // (위->아래) 검색
			sum += min(cnt, n - cnt);   // 실제로 세로줄을 뒤집지 않고, 최소 개수를 구한다.
		}
		ret = min(ret, sum);
		return;
	}
	a[here] = ~a[here];	// 뒤집고,
	go(here + 1);	// 탐색
	a[here] = ~a[here];	// 원복하고,
	go(here + 1);	// 탐색
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'T')a[i] |= value;
			value *= 2;
		}
	}
	go(1);
	cout << ret << "\n";
	return 0;
}