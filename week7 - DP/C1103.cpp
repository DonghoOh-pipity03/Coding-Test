#include<bits/stdc++.h>
using namespace std;

int n, m;
char a[54][54];    // 보드
int dp[54][54]; // 최대 이동 가능 횟수
bool visited[54][54];    // 방문 여부 (각 탐색마다, 현재 경로 기준)
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };

// 입력: 현재 위치, 출력: 현재 위치에서 최대 이동 가능 횟수
// 다음 위치로 재귀
int go(int _cy, int _cx) {
    // 기저 - 예외, 완료
    if (_cy < 0 || _cx < 0 || _cy >= n || _cx >= m) return 0; // 보드 범위 밖
    if (a[_cy][_cx] == 'H') return 0;  // 구멍에 도착
    if (visited[_cy][_cx]) {    // 이미 방문한 곳 도착 = 루프
        cout << "-1" << endl;
        exit(0);
    }

    // 메모이제이션 - 이미 탐색이 완료된 곳인 경우, 재활용
    int& ret = dp[_cy][_cx];
    if ( ret ) return ret;
    
    // 탐색
    visited[_cy][_cx] = 1;
    int value = (int)a[_cy][_cx] - '0';
    for (int i = 0; i < 4; i++) {
        int ny = _cy + dy[i] * value;
        int nx = _cx + dx[i] * value;
        ret = max(ret, go(ny, nx)+1);
    }
    visited[_cy][_cx] = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            a[i][j] = tmp;
        }
    }

    cout << go(0, 0) << "\n";
}
/* 
특징 
- 4방면 탐색
- vistied로 루프 체크
- 메모이제이션으로 재활용 - DP
 
최대 50 * 50 배열의 방문 여부를, 저장하는 방법은?
- 메모이제이션 용 배열: dp[54][54]
- 루프 체크 용 배열: visited[54][54]


이미 방문했던 곳을 왔더라도, 루프 구조가 아닌 경우가 있다.
ex
3HH2
HHHH
3HH1
1HHH
그러므로 루프 여부를 체크하기 위해서는, 현재 경로를 기억하고 체크해야한다.


잘못된 코드
// 메모이제이션 - 이미 탐색이 완료된 곳인 경우, 재활용
int& ret = dp[_cy][_cx];
if ( ret ) return ret;    
// 탐색
visited[_cy][_cx] = 1;
int value = (int)a[_cy][_cx] - '0';
for (int i = 0; i < 4; i++) {
    int ny = _cy + dy[i] * value;
    int nx = _cx + dx[i] * value;
    ret = max(ret, go(ny, nx));
}
visited[_cy][_cx] = 0;
return ret + 1;

위와 같이 작성하면, return 값에는 문제가 없지만,
참조 변수 ret + 1이 갱신되지 않는다.

원인: 미숙한 참조 변수 사용

 */