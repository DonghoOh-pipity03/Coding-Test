#include<bits/stdc++.h>
using namespace std;

int n, answer = INT_MIN;

// 드래그 명령 함수
struct stage {
    int a[21][21] = {0,};

    // 가장 큰 블록을 구하는 함수
    int GetBigBlock() {
        int val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                val = max(val, a[i][j]);
            }
        }
        return val;
    }

    // 시계방향으로 90도 회전시키는 함수
    stage Rotation() {
        stage returnStage;
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                returnStage.a[i][n - j - 1] = a[j][i];
            }
        }
        return returnStage;
    }

    // 왼쪽으로 드래그하는 함수
    // 임시 벡터에 행의 요소를 추가한다, flag가 0이면 마지막 추가요소와 결합하지 않는다.
    stage Move() {
        stage returnStage;
        for (int j = 0; j < n; j++) {
            int flag = 0;
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (a[j][i] == 0) continue;
                if( flag && tmp.back() == a[j][i]) {  // 결합하고 추가
                    tmp.pop_back();
                    tmp.push_back(2 * a[j][i]);
                    flag = 0;
                }
                else{    // 결합을 안하고 추가
                    tmp.push_back(a[j][i]);
                    flag = 1;
                }
            }
            // 행 생성
            for (int i = 0; i < tmp.size(); i++) {
                returnStage.a[j][i] = tmp[i];
            }
        }
        return returnStage;
    }

};

// 조합 함수
void go(int _cnt, stage _stage) {
    // 재귀 종료
    if (_cnt == 0) {
        answer = max(answer, _stage.GetBigBlock());
        return;
    }
    // 조합 실행
    else {
        stage newStage = _stage;
        for (int i = 0; i < 4; i++) {
            go(_cnt - 1, newStage.Move());     // 재귀, 드래그
            newStage = newStage.Rotation();     // 회전
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n;
    stage originalA;
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            cin >> originalA.a[j][i];
        }
    }

    // 조합
    go(5, originalA);

    cout << answer;
    return 0;
}

// 2차원 벡터 동적으로 생성하기

// 2차원 배열을 리턴하는 방법 3가지

// 구조체 안에 함수를 작성하는 경우

// 2차원 배열에서 가장 큰 수를 찾는 방법

// returnStage[j][i] = tmp[i];  오류
// returnStage.a[j][i] = tmp[i]; 정답

// 쓰레기값이 찍혀서 의도하지 않은 값이 나옴