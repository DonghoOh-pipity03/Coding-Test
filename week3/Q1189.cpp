// 1189 - DFS
// 1회차 - 성공 32분
#include<bits/stdc++.h>
using namespace std;

int r, c, k,visited[9][9], answer;
char a[9][9];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void go(int cy, int cx, int cnt) {
	if (cnt > k) return;
	if (cnt == k && cy== 0 && cx == c-1) { 
		answer++; 
		return;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
			if ( a[ny][nx] == 'T' || visited[ny][nx]) continue;
			visited[ny][nx] = 1;
			go(ny,nx,cnt+1);
			visited[ny][nx] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c >> k;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
		}
	}
	
	visited[r - 1][0] = 1;
	go(r-1,0,1);
	cout << answer;
	return 0;
}

// 1:47 시작
// 2:19 성공