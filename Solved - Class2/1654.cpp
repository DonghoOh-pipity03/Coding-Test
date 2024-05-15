#include<bits/stdc++.h>
using namespace std;

int n, k, answer;
unsigned int h, l;
vector<int> cable;

// 자르는 케이블 길이를 입력받아서, 몇개의 케이블이 나오는지 반환하는 함수
int GetCnt(int _l) {
    int cnt = 0;
    for ( int i : cable) {
        cnt += i / _l;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    h = 0; l = 1; answer = 0;
    // 입력
    cin >> k >> n;
    for (int i = 0; i < k; i++) {
        int tmp;
        cin >> tmp;
        cable.push_back(tmp);
        h = max((int)h, tmp);
    }
    
    // 탐색
    while (h >= l) {
        // 탐색 지정
        int next = ((unsigned int)h + (unsigned int)l) / 2;
        // 확인
        int cnt = GetCnt(next);
        // 세팅
        // 부족
        if (cnt < n) { h = next - 1; }
        // 넘음
        else {
            answer = max(answer, next);
            l = next + 1; 
        }
    }

    cout << answer;
}


/*
이분탐색
찾으려는 값의 최소최대인 low, hi를 저장하고, 다음탐색 목표인 가운데 값 mid를 저장한다.
분기에서 탐색 값이 큼/작음/같음에 따라, 로우나 하이를 줄여나간다. 이때 탐색값을 기준으로 +-1해서 지정한다.

탐색 분기 - 같을 때
문제의 조건에따라 작거나 큰 if문에 편입한다.

hi, low 지정 방법
입력 값의 최대/최솟값으로 초기화한다.


unsigned int h, l;
int의 최댓값은 2,147,483,647
int의 최댓값이 int의 최대값이면, unsigned int를 사용하고, 연관된 변수들도 연산 중에 unsigned int로 바꿔야 하는지 주의해야한다.
*/