// 2583 - 연결된 컴포넌트 - DFS
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

const int max_length = 100;
int m, n, k, a[max_length][max_length], v[max_length][max_length],cnt;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
vector<int> s;
int DFS(int _x, int _y) {
	int s = 1;
	v[_y][_x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (a[ny][nx] == 0 && v[ny][nx] == 0) {
			s += DFS(nx, ny);
		}
	}
	return s;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> k;

	while (k--) {
		int x1, y1, x2, y2, x, y;
		cin >> x1 >> y1 >> x2 >> y2;
		for (y = y1; y < y2; y++) {
			for (x = x1; x < x2; x++) {
				a[y][x] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0 && v[i][j] == 0) {
				s.push_back(DFS(j, i));
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	sort(s.begin(), s.end());
	for (int i : s) cout << i << " ";
}