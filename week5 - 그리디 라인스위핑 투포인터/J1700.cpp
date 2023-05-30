#include<bits/stdc++.h>
using namespace std;

int n, k, answer, a[104], visited[104]; // 사용 순서  
vector<int> v;  // 멀티탭
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    // 입력
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
        
    // 프로세싱
    for (int i = 0; i < k; i++) {
        // 스왑 불필요
        if (visited[a[i]]) continue;

        // 스왑 필요 - swap out - Optimal
        if (v.size() == n) {
            // 사용중인 프로세스를 순회하며, Optimal
            int lastestProcess = 0, lastestTime = 0;    // 교체 대상의 프로세스, 시간
            for (auto p : v) {
                int curTime = INT_MAX;  // 현재 프로세스의 예상 재등장시간
                for (int j = i + 1; j < k; j++) {   // 끝까지 순회
                    if (a[j] == p) {    // 찾음
                        curTime = j; 
                        break;
                    }
                }
                if (curTime > lastestTime) { // 당선
                    lastestTime = curTime;
                    lastestProcess = p;
                }
            }
            // swap out
            visited[lastestProcess] = 0;
            v.erase(find(v.begin(), v.end(), lastestProcess));
            answer++;
        }
        // swap in
        v.push_back(a[i]);
        visited[a[i]] = 1;
    }

    cout << answer << '\n';
    return 0;
}

// 그리디 - 스와핑 - Opimal: 가장 먼 미래에 사용하지 않을 것을 교체

// cin >> a[i];

// 백준에서 #define _CRT_SECURE_NO_WARNINGS  쓰면 틀리나?