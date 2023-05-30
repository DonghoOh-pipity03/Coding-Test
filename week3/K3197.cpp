// 3197 - BFS 
// 1회차 - 시간초과, 메모리 초과

#include<bits/stdc++.h>
using namespace std;
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { -1, 0, 1, 0 };

int r, c, swanV[1504][1504], waterV[1504][1504], cy, cx;
char a[1504][1504];
int y11, x11;
queue <pair<int, int> > swanQ, swanQ_temp, waterQ, waterQ_temp;

void QClear(queue<pair<int, int>> &target) {
	queue<pair<int,int>> temp;
	swap(target, temp);
}

bool swanMove() {
	while (swanQ.size()) {
		tie(cy, cx) = swanQ.front();
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || swanV[ny][nx]) continue;
			swanV[ny][nx] = 1;
			if (a[ny][nx] == 'X') {swanQ_temp.push({ ny,nx });}
			else if (a[ny][nx] == 'L') { return true; }
			else { swanQ.push({ ny,nx }); }
		}
	}
	return false;
}

void melting() {
	while (waterQ.size()) {
		tie(cy, cx) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= r || nx >= c || waterV[ny][nx]) continue;
			if (a[ny][nx] != 'X') continue;
			waterV[ny][nx] = 1;
			waterQ_temp.push({ ny,nx });
			a[ny][nx] = '.';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> r >> c;
	// 입력
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') {y11 = i; x11 = j;}
			if (a[i][j] == 'L' || a[i][j] == '.') { waterQ.push({i,j}); }
		}
	}

	int day = 0;
	swanQ.push({ y11,x11 });
	swanV[y11][x11] = 1;
	while (1) {
		// 검사
		if (swanMove()) break;
		swanQ = swanQ_temp;
		QClear(swanQ_temp);
		// 녹이기
		melting();
		waterQ = waterQ_temp;
		QClear(waterQ_temp);

		day++;
	}

	cout << day;
	return 0;
}

// 만날 수 있는지 검사 - 
// 연결된 컴포넌트 별로 1깊이씩 녹이기 - 

// void QClear(queue<pair<int,int>> target){
// queue<pair<int,int>> temp;
// swap(target, temp);
// }
//  위의 로직이
// while(q.size()) q.pop();
// 보다 빠르다.
//

// 시간초과
//	->
// 백조의 이동, 얼음 녹음 -> 2개 모두, temp 큐를 사용해서 속도를 향상시키는 것이 정답이였다.
// 
//	메모리 초과
//	=>
// 백조가 이동하면서 얼음을 확인한 구역은 water큐에 들어갔기에, visit 처리를 한다.
// (여기서 visit 처리를 하지 않아서, 메모리 초과로 실패했다.)