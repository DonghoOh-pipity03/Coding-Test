#include<bits/stdc++.h>
using namespace std;

int n, deadLine, cnt, answer;
vector<pair<int,int>> v;
priority_queue <int, vector<int>, greater<int>> answer_pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i =0; i < n; i++){
        cin >> deadLine >> cnt;
        v.push_back({deadLine, cnt});
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < v.size(); i++){
        answer += v[i].second;
        answer_pq.push(v[i].second);
        if(v[i].first < answer_pq.size()){
            answer -= answer_pq.top();
            answer_pq.pop();
        }
    }

    cout << answer;
    return 0;
}

// 최대를 만드는 방법 2가지 - 최소를 최소로 / 최대를 최대로
// 여기서는 라인스위핑과 함께, pq를 이용해, 넘치면 최소를 빼버린다.

// pq 오름차순으로 만들기
// priority_queue <int, vector<int>, greater<int>> answer_pq;