#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll go(ll _a, ll _b) {
	if (_b == 1) return _a % c;
	ll ret = go(_a, _b / 2);
	ret = (ret * ret) % c;
	if (_b & 1) ret = (ret * _a) % c;
	return ret;
}

int main() {
	cin >> a >> b >> c;
	cout << go(a, b) << "\n";
	return 0;
}


/*
개선 가능부분
1. 모듈러 성질을 이용하여, 주기적으로 나머지 연산을 해주어, 수의 크기를 줄여주어야 한다.
-지수법칙 : a^(n+m) = a^n * a^m
-모듈러 성질 : (a*b)%c = (a%c * b%c)%c

2. 함수 내의 지역변수 대신 전역변수를 써서 틀림.

*/

/*
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;
ll go(ll a, ll b){
    if(b == 1) return a % c;
    ll ret = go(a, b / 2);
    ret = (ret * ret) % c;
    if(b % 2)ret = (ret * a)% c;
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b >> c;
    cout << go(a, b) << "\n";
    return 0;
}
*/