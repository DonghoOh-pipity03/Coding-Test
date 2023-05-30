// 12851 - 1회차: 이론실패
#include<bits/stdc++.h>
using namespace std;

const int MAX = 200000;
int n, k, v[MAX+4], kind[MAX+4];
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	if (n == k) {
		puts("0"); puts("1");
		return 0;
	}

	q.push(n);
	v[n] = 1;
	kind[n] = 1;
	while (q.size()) {
		int curpos = q.front();
		q.pop();
		if (curpos == k) continue;
		for (int nextpos : {curpos-1, curpos+1, curpos*2}) {
			if (nextpos < 0 || nextpos >= MAX) continue;
			if (!v[nextpos]) {
				q.push(nextpos);
				v[nextpos] = v[curpos] + 1;
				kind[nextpos] += kind[curpos];
			}
			else if(v[nextpos] == v[curpos]+1){
				kind[nextpos] += kind[curpos];
			}
		}

	}

	cout << v[k] - 1 << '\n' << kind[k];

	return 0;
}

// '최단' -> BFS임을 잊음

// 최대 이동거리 20만일 수 있음

// 같은 위치에서 시작할 때의 예외처리를 안함

// for(int next : {now-1, now+1, now*2})로 나타낼 수 있음

// 자료구조 나누기를 안함
// 가짓수를 몇번 도착하는지에 따라 계산했는데,
// 가짓수 배열을 한개 더 만들어서 따로 계산하는 방법이 있음 -> 조건문 처리하기 더 간편해짐