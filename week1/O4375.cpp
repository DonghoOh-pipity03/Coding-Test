#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll cmp;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n) {
		cmp = 0;
		for (int i = 1; 1; i++) {
			cmp = (cmp * 10) + 1;
			cmp %= n;
			if (cmp % n == 0) {
				cout << i << "\n";
				break;
			}
		}
	}

	return 0;
}

/*
보완 가능한 부분
1. 모듈러 연산이 +-에도 적용이 가능한지 몰랐음
[(a mod n)+(b mod n)] mod n = (a+b) mod n
[(a mod n)-(b mod n)] mod n = (a-b) mod n
[(a mod n)*(b mod n)] mod n = (a*b) mod n
따라서 cmp에 *10 +1을 하고나서, 미리 모듈러연산으로 수를 줄일 수 있음
*/

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int main(){
	while(scanf("%d", &n) != EOF){
		int cnt = 1, ret = 1;
		while(true){
			if(cnt % n == 0){
				printf("%d\n", ret);
				break;
			}else{
				cnt = (cnt * 10) + 1;
				cnt %= n;
				ret++;
			}
		}
	}
	return 0;
}
*/