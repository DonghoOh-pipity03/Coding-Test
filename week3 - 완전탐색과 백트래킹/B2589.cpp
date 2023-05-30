// 2589 - 완전탐색, BFS
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int bfs(int _x, int _y) {
	int v[51][51] = {};
	queue<pair<int, int>> q;
	int hour = 0;
	
	q.push({ _x,_y });
	v[_y][_x] = 1;

	while (q.size()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if (v[ny][nx] || a[ny][nx] == 'W' ) continue;
			q.push({nx,ny});
			v[ny][nx] = v[cy][cx] + 1;
			hour = max(hour, v[cy][cx]);
		}
	}

	return hour;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
			string s = "";
			cin >> s;
			for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'L') {
				int hour = bfs(j, i);
				answer = max(answer, hour);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}


// 1. BFS 구현에 미숙하였음
// 깊이를 알기 위해서 visited[ny][nx] = visited[cy][cx] +1 을 사용하지 못함
//
// 2. 지역변수를 선언할 때 초기화를 하지않음
// int v[51][51] = {};