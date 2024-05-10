#include<bits/stdc++.h>
using namespace std;

int n, m;
bool input[51][51];// 입력받을 체스판
int cnt[43][43];// 분석내용
int answer = INT_MAX;
int cmp = 85;  // 분석용 비트
int cmp2 = 170;  // 분석용 비트2

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력받기
    cin >> n >> m;
    cin.ignore();
    
    for (int i = 0; i < n; i++) {
        string val;
        getline(cin, val);
        for (int j = 0; j < m; j++) {
            if (val[j] == 'W') input[i][j] = true;
            else input[i][j] = false;
        }
    }

    // 한줄씩 분석하기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 7; j++) {
            // 비트 만들기
            int val = 0;
            for (int k = 0; k < 8; k++) {
                val += input[i][j + k] * (1 << k);
            }
            // 분석하기
            if(i%2) cnt[i][j] = __builtin_popcount(val ^ cmp);
            else cnt[i][j] = __builtin_popcount(val ^ cmp2);
        }
    }

    // 세트별 최솟값 구하기
    for (int i = 0; i < n - 7; i++) {
        for (int j = 0; j < m - 7; j++) {
            int sum = 0;
            for (int k = 0; k < 8; k++) {
                sum += cnt[i + k][j];
            }
            sum = min(sum, 64 - sum);
            answer = min(answer, sum);
        }
    }

    // 출력
    cout << answer;
}

/*
사람들은 그냥 
char BW = 'W', 'B', 'W', 'B', 'W', 'B'...
char BB = 'B', 'W', 'B', 'W', 'B', 'W'...
를 만들고 for문이랑 if문으로만 간단히 구현함
2020kb 0ms로 내가 만든 것 보다 메모리를 16kb 더 적게 사용함.
설계구현시간도 더 적었을 것

교훈
먼저 무식하게 풀수 있는지 확인하기 
# 1억 연산에 1초로 생각하기
시간복잡도가 크면, 그 때 고급 알고리즘을 생각하기
*/