// 14620 - 백트래킹
// 1회차 - 성공(푸는 시간이 오래걸림)
#include<bits/stdc++.h>
using namespace std;

const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };
int n, a[14][14], visited[14][14], answer=INT_MAX, x, y;
vector<pair<int, int>> v;

int getValue() {
	int value = 0;
	for (auto i : v) {
		tie(y, x) = i;
		for (int j = 0; j < 4; j++) {
			value += a[y+dy[j]][x+dx[j]];
		}
		value += a[y][x];
	}
	return value;
}

void setFlower(int _y,int _x) {
	visited[_y][_x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = _y + dy[i];
		int nx = _x + dx[i];
		visited[ny][nx] = 1;
	}
}

void eraseFlower(int _y, int _x) {
	visited[_y][_x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = _y + dy[i];
		int nx = _x + dx[i];
		visited[ny][nx] = 0;
	}
}

bool checkCross(int _y, int _x) {
	for (int i = 0; i < 4; i++) {
		int ny = _y + dy[i];
		int nx = _x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) {
			return false;
		}
	}
	return true;
}

void go(int cy, int cnt) {
	if (cnt == 3) { 
		answer = min(answer, getValue()); 
		return;
	}
	else {
		for (int i = cy; i < n - 1; i++) {
			for (int j = 1; j < n - 1; j++) {
				if (!checkCross(i, j)) continue;
				else {
					v.push_back({ i,j });
					setFlower(i,j);
					go(i,cnt+1);
					eraseFlower(i,j);
					v.pop_back();
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	go(1,0);

	cout << answer;
	return 0;
}

// 조건을 구하기는 방법을 단순화하자
// ex) 두 꽃의 겹치는지 여부
// 두 꽃의 위치 관계를 통해 관계식을 도출하여 조건문에 사용 
// -> visited 맵에 0과 1로 그려서 확인하기