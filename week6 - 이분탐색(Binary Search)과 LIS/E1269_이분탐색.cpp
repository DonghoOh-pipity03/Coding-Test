#include<bits/stdc++.h>
using namespace std;

int n, m, answer, a[200001], b[200001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);
    answer = n + m;
    int idx = 0, grp = 1, idx2;
    while (1) {
        if (((grp == 1) && (idx >= n)) || ((grp == -1) && (idx >= m))) break;

        if (grp == 1) idx2 = lower_bound(b, b + m, a[idx]) - b;
        else idx2 = lower_bound(a, a + n, b[idx]) - a;

        if (((grp == 1) && (a[idx] == b[idx2])) || ((grp == -1) && (b[idx] == a[idx2]))) {  // a에서 b 찾음  || b에서 a 찾음
            answer -= 2;
            idx = idx2 + 1;
        }
        else idx = idx2;    // 못 찾음
        grp *= -1;
    }

    cout << answer;
    return 0;
}

// A,B sort - N log N - 76ms
// A, B 원소를 번갈아가며 lower_bound - log N