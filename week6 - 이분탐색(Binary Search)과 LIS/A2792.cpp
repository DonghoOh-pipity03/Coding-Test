#include<bits/stdc++.h>
using namespace std;

int n, m, answer = INT_MAX, low = 1, hi, mid;
vector<int> gem;

// 입력으로 mid(최대묶음개수)를 받아, 보석을 묶음으로 나누었을 때 학생 수보다 작거나 같으면 true -> hi를 줄여야 한다
bool check(int _mid) {
    int cnt = 0;
    for (auto i : gem) {
        cnt += i / _mid;
        if (i % _mid) cnt++;
    }
    return cnt <= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        gem.push_back(tmp);
        hi = max(hi, tmp);  // 오른쪽 포인터 초기화
    }

    // 이분 탐색 - answer(최대묶음개수)을 이분탐색으로 찾는다.
    // low와 hi는 1과 가장많은보석수
    while (hi >= low) {
        mid = (hi + low) / 2;
        if (check(mid)) {   // 묶음개수를 늘려야함
            answer = min(mid,answer);
            hi = mid - 1;
        }
        else {  // 묶음개수를 줄여도 됨
            low = mid + 1;
        }
    }

    cout << answer;
    return 0;
}
