#include<bits/stdc++.h>
using namespace std;

int n, m, video[100001], sum, low, hi, mid, answer = INT_MAX;

// hi를 줄여야 할 때 true를 반환하도록 -> 담을 공간이 부족하거나 같을 때
bool Check(int _mid) {
    int cnt = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + video[i] > _mid) cnt++, sum = video[i];
        else sum += video[i];
        if (i == n - 1) cnt++;
    }
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> video[i], low = max(low, video[i]), sum += video[i];
    hi = sum;

    // 블루레이 탐색
    while (low <= hi) {
        mid = (low + hi) / 2;
        if (Check(mid)) {
            answer = min(answer, mid);
            hi = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    cout << answer;
    return 0;
}

// 구하는 것, 블루레이의 크기
// 순서와 합 -> 누적합?
// 최소 - 최대 영상길이, 최대 - 모든 합 / 블루레이 개수

// 시간복잡도 구하는 습관 들이기
// (1) 블루레이 크기 탐색 n (for문) -> log n (이분탐색)
// (2) 강의 담기 탐색 n (for문)

// 이분탐색 구현 순서
// 구하는 것, 최소, 최대 정의하기
// -> while문과 탈출조건 -> low, hi를 변경한는 분기점 -> hi를 변경하는 분기에서, 답을 min으로 갱신
// -> 커스텀 함수에서, hi를 줄여야 할 때 true를 반환하도록 하기