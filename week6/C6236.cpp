#include<bits/stdc++.h>
using namespace std;

int n, m, pay[100001], low, hi ,mid, answer=INT_MAX, m_sum;

bool check(int _mid) {
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (sum + pay[i] > _mid) cnt++, sum = pay[i];
        else sum += pay[i];
        if (i == n - 1) cnt++;
    }
    return cnt <= m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> pay[i];
        m_sum += pay[i];
        low = max(low, pay[i]);
    }
    hi = m_sum;

    // 이분탐색
    while (low <= hi) {
        mid = (hi + low) / 2;
        if (check(mid)) {
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

// answer - 인출금액, hi - sum, low - 가장 큰 값

// 조건문에 함수의 이름만 넣었는데 동작함
// ex if(check)
// 함수의 이름은 메모리 주소를 나타내는 포인터로 해석될 수 있다.
// 그러므로 NULL이 아니라면 ture로 된다.

// 실수 - 다른 변수를 작성했다, 제한범위를 착각하여 작게 작성했다.
// 추천 - 이분탐색이면 그냥 int ll 구분하지 말고, ll로 시작하자