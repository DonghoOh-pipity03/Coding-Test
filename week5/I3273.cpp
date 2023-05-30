#include<bits/stdc++.h>
using namespace std;

int p1, p2, n, x, answer, sum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 헤더 입력
    cin >> n;

    // 순열 입력
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    // x 입력
    cin >> x;

    // 순열 정렬
    sort(v.begin(), v.end());

    // 탐색
    p1 = 0;
    p2 = n-1;
    while (p1 < p2) {
        sum = v[p1] + v[p2];
        // 같음
        if (sum == x) {
            answer++;
            p1++; p2--;
        }
        else if (sum > x) p2--; // 큼
        else p1++;  // 작음
    }

    cout << answer;
    return 0;
}

// 벡터를 동적으로 공간을 생성하고, 순차적으로 데이터를 저장한다.

// 문제 잘 못 읽음
// 두 쌍을 구해야 하는데, 여러 개를 구하려고 함