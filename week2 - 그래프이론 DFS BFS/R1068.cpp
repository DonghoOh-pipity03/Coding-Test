// 1068 - 절단점 -> BFS X
// DFS, Vector
#include<bits/stdc++.h>
using namespace std; 

int n, d, t, answer, root;
vector<int> v[51];	// 입력은 최대 50개가 들어므로, 부모는 최대 50개 최소 1개가 될수 있다.

int dfs(int _parrent){
	int ret = 0, c = 0;
	for (auto i : v[_parrent]) {
		if (i == d) continue;
			c++;
			ret += dfs(i);
	}
	if (c == 0) ret++;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (t == -1) root = i;
		else v[t].push_back(i);
	}
	cin >> d;

	if (d == root) {
		cout << '0' << '\n';
		return 0;
	}
	
	cout << dfs(root) << '\n';

	return 0;
}

// 1. BFS로 생각함 -> DFS

// 2. 트리 구현을 위한 자료구조를 선택하지 못함 -> 벡터

// 3. '삭제되는 노드의 번호'를 해석하지 못함 -> 입력된 노드를 바탕으로 0, 1, 2...로 불리는 기준이다.

// 4. 문제 범위를 이해하지 못함 -> 들어오는 개수가 50이하 인 것이고, 최대 (전체 트리 번호 기준으로) 노드 번호가 몇인지는 모르는 상황이다.

// 5. vector<int> adj[ 54 ] -> int형 벡터를 저장하는 54공간의 생성한다.
// 1차원 공간은 고정 + 최대 54갸, 2차원 공간은 가변 + 벡터 자료구조
// adj[ 부모 ].push_back( 노드번호 )