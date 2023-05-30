#include<bits/stdc++.h>
using namespace std;

int n, infCost = 1000000000;
int cost[17][17];   // 도시는 0번부터 시작한다.
int dp[17][1<<16];  // 현재위치, 방문한 도시(비트마스킹 이용)


int go(int _curCity, int _visited) {
    // 기재 - 모두 방문
    if (_visited == ((1 << n) - 1)) return cost[_curCity][0] ? cost[_curCity][0] : infCost;
    // 메모이제이션
    // 저장된게 있는지 확인 - 있으면 반환
    int& ret = dp[_curCity][_visited];
    if (~ret) return ret;
    // 탐색로직
    // 재귀함수 돌려서 최적값 반환하기
    ret = infCost;
    for (int i = 1; i < n; i++) {
        if (_visited & 1 << i) continue;    // 방문한 곳이면 넘어가기
        if (cost[_curCity][i] == 0) continue;   // 경로가 없으면 넘어가기
        ret = min(ret, go(i, _visited | 1 << i) + cost[_curCity][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, 1);
    return 0;
}

// INT_MIN, INT_MAX를 사용할 때, 언더플로우, 오버플로우 주의하기

// 모든 도시를 방문하기에 결국 원형이 된다.
// 그러므로 어느 도시에서 출발하든 상관이 없다.

// 16자리를 사용하는 비트마스킹의 경우를 저장하려면, 1<<16 개의 공간이 필요하다.
// 나는 1의 공간을 선언했었다.

// n개의 비트를 모두 방문했는지의 조건문에서,
// == 1 << 16으로 작성했다.
// 답은 == ((1<<n) -1)

// 마지막 방문에서 마지막 도시와 처음 도시를 연결하는 로직을 생각하지 못했다.

// 특정 비트를 추가해야하는 코드에서
// &를 사용했다 - 탐색하는 연산자
// 답은 | - 추가하는 연산자