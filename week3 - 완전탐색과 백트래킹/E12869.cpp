// 12869
#include<bits/stdc++.h>
using namespace std;

int n, scv[3], answer;
int visit[64][64][64];
struct vector3
{
	int x, y, z;
};
queue<vector3> q;
int atk[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}

	q.push({ scv[0], scv[1], scv[2] });
	visit[scv[0]][scv[1]][scv[2]] = 1;
	while (q.size()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;

		cout << x << ' ' << y << ' ' << z << ' ' << visit[x][y][z] << '\n';

		q.pop();
		if (visit[0][0][0]) break;
		for (int i = 0; i < 6; i++) {
			int nx = max(0,x - atk[i][0]);
			int ny = max(0,y - atk[i][1]);
			int nz = max(0,z - atk[i][2]);
			if (visit[nx][ny][nz]) continue;
			q.push({nx,ny,nz});
			visit[nx][ny][nz] = visit[x][y][z] + 1;
		}
		
	}

	cout << visit[0][0][0] -1;
	return 0;
}

// 처음 생각한 알고리즘
// 1. 매번 내림차순 정렬을 한다.
// 2. 0번부터 때린다. 
//
// 알고리즘
// 최단 시간 또는 거리 -> BFS
// 세마리를 x,y,z로 생각하고 BFS를 돌린다.
// 
// 

// 1. sort 사용법 모름
// sort( a, a + 공간수, greater<>())
// //
// 
// 2. 구조체 작성법
// 3. 2차원 배열 선언 못 함