// 실패

#include<bits/stdc++.h>
using namespace std;

int t, cnt;
string order, input;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> order >> cnt >> input;
        
        deque<int> arr;
        int tmp = 0;
        for (auto i : input) {
            if (i == '[' || i == ']')continue;
            else if( i >= '0' && i <= '9') tmp = tmp * 10 + int(i) - int('0');
            else {
                arr.push_back(tmp);
                tmp = 0;
            }
        }
        if(tmp > 0)  arr.push_back(tmp);

        bool flag = true, rev = false;
        
        while (order.length()) {
            if (order.front() == 'R') {
                rev = !rev;
            }
            else if (order.front() == 'D') {
                if (arr.size() == 0) {
                    flag = false;
                    break;
                }
                else {
                    if (rev == false) arr.pop_front();
                    else arr.pop_back();
                }
            }
            order.erase(0, 1);
        }

        if (!flag) cout << "error\n";
        else {
            cout << '[';
            if (rev) reverse(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); i++) {
                cout << arr[i] ;
                if (i < arr.size() - 1) cout << ',';
            }
            cout  << ']' << '\n';
        }
    }
    return 0;
}

// split 구현 못함

// erase(시작인덱스, 삭제 크기)

// 토큰은 속도가 안나옴
// split보다 입력과 동시에 데이터 처리하는 것이 빠름