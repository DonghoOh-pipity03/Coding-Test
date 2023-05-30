#include<bits/stdc++.h>
using namespace std;

int n, l, answer;
vector< pair<int, int>> puddle;
int localStart, localEnd, safeEnd;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        puddle.push_back({ a,  b - 1 });
    }

    sort(puddle.begin(), puddle.end());

    // 계산
    while (puddle.size()) {
        localStart = puddle.front().first;
        localEnd = puddle.front().second;
        puddle.erase(puddle.begin());
        if (safeEnd >= localEnd) continue;
        if (safeEnd >= localStart) localStart = safeEnd + 1;

        int gap = localEnd - localStart + 1;
        int cnt = int(ceil((double)gap / (double)l));
        answer += cnt;
        safeEnd = localStart + cnt * l - 1;
    }

    cout << answer;
    return 0;
}

// cpp에서 int형 2개를 저장하는 우선순위 큐를 오름차순으로 사용하는 방법

// 2차원 벡터 정렬하는 방법

// 소수 계산을 할 때!

// 원인 없이 모호하다고 할 때