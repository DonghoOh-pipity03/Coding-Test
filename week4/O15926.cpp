// 실패

#include<bits/stdc++.h>
using namespace std;

int input, maxStreak, curStreak, a[200004];
string s;
stack<int> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> input >> s;

    for (int i = 0; i < input; i++) {
        if (s[i] == '(') stk.push(i);
        else if (stk.size()){  
            a[i] = a[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i = 0; i < input; i++) {
        if (a[i]) {
            curStreak++;
            maxStreak = max(curStreak, maxStreak);
        }
        else {curStreak = 0;}
    }

    cout << maxStreak;
    return 0;
}