// 2468 - 연결된 컴포넌트 - DFS

#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;
int n, x, y, nx, ny, r[max_n][max_n], v[max_n][max_n], tmp, answer, comp;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void DFS(int _x, int _y, int _h){
	v[_y][_x] = 1;
	for (int i = 0; i < 4; i++) {
		nx = _x + dx[i];
		ny = _y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (r[ny][nx] > _h && v[ny][nx] == 0) DFS(nx, ny, _h);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> r[i][j];
		}
	}

	for (int h = 0; h <= 100; h++) {
		comp = 0;
		fill(&v[0][0], &v[0][0] + max_n * max_n, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (r[i][j] > h && v[i][j] == 0) {
					comp++;
					DFS(j, i, h);
				}
			}
		}
		answer = max(answer, comp);
	}
	cout << answer;
}