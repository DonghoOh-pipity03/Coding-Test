// 14890
// 1회차 - 성공 40분
#include<bits/stdc++.h>
using namespace std;

int n, l, a[100][100], b[100][100], answer, bridge[100];
int prePos, curPos, nextPos;

void solve(int (*arr)[100], int cy) {
	if (cy == n ) return;

	memset(bridge, 0, sizeof(bridge));
	bool flag = true;
	for (int cx = 0; cx < n; cx++) {
		if (cx == n - 1) {answer++;continue;}	// 건너기 성공
		if (arr[cy][cx] == arr[cy][cx + 1]) continue;	// 이동 성공
		else {
			if (abs(arr [cy][cx + 1] - arr[cy][cx]) != 1) break;	// 높이가 1차이가 아닌 경우
			if (arr[cy][cx] < arr[cy][cx + 1]) {	// 올라가야 하는 경우
				if (cx - (l - 1) < 0) break;
				for (int i = 0; i < l; i++) {
					if (arr[cy][cx] != arr[cy][cx - i] || bridge[cx-i] ) {
						flag = false;break;}
					else {bridge[cx - i] = 1;}	// 경사로 설치
				}
			}
			else {	// 내려가야 하는 경우
				if (cx + l > n-1) break;
				for (int i = 1; i <= l; i++) {
					if (arr[cy][cx+1] != arr[cy][cx + i] || bridge[cx + i]) {
						flag = false;break;}
					else {bridge[cx + i] = 1;}	// 경사로 설치
				}
			}
			if (!flag) break;
		}
	}

	solve(arr, cy+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	solve(a,0);
	solve(b,0);
	cout << answer;
	return 0;
}

// 6:53 문제시작
// 7:03 코딩시작
// 7:14~7:50 중단
// 1차제출 8:10 성공


// 1. 배열 주소를 매개변수로 전달하는 방법
// (자료형 매개변수[][가로크기])
// 또는 (자료형(*매개변수)[가로크기])

// 개선점
// (1) 굳이 재귀함수로 구현하지 않았어도 되었다.
// (2) 이동하면서 '연속된 평탄함'을 계산하는 cnt로 더 간략히 짤 수 있다. 
// (강의 참고)(연속, 순차진행, 변화 -> 진행하며 카운팅하기)
//