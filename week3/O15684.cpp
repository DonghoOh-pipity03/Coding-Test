// 15684 - 
// 1회차 - 실패

#include<bits/stdc++.h>
using namespace std;

int n, m, h, x, y, answer = INT_MAX;
int v[274][14];

bool Check() {
	for (int i = 1; i <= n; i++) {
		int route = i;
		for (int j = 1; j <= h; j++) {
			if (v[j][route-1]) route--;
			else if (v[j][route]) route++;
		}
		if (route != i) return false;
	}
	return true;
}

void go(int start, int cnt) {
	if (cnt > 3 || cnt >= answer) return;
	else if (Check()) {
		answer = min(cnt, answer);
		return;
	}
	else {
		for (int i = start; i <= h; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i][j] || v[i][j-1] || v[i][j+1])continue;
				else {
					v[i][j] = 1;
					go(i, cnt + 1);
					v[i][j] = 0;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> y >> x;
		v[y][x] = 1;
	}

	go(1, 0);

	if (answer == INT_MAX) cout << "-1\n";
	else cout << answer;

	return 0;
}

// 11:00 시작
// 11:20 문제이해완료
// 11:32 이론 포기

// <인강 수강후>
// 백트래킹, DFS