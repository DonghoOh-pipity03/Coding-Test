#include<bits/stdc++.h>
using namespace std;

string input;
int s, order, val;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> order;

    while(order--){
        cin >> input;
        if(input == "add"){
            cin >> val;
            s |= (1<< val);
        }
        else if(input == "remove"){
            cin >> val;
            s &= ~(1<<val);
        }
        else if(input == "check"){
            cin >> val;
            if( s & (1<<val)) cout << "1\n";
            else cout << "0\n";
        }
        else if(input == "toggle"){
            cin >> val;
            s ^= (1<<val);
        }
        else if(input == "all"){
            s = (1<<21)-1;
        }
        else if(input == "empty"){
            s = 0;
        }
    }

    return 0;
}

/*
    토글 방법 몰랐음
    bit ^= (1<<자리수)

    전체 1로 만드는 방법 몰랐음
    bit = (1<< 비트크기+1) - 1

    전체 0으로 만드는 방법 몰랐음
    bit = 0;
*/