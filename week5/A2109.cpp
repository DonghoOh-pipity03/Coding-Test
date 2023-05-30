#include<bits/stdc++.h>
using namespace std;

int n, answer, d, p, day[10004];
vector<pair<int, int>> v(10004);

bool cmp(pair<int, int> v1, pair<int, int> v2) {
    if (v1.second == v2.second) {
        if (v1.first > v2.first) return true;
        else return false;
    }
    else if (v1.second > v2.second) return true;
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v[i] = { d,p };
    }

    sort(v.begin(), v.begin() + n , cmp);

    int index = 0;
    while (index < n) {
        for (int i = v[index].first; i > 0; i--) {
            if (!day[i]) {
                answer += v[index].second;
                day[i] = 1;
                break;
            }
        }
        index++;
    }
    cout << answer;

    return 0;
}

// 커스텀 정렬을 만들 때, 두 입력 값이 같을 때는 else로 처리해 주어야 한다.
// if (v1.second == v2.second) -> 사용 시 에러발생    