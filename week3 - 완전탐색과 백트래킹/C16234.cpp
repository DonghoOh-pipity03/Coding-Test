// 16234 - 완전탐색, 연결된 컴포넌트
#include <bits/stdc++.h>
using namespace std;

int n, l, r, m[54][54], moveCnt, v[54][54];
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
vector<pair<int, int>> vec;
int human;

bool dfs(int cx, int cy) {
	bool move = false;
	v[cy][cx] = 1;
	vec.push_back({cx,cy});
	human += m[cy][cx];

	for (int i = 0; i < 4; i++) {
		int nx = cx + dx[i];
		int ny = cy + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (v[ny][nx] == 1) continue;
		int gap = abs(m[cy][cx] - m[ny][nx] );
		if (gap < l || gap > r) continue;
		dfs(nx,ny);
		move = true;
	}

	return move;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}

	while (1) {
		bool move = false;
		memset(v, 0, sizeof(v));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i][j] != 1) {
					human = 0;
					vec.clear();
					if (dfs(j, i)) {
						move = true;
						int perHuman = int(human / vec.size());
						for (auto k : vec) {
							m[k.second][k.first] = perHuman;
						}
					}
				}
			}
		}

		if (move == false) break;
		else moveCnt++;
	}

	cout << moveCnt << '\n';

	return 0;
}


// 여는 조건 무한루프 & 연결된 컴포넌트 -> 분배
// 배열별로 완전탐색 후 visit로 구분하기 // 구현이 간단한 DFS 사용
// 연결된 국가를 큐에 저장, 탐색이 끝나면 인구를 분배

// 1. x,y를 거꾸로 써서 1시간 소비함