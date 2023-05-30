#include<bits/stdc++.h>
using namespace std;

int n, a[21][21], answer = INT_MAX;

// 점수차 구하는 함수
int go(vector<int> _A, vector<int> _B) {
    int ASum=0, BSum=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ASum += a[_A[i]][_A[j]];
            BSum += a[_B[i]][_B[j]];
        }
    }
    return abs(ASum - BSum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // 조합
    for (int i = 0; i < (1 << n); i++) {
        if (__builtin_popcount(i) == n / 2) continue;
        vector<int> A, B;
        for (int j = 0; j < n; j++) {
            if (i & 1 << j) A.push_back(j);
            else B.push_back(j);
        }
        answer = min(answer, go(A, B));
        if (answer == 0) break;
    }

    cout << answer << '\n';
    return 0;
}