// 2828 - 단순 
#include<bits/stdc++.h>
using namespace std;

int n, m, j, apple[20], cur, cnt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cur = 1;
	cin >> n >> m >> j;
	for (int i = 0; i < j; i++) {
		cin >> apple[i];
	}

	for (int i = 0; i < j; i++) {
		// 이동 불필요
		if (apple[i] >= cur && apple[i] <= (cur + m - 1)) continue;
		// 이동 필요
		else {
			// 왼쪽 이동
			if (apple[i] < cur) {
				int move = cur - apple[i];
				cnt += move;
				cur -= move;
			}
			// 오른쪽 이동
			else {
				int move = apple[i] - (cur + m - 1);
				cnt += move;
				cur += move;
			}
		}
	}

	cout << cnt << endl;
}