// J 10709

#include<bits/stdc++.h>
using namespace std;

int h, w;
string s;
int a[101][101], b[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		cin >> s;
		for (int j = 0; j < w; j++) {

			if (s[j] == 'c') a[i][j] = 1;
		}
	}

	for (int i = 0; i < h; i++) {
		int prevC = -1;
		
		for (int j = 0; j < w; j++) {
			// 구름지역
			if (a[i][j] == 1) {
				prevC = j;
				b[i][j] = 0;
			}
			// 구름X지역
			else {
				// 구름 안 올 지역
				if (prevC == -1) b[i][j] = -1;
				// 구름 올 지역
				else b[i][j] = j - prevC;
			}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << b[i][j] << " ";
		}
		cout << "\n";
	}
}