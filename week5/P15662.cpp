#include<bits/stdc++.h>
using namespace std;

int t, k;
int gear[1001][8];    // 톱니 상태
queue<pair<int, int>> rotOrder;   // 회전 명령

// 회전시키는 함수
void rotate(int _gearNum, int _rotDir) {
    int tmp;
    if (_rotDir == 1) {
        tmp = gear[_gearNum][7];
        for (int i = 6; i >= 0; i--) gear[_gearNum][i + 1] = gear[_gearNum][i];
        gear[_gearNum][0] = tmp;
    }
    else if (_rotDir == -1) {
        tmp = gear[_gearNum][0];
        for (int i = 0; i <=6 ; i++) gear[_gearNum][i] = gear[_gearNum][i+1];
        gear[_gearNum][7] = tmp;
    }
}

// 연쇄작용을 검사하는 함수
// _chainDir: 0-왼쪽, 1-오른쪽
void rotateChain(int _gearNum, int _rotDir, int _chainDir) {
    if (_gearNum == 0 && _chainDir == 0) return;
    if (_gearNum == t-1 && _chainDir == 1) return;

    if (_chainDir == 0 && gear[_gearNum - 1][2] != gear[_gearNum][6]) {
        rotateChain(_gearNum - 1, _rotDir * -1,_chainDir);
        rotate(_gearNum - 1, _rotDir*-1);
    }
    else if (_chainDir == 1 && gear[_gearNum + 1][6] != gear[_gearNum][2]) {
        rotateChain(_gearNum + 1, _rotDir * -1, _chainDir);
        rotate(_gearNum + 1, _rotDir * -1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> t;
    for (int i = 0; i < t; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < 8; j++) gear[i][j] = (int)(input[j] - '0');
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        int num, order;
        cin >> num >> order;
        rotOrder.push({num, order});
    }

    // 회전
    while (rotOrder.size()) {
        int num, order;
        num = rotOrder.front().first -1;
        order = rotOrder.front().second;
        rotOrder.pop();

        rotateChain(num, order, 1);
        rotateChain(num, order, 0);

        rotate(num, order);
    }

    // 카운트
    int answer = 0;
    for (int i = 0; i < t; i++) {
        if (gear[i][0] == 1)answer++;
    }

    cout << answer;
    return 0;
}

// cin을 이용해서 붙어있는 숫자를 한자리씩 배열에 저장하는 방법

// 톱니의 상태를 배열이 아닌, 비트로 구현할 수도 있었다.