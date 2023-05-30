#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<float> q;
vector<float> v(7);
float f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> f;
        q.push(f);
        if(q.size() >= 8) q.pop();
    }

    for(int i = 6; i >= 0; i--){
        v[i] = q.top();
        q.pop();
    }

    for(auto i : v)  printf("%.3lf\n", i);

    return 0;
}