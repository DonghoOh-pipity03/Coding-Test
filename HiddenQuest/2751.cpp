#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int cnt, tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	for (auto i : v) cout << i << '\n';

	return 0;
}

// set 느림
// 벡터 + sort + '\n' + ios_base ~ cin.tie() 로 해결