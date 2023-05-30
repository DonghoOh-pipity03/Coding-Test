#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int testCaseCnt, clothCnt, sum;
string clothName, clothKind;
unordered_map<string, int> cloth;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> testCaseCnt;

	for (int i = 0; i < testCaseCnt; i++) {
		cin >> clothCnt;
		for (int j = 0; j < clothCnt; j++) {
			cin >> clothName >> clothKind;
			cloth[clothKind]++;
		}
		sum = 1;
		for (auto j : cloth) {
			sum *= j.second + 1;
		}
		cout << (sum - 1) << "\n";
		cloth.clear();
	}
}

/*
개선 가능한 부분
1. for문 간편버전
cin >> t;
	while(t--){}
2. '경우의 수' 같은 경우에는 수가 매우 커질수 있기 때문에 long long을 사용하는 것을 추천한다.


*/

/*
#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main(){
	cin >> t;
	while(t--){
		map<string, int> _map;
		cin >> n;
		 for(int i = 0; i < n; i++){
			cin >> a >> b;
			_map[b]++;
		}
		long long ret = 1;
		for(auto c : _map){
			ret *= ((long long)c.second + 1);
		}
		ret--;
		cout << ret << "\n";
	}
	return 0;
}

*/