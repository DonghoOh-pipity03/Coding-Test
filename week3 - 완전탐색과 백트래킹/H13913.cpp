// 13913 - 1회차 이론 성공 (자료구조 일부실패)
#include<bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k, visited[MAX+4], prevVisited[MAX+4];
vector<int> v;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		cout << "0\n" << n;
		return 0;
	}

	q.push(n);
	visited[n] = 1;
	prevVisited[n] = -1;
	while (q.size()) {
		int curPos = q.front();
		q.pop();
		if (curPos == k) {
			v.push_back(curPos);
			int temp = prevVisited[curPos];
			while (temp != -1) {
				v.push_back(temp);
				temp = prevVisited[temp];
			}
			break;
		}
		for (int nextPos : {curPos - 1, curPos + 1, curPos * 2}) {
			if (nextPos < 0 || nextPos > MAX) continue;
			if (visited[nextPos]) continue;
			q.push(nextPos);
			visited[nextPos] = visited[curPos] + 1;
			prevVisited[nextPos] = curPos;
		}
	}

	cout << visited[k] - 1 << '\n';
	while (v.size()) {
		cout << v.back() << ' ';
		v.pop_back();
	}

	return 0;
}

// 최단경로를 2차원 벡터에 담으려 했다.
// -> 배열의 각 노드에 이전 노드의 인덱스를 저장하는 자료구조 사용하기