// 17071 - 
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1000000;
int n, k;
int v[MAX + 4], c[MAX + 4];
queue<pair<int, int>> q;
map<int, int> m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << "0";
		return 0;
	}

	int cnt = 1;
	int curChild = k;
	int childVector = 1;
	c[curChild] = cnt;

	while (1) {
		curChild += childVector;
		if (curChild > 500000) break;
		cnt++;
		childVector++;
		c[curChild] = cnt;
	}
	//cout << "done\n";

	q.push({ n,1 });
	m[n] = 1;
	int curPos, curVisit;
	while (q.size()) {
		tie(curPos, curVisit) = q.front();
		q.pop();
		//cout << "curVisit: " << curVisit << " curPos: " << curPos << " childPos: " << c[curPos] << '\n';
		if (curPos <= 500000 && curVisit <= c[curPos] && (c[curPos]-curVisit)%2 == 0) {
			//cout << c[curPos] - 1 << " curpos: " << curPos;
			cout << c[curPos] - 1;
			return 0;
		}
		for (int nextPos : {curPos - 1, curPos + 1, curPos * 2}) {
			if (nextPos < 0 || nextPos > MAX) continue;
			if (m[nextPos] == curVisit + 1 || curVisit > cnt) continue;
			q.push({ nextPos, curVisit + 1 });
			m[nextPos] = curVisit + 1;
		}
	}

	cout << "-1";

	return 0;
}