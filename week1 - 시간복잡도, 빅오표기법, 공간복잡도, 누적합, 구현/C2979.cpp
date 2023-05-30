#include <bits/stdc++.h>
using namespace std;

int main() {
    int entireParkingTime[100] = { 0, };
    int parkingTimePerCount[4] = { 0, };

    int parkingTime[3][2] = { {0,0}, };
    int costPerCount[3] = { 0, };

    int cost = 0;

    for (int i = 0; i < 3; i++) {
        cin >> costPerCount[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> parkingTime[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = parkingTime[i][0] - 1; j < parkingTime[i][1] - 1; j++) {
            entireParkingTime[j]++;
        }
    }

    for (int i = 0; i < 100; i++) {
        parkingTimePerCount[entireParkingTime[i]]++;
    }

    for (int i = 1; i < 4; i++) {
        cost += parkingTimePerCount[i] * costPerCount[i - 1] * i;
    }

    cout << cost;
    return 0;
}

/*
내가 생각한 알고리즘
1. 0-99 배열에 주차 시간을 차례로 넣는다.
2. 1,2,3대 주차시간을 추출한다.
3. 요금을 계산해서 리턴한다.

개선 가능점
1. 코드 수 줄이기: 변수 선언을 전역변수로 하고, 입력과 동시에 데이터 처리를 해서 코드 수 줄이기
*/

/*
#include <bits/stdc++.h>
using namespace std;
int A, B, C, a, b, cnt[104], ret;
int main(){
    cin >> A >> B >> C; // 여러 변수 입력 방법
    for(int i = 0; i < 3; i++){ // 입력과 동시에 시간 기록하기
        cin >> a >> b;
        for(int j = a; j < b; j++)cnt[j]++;
    }
    for(int j = 1; j < 100; j++){   // 시간 체크와 계산을 동시에 하기
        if(cnt[j]){
            if(cnt[j] == 1) ret += A;
            else if(cnt[j] == 2)ret += B * 2;
            else if(cnt[j] == 3)ret += C * 3;
        }
    }
    cout << ret << "\n";
    return 0;
}
*/