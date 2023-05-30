#include<bits/stdc++.h>
using namespace std;

int n, reachTime, waitTime, answer;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> reachTime >> waitTime;
        v.push_back({reachTime, waitTime});
    }

    sort(v.begin(), v.end());

    for(int i =0; i < v.size(); i++){
        if( v[i].first > answer ){
            answer = v[i].first;
        }
        answer += v[i].second;
    }

    cout << answer;
    return 0;
}