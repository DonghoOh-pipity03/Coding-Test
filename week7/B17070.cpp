#include<bits/stdc++.h>
using namespace std;

int n;
int m[17][17];  // 집    y-r, x-c / 입력은 1~, 배치는 0~
int dp[17][17][4];   // 파이프 왼쪽의 위치 yx, 방향 가로-0, 대각선-1, 세로-2 = 가짓수
int dy[3] = { 0, 1, 1 }, dx[3] = {1, 1, 0};

// 입력을 기준으로 탐색을 시작한다.
int go(int _cy, int _cx, int _dir) {
    // 기저사례 - 탐색완료, 진행불가
    int cry = _cy + dy[_dir], crx = _cx + dx[_dir]; // 현재 파이프 오른쪽의 위치
    if (cry >= n || crx >= n) return 0;   // 진행불가 - 집 초과
    if (m[cry][crx]) return 0;  // 진행불가 - 벽 충돌
    if (_dir == 1 && (m[_cy][crx] || m[cry][_cx])) return 0;    // 진행불가 - 벽 충돌 - 대각선
    if (cry == n - 1 && crx == n - 1) return 1; // 탐색완료
    // 메모이제이션
    int& ret = dp[_cy][_cx][_dir];
    if (~ret) return ret;
    // 탐색로직
    ret = 0;
    for (int i = 0; i < 3; i++) {
        if (_dir == 0 && i == 2)continue;   // 방향제한
        if (_dir == 2 && i == 0)continue;   // 방향제한
        cry = _cy + dy[_dir]; crx = _cx + dx[_dir]; // 다음 위치 갱신
        ret += go(cry, crx, i);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0,0,0);

    return 0;
}

// 기저사례에서 탐색완료를 진행불가보다 먼저 작성해서, 예외처리가 되지 않았다.