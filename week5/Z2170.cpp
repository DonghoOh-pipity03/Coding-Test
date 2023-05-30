#include<bits/stdc++.h>
using namespace std;

int n, l, r;
vector<pair<int, int>> v(1000000);
long long answer;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        v[i] = { l,r };
    }

    sort(v.begin(), v.begin() + n);

    l = v.front().first;
    r = v.front().second;
    answer += (r - l);
    for (int i = 1; i < n; i++) {
        if (v[i].first > r) {
            l = v[i].first;
            r = v[i].second;
            answer += (r - l);
        }
        else if (v[i].second > r) {
            answer += v[i].second - r;
            r = v[i].second;
        }
    }

    cout << answer;
    return 0;
}