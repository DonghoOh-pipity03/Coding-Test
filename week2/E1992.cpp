// 1992 - 단순 분리 & 재귀함수
#include<bits/stdc++.h>
using namespace std;

const int max_n = 65;
int n, a[max_n][max_n];

string Quad(int _x, int _y, int _s) {
	string r = "";	// !!!
	if (_s == 1) return string(1, a[_y][_x]);	// !!!
	else {
		int init = a[_y][_x];
		for (int i = 0; i < _s; i++) {
			for (int j = 0; j < _s; j++) {
				if (init != a[_y + i][_x + j]) {
					r += '(';
					r += Quad(_x, _y, _s / 2);
					r += Quad(_x + (_s / 2), _y, _s / 2);
					r += Quad(_x, _y + (_s / 2), _s / 2);
					r += Quad(_x + (_s / 2), _y + (_s / 2), _s / 2);
					r += ')';
					return r;
				}
			}
		}
		return string(1, init);	// !!!
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
		}
	}

	cout << Quad(0, 0, n) << endl;
}