// K 3474
// 10을 만드는 것은 2와 5 -> 2와 5의 개수를 구하고 min값을 구하면 된다.
// 2와 5개수를 구하는 방법은 블로그 참고
#include<bits/stdc++.h>
using namespace std;
int t, a;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;

	while (t--) {
		cin >> a;
		int result = 0, b = 0, c = 0;
		for (int i = 2; i <= a; i *= 2) {
			b += a / i;
		}
		for (int i = 5; i <= a; i *= 5) {
			c += a / i;
		}
		cout << min(b,c) << "\n";
	}
	return 0;
}