// 1987
// 2회차 - 성공
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int r, c, v, maxDist = INT_MIN, m[20][20];

void dfs(int cy, int cx, int cnt) {
	int move = 0;
	// 탐색
	for (int i = 0; i < 4; i++) {
		int ny = cy + dy[i];
		int nx = cx + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		if (1<<m[ny][nx] & v) continue;
		move++;
		v |= 1<<m[ny][nx];
		dfs(ny,nx,cnt+1);
		v &= ~(1<<m[ny][nx]);
	}
	if (move == 0) { maxDist = max(maxDist, cnt); }
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			m[i][j] = int(s[j] - 'A');
		}
	}

	v |= 1<<m[0][0];
	dfs(0, 0, 1);

	cout << maxDist;

	return 0;
}

// 6:20
// 1차 코딩 끝 6:35
// 성공 6:40

// 개선점 
// (1) 비트를 마스킹 말고도 매개변수로 사용하기
// visited 정보를 dfs의 매개변수로 전달하면, 
// 20, 22의 방문, 원복 코드를 사용하지 않아도 된다.