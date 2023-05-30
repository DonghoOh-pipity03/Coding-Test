#include<bits/stdc++.h>
using namespace std;
int dp[1004][2][34], n, m, b[1004];
// dp - 현재시간/나의 위치/남은 이동 수
// b - 시간에 따라 1, 2 나무 위치 저장
// n - 전체 시간
// m - 이동 가능 수

// 3가지 상태 값을 받아, 최대로 먹을 수 있는 자두의 개수를 반환하는 함수
// tree - 0-왼쪽, 1-오른쪽
int go(int idx, int tree, int cnt) {
    //기저사례
    if (cnt < 0) return -1e9;   // 최대 이동 수를 초과한 경우, 탐색되면 안되므로 -무한을 리턴해서 해당탐색을 무력화한다.
    if (idx == n) return cnt == 0 ? 0 : -1e9;   // 최대 시간 초과, 이동 수가 남아있으면 왜 무력화하지?
    // 메모이제이션
    int& ret = dp[idx][tree][cnt];
    if (~ret) return ret;   //  ret이 -1이 아닌 경우(즉, 이전에 계산한 값이 있는 경우)에는 ret을 반환, 이를 통해 이전에 계산한 값을 재활용
    // 로직-탐색
    // 이전에 저장된 값이 없으면, 이동O/이동X 선택지에 따라 max 값을 구하고 반환
    // '현재 나의 위치'와 '현재 시간에 자두가 떨어지는 위치'가 같다면 + 1
    return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main() {
    // 초기화
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> b[i];
    cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
    return 0;
}