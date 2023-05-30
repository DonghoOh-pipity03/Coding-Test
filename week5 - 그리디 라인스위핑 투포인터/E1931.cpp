#include<bits/stdc++.h>
using namespace std;

int n, startTime, EndTime, answer;
vector<pair<int,int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for(int i =0; i < n; i++){
        cin >> startTime >> EndTime;
        v.push_back({EndTime,startTime});
    }

    sort(v.begin(), v.end());

    int curTime = 0;
    for(int i = 0; i < n; i++){
        if(curTime > v[i].second) continue;
        answer++;
        curTime = v[i].first;
    }

    cout << answer;
    return 0;
}