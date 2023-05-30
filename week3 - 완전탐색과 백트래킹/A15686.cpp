// 15686 - 완전탐색, 경우의 수
#include <bits/stdc++.h>
using namespace std;

int n, m, answer;
int a[54][54];
vector<pair<int,int>> c, h;
vector< vector<int>> case_chicken;

void combi(int _start, vector<int> _v) {
	if (_v.size() == m) {
		case_chicken.push_back(_v);
		return;
	}
	for (int i = _start + 1; i < c.size(); i++) {
		_v.push_back(i);
		combi(i, _v);
		_v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	answer = INT_MAX;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) { 
				h.push_back({ i,j });
			}
			else if (a[i][j] == 2) {
				c.push_back({ i,j });
			}
		}
	}

	vector<int> v;
	combi(-1, v);
	for (vector<int> i : case_chicken) {	// 치킨집 경우 수마다
		int dist = 0;

		for (pair<int, int> j : h) {	// 집마다
			int dist2 = INT_MAX;
			for (int k : i) {	// 집별로 치킨집마다
				int dist3 = abs(c[k].first - j.first)+abs(c[k].second - j.second);
				dist2 = min(dist2, dist3);
			}
			dist += dist2;
		}

		answer = min(dist, answer);
	}
	cout << answer << '\n';

	return 0;
}

// (1) 경우의 수 구현을 못했음
// (2) int 최댓값
// (3) 변수명 오타가 2틀연속 발생중