// 1325 - 브루트포스
#include<bits/stdc++.h>
using namespace std; 

int n, m, a, b;
int maxCnt, cnt[10001], visited[10001];
vector<int> v[10001];

int dfs(int _curNode) {
	visited[_curNode] = 1;
	int move = 1;
	for (auto i : v[_curNode]) {
		if (visited[i] == 1) continue;	// visited 빼먹음
		move += dfs(i);
	}
	return move;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	while (m--) {
		cin >> a >> b;
		v[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {	// 1부터 n으로 하지 않고, 0부터 시작함
		memset(visited, 0,  10001 * sizeof(int));
		if(v[i].size() != 0) cnt[i] = dfs(i);
		maxCnt = max(cnt[i], maxCnt);
	}

	for (int i = 1; i <= n; i++) {	// 1부터 n으로 하지 않고, 0부터 시작함
		if (maxCnt == cnt[i]) cout << i << " ";
	}

	return 0;
}

//
// 생각한 알고리즘 1.
// (1) 입력받으면서, N 개 중에서 신뢰받는 Com과 연결되지 않은 Com 기록
// (2) N 개 중, (1)의 Com을 제외하여 말단 노드 Com을 구함
// (3) (2)의 후보 노드별로 최장거리 구하기
//
// 
// 생각한 알고리즘 2.
// (1) N( <= 10000)의 노드별로 최장거리를 확인
// #브루트포스 #BFS #인접리스트
// 
// 