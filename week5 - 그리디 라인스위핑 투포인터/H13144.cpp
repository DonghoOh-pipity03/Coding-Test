#include<bits/stdc++.h>
using namespace std;

long long p1, p2, n, a[100001], v[100001];
long long answer;

int main() {

    // 헤더 입력
    cin >> n;

    // 수열 입력
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    // 탐색
    while (p2 < n) {
        // 중복 X
        if (v[a[p2]] == 0) {
            v[a[p2]]++;
            p2++;
        }
        // 중복 O
        else {
            answer += (long long)(p2 - p1);
            v[a[p1]]--;
            p1++;
        }
    }

    answer += (long long)((p2 - p1 + 1) * (p2 - p1) / 2);

    cout << answer;
    return 0;
}

// 1. vector의 선언과 크기지정을 동시에 하는법
// vector<int> input(inputLength);
// () 소괄호임을 주의하기

// 2. 간단하게 입력받기 
// scanf("%d", a+i);

// 문제 잘 못 파악함
// 수열이 한자리 수들로 이루어진 것이 아님
// 100000이하 정수임

// 카운팅 배열 -> int 배열에 몇 개가 카운트 되었는지 저장한다.

// 경우의 수 유형이면 모두 long long을 사용하기!!!!!!!
// long long으로 바꿔서 통과함

/*
코딩 틀렸을 때 체크리스트

1. 입출력 제한사항
이상,이하,초과,미만 

2. 자료 크기
경우의 수: int -> long long

3. 예외처리

4. 시공간 제한

5. 문제 파악을 제대로 했는가
*/
