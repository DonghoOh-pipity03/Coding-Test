#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n;
    vector<float> v(n);
    float f;

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < 7; i++){
        printf("%.3lf\n", v[i]);
    }

    return 0;
}