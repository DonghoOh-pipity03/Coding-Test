#include<bits/stdc++.h>
using namespace std;

int n, k, m, v, c;
vector<pair<int,int>> gem(300000);
vector<int> bag(300000);
long long answer;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;

    for(int i =0; i < n; i++){
        cin >> m >> v;
        gem[i] = {m,v};
    }
    for(int i = 0; i < k; i++){
        cin >> c;
        bag[i] = c;
    }

    sort(gem.begin(), gem.begin() + n);
    sort(bag.begin(), bag.begin() + k);

    int index = 0;
    for(int i = 0; i < k; i++){
        while( index < n && gem[index].first <= bag[i] ){
            pq.push(gem[index].second);
            index++;
        }
        if(pq.size()){
            answer += pq.top();
            pq.pop();
        }
    }

    cout << answer;
    return 0;
}