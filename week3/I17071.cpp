// 다시풀기
#include<bits/stdc++.h>
using namespace std;

const int MAX = 500000;
int n, k, v[2][MAX+4], moveSpeed = 1;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	if (n == k) {
		cout << "0";
		return 0;
	}

	int flag = 0;
	q.push(n);
	v[0][n] = 1;
	while (q.size()) {
		k += moveSpeed;
		if (k > 500000) break;
		if (v[moveSpeed % 2][k]) {
			flag = 1; break;
		}
		int QSize = q.size();
		for (int i = 0; i < QSize; i++) {
			int curPos = q.front();
			q.pop();
			for (int nextPos : {curPos - 1, curPos + 1, curPos * 2}) {
				if (nextPos < 0 || nextPos > MAX || v[moveSpeed % 2][nextPos]) continue;
				v[moveSpeed % 2][nextPos] = v[(moveSpeed + 1) % 2][curPos] + 1;
				if (nextPos == k) {
					flag = 1; break;
				}
				q.push(nextPos);
			}
			if (flag) break;
		}
		if (flag) break;
		moveSpeed++;
	}
	if (!flag) cout << "-1";
	else cout << moveSpeed;

	return 0;
}
