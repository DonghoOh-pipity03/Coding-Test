#include <bits/stdc++.h>
using namespace std;
int n, k, tmp, psum[100000], maxVal = -100 * 100000;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        psum[i] = psum[i - 1] + tmp;
    }

    for (int i = k; i <= n; i++) {
        maxVal = max(maxVal, psum[i] - psum[i - k]);
    }

    cout << maxVal;
    return 0;
}

// 1차 코딩
/*
#include <bits/stdc++.h>
using namespace std;

int tempSumCnt[2];
vector<int> ori, sum;
int tmp;

int main() {
    for (int i = 0; i < 2; i++) {
        cin >> tempSumCnt[i];
    }

    for (int i = 0; i < tempSumCnt[0]; i++) {
        cin >> tmp;
        ori.push_back(tmp);
    }

    tmp = 0;
    for (int i = 0; i < tempSumCnt[1]; i++) {
        tmp += ori[i];
    }
    sum.push_back(tmp);
    for (int i = 1; i < tempSumCnt[0] - tempSumCnt[1] + 1; i++) {
        tmp -= ori[i - 1];
        tmp += ori[i + tempSumCnt[1] - 1];
        sum.push_back(tmp);
    }

    sort(sum.rbegin(), sum.rend());

    cout << sum[0];
    return 0;
}
*/

/*
내가 생각한 알고리즘
1. 온도 개수와 합하는 개수를 입력받는다.
2. 온도를 입력받아 벡터에 저장한다.
3. 온도를 합하여 벡터에 저장한다.
4. 정렬 후, 가장 높은 온도를 출력한다.

개선점
1. 최댓값 구하기: 정렬보다, 순환하며 최댓값을 찾는 방법으로 하기
2. 한줄에 여러개를 입력받는 방법: cin >> n >> k;
3. 입출력 동기 해제로 빠르게 하기
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);

부분합: 0~k까지의 합
구간합: a~b까지의 합
*/

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, temp, psum[100001], ret = -1000000;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> temp; psum[i] = psum[i - 1] + temp;  // 누적합을 구한다.
    }
    for(int i = k; i <= n; i++){
        ret = max(ret, psum[i] - psum[i - k]);  // 누적합을 이용하여 각각의 구간합을 구하고, 최대값을 찾는다.
    }
    cout << ret << "\n";
    return 0;
}
*/