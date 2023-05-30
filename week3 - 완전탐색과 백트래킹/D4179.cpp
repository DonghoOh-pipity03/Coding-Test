// 4179 - 나중에 다시 풀어보기

#include<bits/stdc++.h>
using namespace std;

char m[1004][1004];
int r, c, x, y, fire[1004][1004], person[1004][1004], iy, ix;
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0 ,1 ,0 };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;

	queue<pair<int, int>> q;
	fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INT_MAX);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> m[i][j];
			if (m[i][j] == 'F') {
				fire[i][j] = 1;
				q.push({ i,j });
			}
			else if (m[i][j] == 'J') {
				iy = i, ix = j;
			}
		}
	}

	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (fire[ny][nx] != INT_MAX) continue;
			if (m[ny][nx] == '#') continue;
			q.push({ny,nx});
			fire[ny][nx] = fire[y][x] + 1;
		}
	}

	q.push({iy, ix});
	person[iy][ix] = 1;
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		if (y == 0 || x == 0 || y == r - 1 || x == c - 1) {
			cout << person[y][x];
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if (m[ny][nx] == '#') continue;
			if (person[ny][nx] >= 1)continue;
			if (fire[ny][nx] <= person[y][x] + 1) continue;
			q.push({ ny,nx });
			person[ny][nx] = person[y][x] + 1;
		}
	}
	
	cout << "IMPOSSIBLE";

	return 0;
}

// 1. fill 사용하면서 처음 주소([0][0])가 아닌, 마지막 배열 주소를 입력함
// 2. 문제를 제대로 이해하지 않음

// 3. 자료구조 크기 생각해서 공통으로 쓰기보다는, 나눠서 사용하기 -> 디버그하기도 쉬움

/*
#include <bits/stdc++.h>
using namespace std;

int r, c, a[1004][1004], v[1004][1004];
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};
pair<int, int> jh;
vector<pair<int, int>> fire;
queue<pair<int, int>> q;

void bfs(int cy, int cx) {
	for (int i = 0; i < 4; i++) {
		int nx = cx+ dx[i];
		int ny = cy+ dy[i];
		if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
		if (a[ny][nx] == 0) continue;
		if (a[ny][nx] != -1 && v[ny][nx] <= v[cy][cx] + 1) continue;
		v[ny][nx] = v[cy][cx] + 1;
		a[ny][nx] = v[cy][cx] + 1;
		q.push({ ny,nx });
		int x, y = 0;
		tie(y, x) = q.front();
		bfs(y,x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	//  -1-길 0-벽 1~-불 특수-지훈이
	for (int i = 0; i < r; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == '#') a[i][j] = 0;
			else if (s[j] == '.') a[i][j] = -1;
			else if (s[j] == 'J') {
				a[i][j] = -1;	
				jh = { i,j };
			}
			else if (s[j] == 'F') {
				a[i][j] = 1;
				fire.push_back({i,j});
			}
		}
	}

	// 불 시뮬-BFS
	for (auto i : fire) {
		for (int j = 0; j < 4; j++) {
			int nx = i.second + dx[j];
			int ny = i.first + dy[j];
			if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if (a[ny][nx] == 0) continue;
			if(	a[ny][nx] != -1 && v[ny][nx] <= v[i.second][i.first] + 1) continue;
			v[ny][nx] = 1;
			a[ny][nx] = 1;
			q.push({ny,nx});
		}
	}
	int x, y = 0;
	tie(y, x) = q.front();
	bfs(y, x);

	// 탈출 시뮬 - BFS
	while (q.size()) q.pop();
	memset(v, 0, sizeof(v));
	int escTime = INT_MAX;
	bool ableToEsc = false;
	v[jh.first][jh.second] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = jh.second + dx[i];
		int ny = jh.first + dy[i];
		if (a[ny][nx] == 0 || v[ny][nx] >= 1) continue;	// 벽 & 지나간 길
		if (a[ny][nx] <= 1 && a[ny][nx] != -1) continue;	// 불
		if (nx == 0 || ny == 0 || nx >= c || ny >= r) {
			cout << '1' << '\n';
			return 0;
		}
		v[ny][nx] = 1;
		q.push({ ny,nx });
	}
	while (q.size()) {
		int cx, cy = 0;
		tie(cy, cx) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx == 0 || ny == 0 || nx >= c || ny >= r) {
				escTime = min(escTime, v[cy][cx]+2);
				ableToEsc = true;
				continue;
			}

			if (a[ny][nx] == 0 || v[ny][nx] >= 1) continue;	// 벽 & 지나간 길
			if (a[ny][nx] <= v[cy][cx] + 1 && a[ny][nx] != -1) continue;	// 불
			
			v[ny][nx] = v[cy][cx] + 1;
			q.push({ ny,nx });
		}
	}

		if (ableToEsc == false) cout << "IMPOSSIBLE" << '\n';
		else cout << escTime << '\n';

	return 0;
}
*/

// 가장자리 최단경로, 완전탐색, 동적
// 불은 벽으로 설정, 불이 갈곳을 불로 설정
// 벽과 불이 1턴뒤 갈곳을 따로 저장
// 
// 불 먼저 시뮬
// 다음 탈출
// 
// 이론은 맞는데, 구현이 안되었음
