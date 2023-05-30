#include<bits/stdc++.h>
using namespace std;

string a, b, answer;
int sum, ret, tmpA, tmpB;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i = 0;
    while (1) {
        if (i < a.length()) tmpA = int(a[i] - '0');
        else tmpA = 0;
        if (i < b.length()) tmpB = int(b[i] - '0');
        else tmpB = 0;
        if (a.length() <= i && b.length() <= i && ret == 0) break;
        answer += char((tmpA + tmpB + ret) % 10 + '0');
        ret = (tmpA + tmpB + ret) / 10;
        i++;
    }

    reverse(answer.begin(), answer.end());
    cout << answer;
    return 0;
}

// 제곱 연산
// pow(base, n)