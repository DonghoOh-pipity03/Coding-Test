// 1436
#include<bits/stdc++.h>
using namespace std;
int n, num = 665, numCnt;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (1) {
		num++;
		if (to_string(num).find("666") != string::npos) numCnt++;
		if (n == numCnt) {
			cout << num;
			return 0;
		}
	}
}

// 무식하게 풀 수 있는지 -> 그에 따라 적용할 알고리즘이 있는지
//
// 무식하게? -> 시간복잡도가 크네? / 되네?
// 완전탐색? -> DP, 그리디
// 무식하게? -> 정렬 -> 이분탐색
//
// 
// find() -> 위치를 알려주거나, 없으면 끝 점을 반환함 -> 있는지 없는지를 알려면 == string::npos
