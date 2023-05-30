// 14502 - 브루트포스, DFS 2번_재귀함수
#include<bits/stdc++.h>
using namespace std; 
const int max_length = 9;
// a: 원본 맵, b: 방화벽 맵, c: 시뮬 맵
int n, m, answer,
a[max_length][max_length], b[max_length][max_length], c[max_length][max_length], v[max_length][max_length], max_safe;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0 };

// c맵에서 바이러스를 시뮬하는 함수
void sim(int _x, int _y) {
	v[_y][_x] = 1;
	c[_y][_x] = 2;
	for (int i = 0; i < 4; i++) {
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		// 이미 방문 했거나, 접근 못하는 곳이면, 넘어가기
		if (v[ny][nx] == 1 || c[ny][nx] != 0) continue;
		sim(nx, ny);
	}

}

// c를 기반으로 세이프룸 개수를 세어 반환하는 함수
int chkSafe(int _x, int _y) {
	int ret = 1;
	v[_y][_x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = _x + dx[i];
		int ny = _y + dy[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
		// 이미 방문 했거나, 접근 못하는 곳이면, 넘어가기
		if (v[ny][nx] == 1 || c[ny][nx] != 0) continue;
		ret += chkSafe(nx, ny);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	// 맵 복제 a -> b
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			b[y][x] = a[y][x];
		}
	}

	// 벽 랜덤 배치 -> 바이러스 시뮬레이션 -> 최대 세이프룸 출력
	for (int i = 0; i < n * m; i++) {
		if (a[i / m][i % m] == 0) {
			// 1번 벽 생성
			b[i / m][i % m] = 1;
		}
		else continue;
		for (int j = i + 1; j < n * m; j++) {
			if (a[j / m][j % m] == 0) b[j / m][j % m] = 1;	// 2번 벽 생성
			else continue;
			for (int k = j + 1; k < n * m; k++) {
				if (a[k / m][k % m] == 0) {
					// 3번 벽 생성
					b[k / m][k % m] = 1;
					// 맵 복제 b -> c
					for (int y = 0; y < n; y++) {
						for (int x = 0; x < m; x++) {
							c[y][x] = b[y][x];
						}
					}
					fill(&v[0][0], &v[0][0] + max_length * max_length, 0);
					// 바이러스 시뮬레이션
					for (int y = 0; y < n; y++) {
						for (int x = 0; x < m; x++) {
							if (c[y][x] == 2 && v[y][x] == 0) sim(x,y);
						}
					}
					// 세이프룸 개수 체크
					int safeRoom = 0;
					fill(&v[0][0], &v[0][0] + max_length * max_length, 0);
					for (int y = 0; y < n; y++) {
						for (int x = 0; x < m; x++) {
							if (c[y][x] == 0 && v[y][x] == 0) safeRoom += chkSafe(x, y);
						}
					}
					answer = max(answer, safeRoom);
					// 3번 벽 철거
					b[k / m][k % m] = 0;
				}
				else continue;
			}
			// 2번 벽 철거
			b[j / m][j % m] = 0;
		}
		// 1번 벽 철거
		b[i / m][i % m] = 0;
	}
	
	cout << answer;

	return 0;
}

// 배열 전체 초기화 하기
// fill(배열 시작 주소, 배열 끝 주소, 초기화 값)
//
// 개선 가능부분
// 1. 벽 설치 가능 영역과 바이러스 영역을 list<int, int>에 저장해서 효율적으로 쓰기
//