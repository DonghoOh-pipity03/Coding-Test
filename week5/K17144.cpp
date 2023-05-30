#include<bits/stdc++.h>
using namespace std;

int r, c, t;
int dustBefore[54][54], dustAfter[54][54];   // 시뮬 전과 후의 먼지 분포 배열
vector<pair<int, int>> cleaner; // 공기청정기 위치 - 위, 아래
vector<tuple<int, int, int>> flow;  // 공기청정기 바람흐름_역주행 순으로 저장됨, 0~3은 위부터 시계방향, 4는 삭제
int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> r >> c >> t;
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < c; i++) {
            int tmp;
            cin >> tmp;
            dustBefore[j][i] = tmp;
            if (tmp == -1) {
                cleaner.push_back({ j,i });  // 청정기 위치 저장
                dustBefore[j][i] = 0;
            }
        }
    }

    // 공기흐름 구하기
    for (int i = cleaner[0].first - 1; i >= 0; i--) {   // 위 - 왼
        if(i == cleaner[0].first - 1) flow.push_back({ i, 0, 4 });
        else flow.push_back({ i, 0, 2 });
    }
    if (cleaner[0].first != 0) {   // 위 - 위
        for (int i = 1; i < c; i++) {
            flow.push_back({ 0, i, 3 });
        }
    }
    for (int i = 1; i <= cleaner[0].first; i++) {   // 위 - 오
        flow.push_back({ i, c-1, 0 });
    }
    for (int i = c-2; i >= 0; i--) {   // 위 - 아
        flow.push_back({ cleaner[0].first, i, 1 });
    }

    for (int i = cleaner[1].first + 1; i <= r; i++) {   // 아 - 왼
        if (i == cleaner[1].first + 1) flow.push_back({ i, 0, 4 });
        else flow.push_back({ i, 0, 0 });
    }
    if (cleaner[1].first != r-1) {   // 아 - 아
        for (int i = 1; i < c; i++) {   
            flow.push_back({ r-1, i, 3 });
        }
    }
    for (int i = r-1; i >= cleaner[1].first; i--) {   // 아 - 오
        flow.push_back({ i, c-1, 2 });
    }
    for (int i = c-1; i >= 0; i--) {   // 아 - 위
        flow.push_back({ cleaner[1].first, i, 1 });
    }


    // 시뮬레이션 하기
    for (int cnt = 0; cnt < t; cnt++) {
        // 먼지 시뮬레이션 
        for (int j = 0; j < r; j++) {
            for (int i = 0; i < c; i++) {
                // 퍼지기
                if (dustBefore[j][i]) {
                    int moveCnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int ny = j + dy[k];
                        int nx = i + dx[k];
                        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
                        if ( nx == 0 && (ny == cleaner[0].first || ny == cleaner[1].first)) continue;
                        moveCnt++;
                        dustAfter[ny][nx] += int(dustBefore[j][i] / 5);
                    }
                    dustAfter[j][i] += dustBefore[j][i] - int(dustBefore[j][i] / 5) * moveCnt;
                }
            }
        }

        // 공기청정기 시뮬레이션
        for (auto i : flow) {
            int y = get<0>(i);
            int x = get<1>(i);
            int order = get<2>(i);
            if (order == 4) dustAfter[y][x] = 0;
            else if (order == 0) dustAfter[y - 1][x] = dustAfter[y][x];
            else if (order == 1) dustAfter[y][x+1] = dustAfter[y][x];
            else if (order == 2) dustAfter[y+1][x] = dustAfter[y][x];
            else if (order == 3) dustAfter[y][x-1] = dustAfter[y][x];
            dustAfter[y][x] = 0;
        }

        memcpy(dustBefore, dustAfter, sizeof(dustAfter));
        memset(dustAfter, 0, sizeof(dustAfter));
    }

    // 남은 먼지 양 구하기
    int answer = 0;
    for (int j = 0; j < r; j++) {
        for (int i = 0; i < c; i++) {
            if (dustBefore[j][i] > 0) answer += dustBefore[j][i];
        }
    }

    cout << answer;
    return 0;
}

// 헹열 위치 

// cleaner[1].first()로 잘못 접근함
// cleaner[1].first

// 문제 잘못 이해함
// 디버그 방법 - 중간에 맵을 그려서 한단계씩 확인하기

// 배열 복사방법