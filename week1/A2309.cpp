#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, excess;
    vector<int> heights;

    while (cin >> n) {
        //if (n == 0) break;
        heights.push_back(n);
    }

    sort(heights.begin(), heights.end());

    for (int i : heights) sum += i;
    excess = sum - 100;

    for (int i = heights.size() - 1; i > 0; i--) {
        for (int j = heights.size() - 2; j >= 0; j--) {
            if (heights[i] + heights[j] == excess) {
                heights.erase(heights.begin() + i);
                heights.erase(heights.begin() + j);

                for (int i : heights) cout << i << endl;
                return 0;
            }
        }
    }
}


/*
내가 생각한 알고리즘

1. 9개 정렬하기
2. 9개 모두 더하고 초과수 찾기
3. 큰 수부터 초과수가 되는 2개의 조합 찾기 및 제거


강의 알고리즘
방법 1: 9p7 순열로 합이 100이 되는 경우를 찾기
방법 2: 내가 생각한 방법과 거의 유사
*/
/*
#include <bits/stdc++.h>
using namespace std;  
int a[9]; 
int main() {
    ios_base::sync_with_stdio(false);   // 싱글 쓰레드환경에서, 빠른 연산을 위한 구문
    cin.tie(NULL);  // 입력과 출력을 반복하는 경우, 빠른 연산을 위한 구문
    cout.tie(NULL); // 입력과 출력을 반복하는 경우, 빠른 연산을 위한 구문
    for(int i = 0; i < 9; i++){
        cin >> a[i]; 
    }
    sort(a, a + 9);
    do{ // 0~6의 합이 100이 되는지 찾는다.
        int sum = 0; 
        for(int i = 0; i < 7; i++) sum += a[i]; 
        if(sum == 100)break;
    }while(next_permutation(a, a + 9)); // 0~6의 합이 100이 안되는 경우, 다음 순열을 돌린다.
    // (next_permutation은 오름차순 기반의 '배열'을, 순차적으로 순서가 있는 랜덤조합을 돌리는 함수이다.)
    for(int i = 0; i < 7; i++) cout << a[i] << "\n"; 
    return 0;
}
*/