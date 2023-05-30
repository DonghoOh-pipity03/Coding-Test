#include<bits/stdc++.h>
using namespace std;

int n, k, l, gameTime;
vector<pair<int, int>> applePos;    // 사과 위치
vector<pair<int, char>> turn;    // 회전 정보_L-왼쪽, D-오른쪽
deque<pair<int, int>> body; // 뱀 몸 위치 정보
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

struct head {
    int headY = 1;  // 머리의 위치 y 
    int headX = 1;  // 머리의 위치 x 
    int headRot = 1;    // 머리방향 0~3 = 위~왼 (시계방향)
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n;

    cin >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        applePos.push_back({ y,x });
    }
    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;char h;
        cin >> t >> h;
        turn.push_back({ t,h });
    }

    // 시뮬 시작
    // 종료조건: 1. 모든 사과 흭득? 2. 벽 충돌 3. 자신 충돌
    head h;
    body.push_back({ 1,1 });
    while (1) {
        // 이동
        int ny, nx;
        int nr = h.headRot;
        if (!turn.empty() && turn.front().first == gameTime) {
            if (turn.front().second == 'L') nr += 3;
            else nr += 1;
            nr %= 4;
            turn.erase(turn.begin());
        }
        ny = h.headY + dy[nr];
        nx = h.headX + dx[nr];

        gameTime++;

        // 충돌 판정
        if (ny <= 0 || nx <= 0 || ny > n || nx > n) { break; }
        if (find(body.begin(), body.end(), make_pair( ny,nx )) != body.end() ) { break; }
        
        bool eatApple = false;
        if ((!applePos.empty())) {
            auto pos = find(applePos.begin(), applePos.end(), make_pair(ny, nx));
            if (pos != applePos.end()) {
                eatApple = true;
                applePos.erase(pos);
            }
        }

        // 정보 리셋
        h.headY = ny;
        h.headX = nx;
        h.headRot = nr;

        body.push_front({ ny,nx });
        if (!eatApple) body.pop_back();
    }

    cout << gameTime;
    return 0;
}

// deque(덱)와 queue 차이

// turn을 벡터로 하는 것이 최선인가

// 요소 찾기 중 make_pair를 써야 할 때

// 벡터 특정 값의 인덱스를 이용해서 삭제하는 방법
// applePos.erase( applePos.begin() + pos -1); -> find의 반환형은 int가 아닌 반복자임, 그리고 반복자와 int는 같이 사용할 수 있지만 권장되지 않음

/*
if ((!applePos.empty())) {
            auto pos = find(applePos.begin(), applePos.end(), make_pair(ny, nx));
            if (pos != applePos.end()) {
                eatApple = true;
                applePos.erase(pos);
            }
        }
*/

// 디버그 - 조건 분기별로 이유 넣기 ex) 벽 충돌!, 자기자신 충돌

// 자료구조에 접근할 때, 비어있는지 확인하기