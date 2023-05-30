#include<bits/stdc++.h>
using namespace std;

long long answer;
int n, k, m, v, c;
vector<pair<int, int>> bag;
vector<pair<int,int>> gem;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> k;

    for(int i = 0; i < n; i++){
        cin >> m >> v;
        gem.push_back({v,m});
    }
    for(int i = 0; i < k; i++){
        cin >> c;
        bag.push_back({c,0});
    }

    sort(gem.begin(), gem.end(), greater<>());
    sort(bag.begin(), bag.end());

    for(auto i : gem){
        for(auto j : bag){
            if(j.second) continue;
            if(j.first < i.second) continue;
            j.second = 1;
            answer += i.first;
            k--;
            break;
        }
        if(k == 0) break;
    }

    cout << answer;
    return 0;
}

// 1. for문에서 얕은 참조로 인해, 벡터의 값이 수정되지 않음
// 2. 위의 구조로는 시간 초과가 발생함