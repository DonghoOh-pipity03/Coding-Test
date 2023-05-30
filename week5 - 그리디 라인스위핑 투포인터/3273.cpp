#include<bits/stdc++.h>
using namespace std;

int n, x, a, b, sum, answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    cin >> x;

    a = 0;
    b = n-1;

    while(1){
        sum = v[a] + v[b];
        if( sum == x){
            answer++;
            a++; b--;
        }
        else if(sum < x) a++;
        else if(sum > x) b--;
        if(a==b || a>b ) break;
    }

    cout << answer;
    return 0;
}