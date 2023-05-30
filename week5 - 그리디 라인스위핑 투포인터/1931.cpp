#include<bits/stdc++.h>
using namespace std;

int n, startTime, endTime, answer;
vector<pair<int,int>> v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    while(n--){
        cin >> startTime >> endTime;
        v.push_back({endTime, startTime});
    }

    sort(v.begin(), v.end());

    int curEnd = v.front().first;
    answer++;

    for(int i = 1; i < v.size(); i++){
        if(v[i].second < curEnd) continue;
        else{
            curEnd = v[i].first;
            answer++;
        }
    }

    cout << answer;
    return 0;
}