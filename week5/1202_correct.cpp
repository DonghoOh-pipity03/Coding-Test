#include<bits/stdc++.h>
using namespace std;

long long answer;
int n, k, m, v, c;
vector<int> bag;
vector<pair<int, int>> gem;
priority_queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> m >> v;
        gem.push_back({ m,v });
    }
    for (int i = 0; i < k; i++) {
        cin >> c;
        bag.push_back({c});
    }

    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    int j = 0;
    for (int i = 0; i < k; i++) {
        while ( j < n && bag[i] >= gem[j].first) {
            q.push(gem[j++].second);
        }
        if (q.size()) {
            answer += q.top();
            q.pop();
        }
    }

    cout << answer;
    return 0;
}

// foreach문에서 깊은참조하기
// &i로 깊은 참조를 할 수 있다.

// 우선순위 큐
// 무게허용이 낮은 가방부터 반복문을 돌리면서, 담을 수 있는 보석을 우선순위 큐에 담는다.
// 우선순위 큐의 top에는 가치가 높은 순으로 담기기에, 첫번째 것만 계산하고, 계속 반복문을 돌린다.
// 다음 가방은 무게허용량이 더 크기 때문에, 이전에 담은 큐의 내용물은 상관없다.