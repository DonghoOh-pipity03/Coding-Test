// 1325 - 브루트포스
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int cnt[10001];
vector<int> v[10001];

int bfs(int _curNode) {
	int visited[10001] = {};
	queue<int> q;
	q.push(_curNode);
	visited[_curNode] = 1;
	int move = 1;

	while (q.empty() == 0) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]] != 1) {
				q.push(v[cur][i]);
				visited[v[cur][i]] = 1;
				move++;
			}
		}
	}
	return move;
}

int main() {

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[b].push_back(a);
	}

	int maxCnt = 0;

	for (int i = 1; i <= n; i++) {
		cnt[i] = bfs(i);
		maxCnt = max(cnt[i], maxCnt); //
	}

	for (int i = 1; i <= n; i++) {
		if (maxCnt == cnt[i]) printf("%d ", i);
	}

	return 0;
}