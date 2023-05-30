#include<bits/stdc++.h>
using namespace std;

int x, answer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> x;

    for(int i = 6; i >= 0; i--){
        if(x >= (1<<i)){
            answer++;
            x -= (1<<i);
        }        
    }

    cout << answer;
    return 0;
}
/*
    10진법 n을 b진법으로 바꾸는 방법
    키워드: while문, 나머지 더하기, 벡터

    whiel(n > 1){
        v.push_bback( n % b )
        n /= b;
    }
    if( n == 1 ) v.push_back( 1 );
    reverse(v.begin(), v.end())

*/