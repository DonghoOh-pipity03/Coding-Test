// 14497 - BFS

#include<bits/stdc++.h>
using namespace std;

int n, m, v[304][304];
char a[304][304];
int x11, y11, x2, y2;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	cin >> y11 >> x11 >> x2 >> y2;

	x11--; y11--; x2--; y2--;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	queue<pair<int, int>> q;
	int flag = 0;
	int cnt = 0;
	while (!flag) {
		memset(&v[0][0], 0, sizeof(v));
		q.push({ y11,x11 });
		v[y11][x11] = 1;
		cnt++;

		while (q.size()) {
			int cy = 0, cx = 0;
			tie(cy, cx) = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int ny = cy + dy[j];
				int nx = cx + dx[j];
				//cout << cnt << " " << cy << " " << cx << '\n';
				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (v[ny][nx]) continue;
				if (a[ny][nx] == '1') {
					a[ny][nx] = '0';
					v[ny][nx] = 1;
					//cout << cnt << " " << cy << " " << cx << " " << ny << " " << nx << '\n';
				}
				else if (a[ny][nx] == '#') {
						flag = 1;break;
				}
				else {
					v[ny][nx] = 1;
					q.push({ ny,nx });
				}
			}
			if (flag) break;
		}
	}

	cout << cnt;

	return 0;
}

// 1. 제한범위 xy좌표가 0부터인지 1부터인지 혼동
// 2. xy기준 혼동