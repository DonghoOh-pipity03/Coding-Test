// 9934 - BFS
// 1회차 - 성공(푸는 시간이 오래걸림)

#include<bits/stdc++.h>
using namespace std;

int k, a[1028], v[1028];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < pow(2,k)- 1; i++) {
		cin >> a[i];
	}
	
	int root = pow(2, k) / 2 - 1;
	q.push(root);	// 루트 인덱스 삽입
	v[root] = 1;
	while (q.size()) {
		int QSize = q.size();
		while (QSize) {
			int cur = q.front();
			q.pop();
			QSize--;
			cout << a[cur] << ' ';
			int gap = pow(2,k-v[cur]-1);
			if (gap < 1) continue;
			int next1 = cur - gap;
			q.push(next1);
			v[next1] = v[cur] + 1;
			int next2 = cur + gap;
			q.push(next2);
			v[next2] = v[cur] + 1;
		}
		cout << '\n';
	}
	
	return 0;
}

// 제곱 구하는 방법
// pow(a,b) // a의 b제곱
// 
// 변수간의 관계식 도출은 손으로 계산하면서 하기