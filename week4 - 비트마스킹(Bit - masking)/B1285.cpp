// 1285
// 1회차 - 실패
#include<bits/stdc++.h>
using namespace std;

int n, a[24], min_cnt = INT_MAX;
string s;

void go(int cy) {
	if (cy == n + 1) {
		int sum = 0;
		for (int j = 1; j < (1 << n); j *= 2) {
			int cnt = 0;
			for (int i = 1; i <= n; i++) {
				if (a[i] & j) {
					cnt += 1;
				}
			}
			sum += min(cnt, n - cnt);
		}
		min_cnt = min(min_cnt, sum);
		return;
	}

	a[cy] = ~a[cy];
	go(cy + 1);
	a[cy] = ~a[cy];
	go(cy + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		int k = 1;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'T') a[i] |= k;
			k *= 2;
		}
	}

	go(1);
	cout << min_cnt;
	return 0;
}

// 가로줄을 기준으로 뒤집거나/원복한 상태로 완전탐색을 한다.
// 완전탐색의 마지막에는 세로줄 별로 T의 개수를 세고,
// T의 개수가 적은 쪽으로 합계에 더한다.
// 뒤집거나, 그대로 두는 방법 2가지인데 실제로 뒤집지는 않고, 적은쪽으로 세는 것이다.
//