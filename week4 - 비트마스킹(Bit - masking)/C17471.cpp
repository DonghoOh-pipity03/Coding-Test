// 17471 - 
// 1회차 - 성공(디버그 4시간)
#include<bits/stdc++.h>
using namespace std;

int n, man[10], minMan = INT_MAX, visited[10];
vector< vector<int> > v(10);
vector<int> a, b;

void dfs(int cur, vector<int> team) {
	visited[cur] = 1;
	for (auto j : v[cur]) {
		if (visited[j]) continue;
		if (find(team.begin(), team.end(), j) == team.end()) continue;
		else{ dfs(j, team); }
	}
}

bool check() {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	for (auto i : a) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i, a);
		}
	}
	if (cnt != 1) return false;

	memset(visited, 0, sizeof(visited));
	cnt = 0;
	for (auto i : b) {
		if (visited[i] == 0) {
			cnt++;
			dfs(i, b);
		}
	}
	if (cnt != 1) return false;

	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {cin >> man[i];}
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		cin >> tmp;
		for (int j = 0; j < tmp; j++) {
			int tmp2;
			cin >> tmp2;
			v[i].push_back(tmp2-1);
		}
	}
	
	for (int i = 1; i < (1 << n) - 1; i++) {	// 모든 경우의 수
		for (int j = 0; j < n; j++) {	
			if (i & (1 << j)) {a.push_back(j);}
			else {b.push_back(j);}
		}
		if (check()) {	// 연결확인 및 최솟값 더하기
			int ASum = 0, BSum = 0;
			for (auto i : a) { ASum += man[i]; }
			for (auto i : b) { BSum += man[i]; }	
			minMan = min(minMan, abs(ASum - BSum));
		}
		a.clear();
		b.clear();
	}

	if (minMan == INT_MAX) cout << -1;
	else cout << minMan;
	return 0;
}


// 8:00
// 처음 생각한 알고리즘
// 비트 X 경우의 수로 모든 경우를 탐색
// DFS로 각 경우의 연결을 확인
// 최솟값 확인 
//
// 2차원 벡터를 선언할 때, 몇 행인지 아는 경우의 선언
// -> vector< vector<int> > v(14);
// 
// i < (1<<n)
// # 미포함해야한다. i는 1부터 시작
//
// 디버그 방법1_비트 경우의 수
// 조건이 되는 경우의 수 if문을 만들고 pause를 걸어놓는다.
// 이후 한단계씩 메모리를 조사하면서, 업보를 청산한다.
// 
// 디버그 방법2
// 백준 질문 게시판에서 반례 찾아서 적용해보기
// 
// DFS에서 같은 지역구인지 확인하는 조건을 생각하지않아서,
// 하루를 날렸다.
// 
// 벡터 요소가 있는지 찾는법
// find(v.begin(), v.end(), 찾는 요소) == v.end()	// true면 없음
//