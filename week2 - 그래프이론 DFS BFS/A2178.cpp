// 2178 최소거리 -> BFS
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

const int max_n = 104;	// 최대값보다 4 크게 할당하기
int n, m, load[max_n][max_n], visited[max_n][max_n], x, y, nx, ny;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &load[i][j]);
		}
	}
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	q.push({0,0});
	while (q.size()) {
		tie(y, x) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
			if (load[ny][nx] == 0) continue;
			if (visited[ny][nx] != 0) continue;

			q.push({ ny, nx });
			visited[ny][nx] = visited[y][x] + 1;
		}
	}
	
	cout << visited[n - 1][m - 1] << endl;
}

// 1. BFS는 못먹어도 고 불가능, 두들기고 건너기만 가능

// 2. 행렬 표기 반전
// 
// 행 = n = y
// 렬 = m = x

// 3. BFS 의사코드
/* 
키워드: 큐, visitedSumUpCount[], 돌다리 두들기기
	
맵 만들기
시작점 방문처리 / 큐 push
while{
	tie(y,x) = q.front()
	q.pop()
	for(각 이동 방향){
		불가능하면 continue
		가능하면 visitedSumUpCount 누적합 / q.push
	}
}
목표.visitedSumUpCount 출력

*/