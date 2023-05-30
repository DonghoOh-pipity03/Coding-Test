#include<bits/stdc++.h>
using namespace std;

int che[10000], m, n, sum, minVal;

int main() {
	cin >> m >> n;

	che[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; ; j++) {
			if (i * j > n) break;
			if (che[i * j]) continue;
			che[i * j] = 1;
		}
	}

	for (int i = m; i <= n; i++) {
		if (che[i] == 0) {
			if (minVal == 0) minVal = i;
			sum += i;
		}
	}

	if (sum == 0) cout << "-1";
	else cout << sum << '\n' << minVal << endl;

	return 0;
}
