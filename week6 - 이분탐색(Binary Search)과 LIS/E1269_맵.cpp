#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int n, m, answer, temp;
unordered_map<int, int> um;
    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp; um[temp]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> temp; um[temp]++;
    }

    for (auto i : um) if (i.second == 1) answer++;

    cout << answer;
    return 0;
}

// nuordered_map - O( 1 ) - 148ms

// 실수 - 변수를 혼용해서 억까를 해결하는데 30분을 썼다.
// int n, m과 unordered_map m