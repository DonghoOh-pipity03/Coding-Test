#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int a, b;
int x[10001] = {};
vector<int> arr[10001];

int bfs(int start) {
	int visit[10001] = {};
	queue<int> q;
	q.push(start);
	visit[start] = 1;

	int cnt = 1;

	while (q.empty() == 0) {
		int t = q.front();
		q.pop();
		for (int i = 0; i < arr[t].size(); i++) {
			if (visit[arr[t][i]] != 1) {
				q.push(arr[t][i]);
				visit[arr[t][i]] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	scanf("%d %d", &a, &b);

	for (int i = 0; i < b; i++) {
		int s, e;
		scanf("%d %d", &s, &e);

		arr[e].push_back(s);
	}

	int max = 0;

	for (int i = 1; i <= a; i++) {
		x[i] = bfs(i);
		if (max <= x[i]) {
			max = x[i];
		}
	}

	for (int i = 1; i <= a; i++) {
		if (x[i] == max) {
			printf("%d ", i);
		}
	}

	return 0;
}