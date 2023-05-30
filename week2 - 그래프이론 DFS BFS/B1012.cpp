// 1012 - 영역 개수 -> connected componenet -> DFS BFS 모두 가능

#include<bits/stdc++.h>
using namespace std;
const int max_length = 54;
int t, m, n, k, x, y, field[max_length][max_length], v[max_length][max_length], answer, nx, ny;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

void go(int _x, int _y) {
	v[_y][_x] = 1;

	for (int i = 0; i < 4; i++) {
		nx = _x + dx[i];
		ny = _y + dy[i];
		if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
		if (field[ny][nx] == 1 && v[ny][nx] == 0) go(nx, ny);
	}
}

int main() {
	cin >> t;
	while (t) {
		t--;
		cin >> m >> n >> k;
		fill(&field[0][0], &field[0][0] + max_length * max_length, 0);
		fill(&v[0][0], &v[0][0] + max_length * max_length, 0);
		answer = 0;

		while (k) {
			k--;
			cin >> x >> y;
			field[y][x] = 1;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (field[i][j] == 1 && v[i][j] == 0) {
					go(j, i);
					answer++;
				}
			}
		}

		cout << answer << endl;
	}
}

//	1. 배열 0으로 초기화하기
//	fill( &배열[0][0], &배열[0][0] + 배열크기 * 배열크기, 0 )

// 의사코드
// DFS로 돌면서 연결된 부분은 배열에 방문 표시를 한다.
// DFS내부에서 방문하면 '연결된 컴포넌트'를 카운트하지 않지만,
// 처음 DFS를 돌게 되면 카운트를 하여 '연결된 컴포넌트'를 구한다.