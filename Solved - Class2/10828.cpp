#include<bits/stdc++.h>
#include<stack>
using namespace std;

int O;
stack<int> S;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 명령 갯수 입력
    cin >> O;

    // 명령 처리
    for (int i = 0; i < O; i++) {
        string input;
        cin >> input;

        if (input == "push") { 
            int tmp;
            cin >> tmp;
            S.push(tmp); 
        }
        else if (input == "pop") {
            if (S.size() != 0) {
                cout << S.top() << '\n';
                S.pop();
            }
            else cout << "-1" << '\n';
        }
        else if (input == "size") {
            cout << S.size() << '\n';
        }
        else if (input == "empty") {
            if (S.size() == 0) cout << "1" << '\n';
            else cout << "0" << '\n';
        }
        else if (input == "top") {
            if (S.size() != 0) {
                cout << S.top() << '\n';
            }
            else cout << "-1" << '\n';
        }
    }
}


/*
1. 한줄에서 한 글자씩 받기
torken보다 cin을 여러번 받는게 더 빠름


endl: 348ms
\n: 0ms


문자열 비교방법
(1) ==
(2) !ㅁㅁ.compare(ㅁㅁ) 
// compare는 같으면 0, 다르면 -1을 리턴함

Cpp에서는 ==연산자가 compare에 오버로딩 되어있다.
디버그 빌드에서는 ==연산자가 느릴 수 있지만,
릴리즈 빌드에서는 차이가 거의 없다.
*/