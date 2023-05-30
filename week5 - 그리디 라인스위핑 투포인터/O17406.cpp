#include<bits/stdc++.h>
using namespace std;

int n, m, k, answer = INT_MAX;
int origin[51][51], a[51][51];
vector<tuple<int, int, int>> rotOrder;

int GetSum() {
    int sum = INT_MAX;
    for (int j = 0; j < n; j++) {
        int tmp = 0;
        for (int i = 0; i < m; i++) tmp += a[j][i];
        sum = min(sum, tmp);
    }
    return sum;
}

vector<int> Rotate(int _order) {

}

//  인터페이스
void go(int _cnt) {
    if (_cnt == 0) {
        answer = min(answer, GetSum());
        return;
    }
    else {
        Rotate(k - _cnt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m >> k;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            cin >> origin[j][i];
        }
    }
    for (int i = 0; i < k; i++){
        int r, c, s;
        cin >> r >> c >> s;
        rotOrder.push_back({r,c,s});
    }

    // 조합 돌리기
    do {
        memcpy(a, origin, size(origin));
        go(k);
    } while (next_permutation(rotOrder.begin(), rotOrder.end()));

    cout << answer;
    return 0;
}

// 한번씩 랜덤으로 사용해야함
// 조합-next_permutation
/*
do {
    // do something
}while(next_permutation(v.begin(), v.end()));
*/

// 2차원 벡터를 매개변수로 받고, 리턴하는 방법

// 2차원 배열을 2차원 벡터로 복사하는 방법
// for문으로 가능

// 2차원 배열을 함수로 주고받는 방식보다, 멤버 변수로 하나 더 배열을 만들어서 활용하기