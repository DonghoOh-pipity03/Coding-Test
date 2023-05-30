#include<bits/stdc++.h>
using namespace std;

int dice[10];
vector<int> v[35];  // 다음 노드 번호를 저장한 맵
int point[35];  // 노드별 점수를 가진 매핑
int answer = INT_MIN, sum;
int malPos[4]; // 말 별 위치

void AddVector(int _idx, int _val) { v[_idx].push_back(_val); }

void SetLevel() {
    for (int i = 0; i <= 19; i++) AddVector(i, i+1);
    AddVector(5,21); AddVector(21, 22); AddVector(22, 23); AddVector(23, 24);
    AddVector(10, 25); AddVector(25, 26); AddVector(26, 24);
    AddVector(15, 27); AddVector(27, 28); AddVector(28, 29); AddVector(29, 24);
    AddVector(24, 30); AddVector(30, 31); AddVector(31, 20); AddVector(20, 32);

    for (int i = 0; i <= 20; i++) point[i] = i * 2;
    point[21] = 13; point[22] = 16; point[23] = 19; point[24] = 25;
    point[25] = 22; point[26] = 24;
    point[27] = 28; point[28] = 27; point[29] = 26;
    point[30] = 30; point[31] = 35; point[32] = 0;
}

int go(int _curPos, int _moveCnt) {
    if (_moveCnt == 0) return _curPos;  // 움직일 필요없는 경우
    else if (_moveCnt == 1 || _curPos == 20) return v[_curPos].front(); // 앞의 칸이 마지막 경우
    else return go(v[_curPos].front(), --_moveCnt); 
}

bool isMal(int _pos) {
    for (int i = 0; i < 4; i++) {
        if (malPos[i] == _pos) return true;
    }
    return false;
}

void combi(int _cnt) {
    if (_cnt == 10) {
        // 최댓값 갱신하기
        answer = max(answer, sum);
    }
    else {
        for (int i = 0; i < 4; i++) {
            if (malPos[i] == 32) continue;  // 말의 이동이 끝남
            // 조합 적용
            int next;
            int originPos = malPos[i];
            if (v[malPos[i]].size() == 2) { next = go(v[malPos[i]][1], dice[_cnt] - 1); }
            else next = go(malPos[i], dice[_cnt]);

            if (next != 32 && isMal(next)) continue;   // 말 겹칩 예상
            malPos[i] = next;    // 말 이동
            sum += point[next];    // 점수 획득
            // 재귀
            combi(_cnt+1);
            // 조합 해제
            malPos[i] = originPos;  // 말 복귀
            sum -= point[next]; // 점수 해제
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    for (int i = 0; i < 10; i++) cin >> dice[i];

    // 완전 탐색
    SetLevel();
    combi(0);

    cout << answer;
    return 0;
}

// 완전탐색(브루트포스) * 조합?