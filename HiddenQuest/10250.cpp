#include<bits/stdc++.h>
using namespace std;

int cnt, h, w, n;

int main() {
	
	cin >> cnt;

	while (cnt--) {
		cin >> h >> w >> n;

		int x = n % h;
		if (x == 0) x = h;
		string x2 = to_string( x );

		int y = (n / h);
		if (n % h) y++;
		string y2;
		if (y < 10) y2 = "0" + to_string(y);
		else y2 = to_string(y);

		cout << x2 << y2 << endl;
	}

	return 0;
}
