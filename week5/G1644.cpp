#include<bits/stdc++.h>
using namespace std;

int eraCode[4000001], n, answer, p1, p2, sum;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (eraCode[i] == 0) {
            v.push_back(i);
            for (int j = i; j <= n; j += i) {
                eraCode[j] = 1;
            }
        }
    }

    while (1) {
        if (sum >= n) sum -= v[p1++];
        else if (sum < n && p2 < v.size()) sum += v[p2++];
        else break;
        if (sum == n) answer++;
    }

    cout << answer;
    return 0;
}

// low와 high -> 투포인터

// 배열 속에서 요소 찾기
// if(find(begin(arr), end(arr), target) != end(arr))

// 벡터 속에서 요소 찾기
// if(find(v.begin(), v.end(), target) != v.end())

// 소수 구하기
// 에라토스테네스의 체를 배열(방문되었는지)과 함께 만들어 구현하기
// 2부터 시작해서 +=i를 하면서 다른 수들은 방문처리한다.
// 단, 1은 소수가 아니다