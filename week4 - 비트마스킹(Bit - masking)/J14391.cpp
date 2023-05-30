#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);



    return 0;
}

/*
    비트를 이용하여 모든 경우의 수를 탐색하는 문제  
    1. 4x4 맵에서 비트를 이용하여 모든 경우의 수를 탐색한다.
    0이면 가로방향, 1이면 세로방향으로 읽는 규칙을 적용한다.
    주어진 가로세로에 맞게 0부터 인덱스를 부여하는 규칙을 적용한다.
    2. 가로, 세로 별로 탐색하면서, 최댓값을 갱신한다.
*/