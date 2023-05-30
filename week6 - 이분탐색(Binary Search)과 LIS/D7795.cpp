#include<bits/stdc++.h>
using namespace std;

int t, n, m, answer, a[20001], b[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> t;
    while (t--) {
        // 입력
        cin >> n >> m;
        //memset(a, 0, size(a));
        //memset(b, 0, size(b));
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        // 이분탐색
        answer = 0;
        sort(b, b + m);
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(b, b + m,a[i]) - b;
            answer += idx;
        }
        cout << answer << '\n';
    }

    return 0;
}
// A - for문 O( N )
// B - 이분탐색 O( log N )
