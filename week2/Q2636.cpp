// 14502 - 브루트포스, DFS 2번_재귀함수
#include<bits/stdc++.h>
using namespace std; 

int n, m, a[104][104], visited[104][104], answer;	// n= 세로, m= 가로
vector<pair<int, int>> v;
int dx[4] = {0, 1, 0 ,-1};
int dy[4] = { -1, 0, 1 ,0 };

void dfs(int _x, int _y) {
	visited[_y][_x] = 1;
	if (a[_y][_x] == 1) {
		v.push_back({_x,_y});
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx] == 1) continue;
		dfs(nx,ny);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 맵 세팅
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	while (1) {
		fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
		v.clear();
		int cnt = 0;
		bool flag = true;
		answer++;

		dfs(0,0);
		for (auto i : v) {
			a[i.second][i.first] = 0;
			cnt++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) {
					flag = false;
					break;
				}
			}
		}
		if (flag) {
			cout << answer << '\n' << cnt;
			break;
		}
	}
	return 0;
}

// <처음 생각한 알고리즘>
// 공기를 리스트로 보관한다
// 공기 기반으로 한 턴씩 소모한다.
// 각 턴 마다 치즈 크기를 구해 저장한다.
//
// <모범 알고리즘>
// 맵을 저장한다.
// 0,0에서 dfs를 1회 시작하고, 치즈 노드에 들어오면, 벡터에 노드 위치를 저장하고, dfs를 멈춘다.
// 벡터에 있는 노드들을 0으로 세팅하고, 삭제한 개수를 증가시킨다.
// 남은 것이 있는지 검사한다.
//
// 
// 리스트는 순차접근 상황에서 삽입에는 상관없지만, 삭제는 불가능하다.
//
// 
// 2시간짜리 디버그
// (1) =로 써야 할 것을 ==로 표기
// (2) true/false를 거꾸로 사용