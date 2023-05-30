#include<bits/stdc++.h>
using namespace std;

int t, w, a[1001], b[1001][2][31], answer;

int go(int _time, int _myPos, int _remainMove) {
    // 예외 (기저사례)
    if (_remainMove < 0) return INT_MIN;
    if (_time == t) return _remainMove == 0 ? 0 : INT_MIN;
    // 메모이제이션
    int& val = b[_time][_myPos][_remainMove];
    if (~val) return val;
    // 재귀탐색
    return val = max(go(_time + 1, _myPos, _remainMove), go(_time + 1, _myPos ^ 1, _remainMove - 1)) + (_myPos == a[_time] - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t >> w;
    for (int i = 0; i < t; i++) cin >> a[i];
    
    memset(b, -1, sizeof(b));
    answer = max(go(0, 0, w), go(0, 1, w - 1));

    cout << answer;
    return 0;
}

// 실수 sizeof 대신에 size로 배열을 초기화하여, 오답을 도출했다.