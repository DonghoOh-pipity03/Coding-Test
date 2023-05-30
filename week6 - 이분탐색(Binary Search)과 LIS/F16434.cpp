#include<bits/stdc++.h>
using namespace std;

long long n, curHP, extraHP, atk, a, b, c;
set<long long> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> atk;
    curHP = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a == 1) {   // 몬스터
            int turn = int(ceil((double)c / (double)atk));
            curHP -= ((turn - 1) * b);
        }
        else { // 물약
            if (curHP < 0) s.insert(curHP * -1 + extraHP);

            atk += b;
            curHP += c;
            if (curHP > 0) extraHP = curHP;
        }

        if(i == n-1) s.insert(curHP * -1 + extraHP);
    }

    cout << (*prev(s.end()) + 1);
    return 0;
}

// 1.1. 체력이 0인 상태에서 전체 순회하며 전투시뮬레이션을 한다.
// 1.2. 물약을 만나면 부족한 체력을 set에 저장하고, 물약으로 회복된 체력은 여분으로 저장한다.
// 이때 부족한 체력을 저장하기 전에 여유 체력이 저장되어 있다면, 함께 더하여 저장한다.
// 2. 가장 부족했던 체력에 +1 하여 답 도출
// 순회 O( N ), set입력 O( log N ) -> O( N log N) 

// set 사용법과 특성

// 가장 큰 수 -> set 대신 int maxVal = max~를 쓰기