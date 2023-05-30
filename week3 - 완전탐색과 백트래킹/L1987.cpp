// 1987 - DFS
// 1회차 - 시간초과

#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = { -1, 0, 1, 0 };

int r, c, ny,nx, v[26];
char a[24][24];

int dfs(int cy, int cx) {
	int childRoute = 0;
	for (int i = 0; i < 4; i++) {
		ny = cy + dy[i];
		nx = cx + dx[i];
		if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
		int next = (int)(a[ny][nx] - 'A');

		if (v[next] == 0) {
			v[next] = 1;
			childRoute = max(childRoute, dfs(ny, nx));
			v[next] = 0;
		}
	}
	return (1 + childRoute);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}

	v[(int)a[0][0] - 'A'] = 1;
	cout << dfs(0,0);

	return 0;
}

// 1부터 시작 주의!!!

// 시간초과
// (1) DFS는 재귀함수의 특징을 가진다.
// 재귀함수에서 복귀했을 때, "원복"을 할 수 있다.
// !!!!!
// 
// (2) 문자열의 비교는 - 'A' 를 통해
// int 형으로 비교할 수 있고, 배열에 넣어 사용할 수 있다.
// 그리고, 연산 문자끼리 연산한 후에는 (int)형으로 바꿔주어야한다.