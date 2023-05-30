// 19942 - 
// 1회차 - 실패
#include<bits/stdc++.h>
using namespace std;

int n, min_nutrition[4], food_list[16][5];
int min_val=INT_MAX;
int temp_nutrition[4], sum;
//vector<int> temp_foodlist;
map< int, vector< vector<int> > > foods; // 각 요금별로  재료 조합들을 저장한다.

bool CMP_Nutrition() {
	for (int i = 0; i < 4; i++) {
		if (min_nutrition[i] > temp_nutrition[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> min_nutrition[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> food_list[i][j];
		}
	}

	for (int i = 0; i < (1 << n); i++) {	// 모든 경우의 수를 탐색
		vector<int> temp_foods;
		memset(&temp_nutrition[0],0,sizeof(temp_nutrition));
		sum = 0;
		for (int j = 0; j < n; j++) {		// 각 요소별로 for문을 돌면서
			if (i & (1 << j)) {			// 1번 루프에 요소가 있는지 확인
				temp_foods.push_back(j);
				sum += food_list[j][4];
				for (int k = 0; k < 4; k++) temp_nutrition[k] += food_list[j][k];
			}
		}
		if (CMP_Nutrition()) {
			if (min_val >= sum) {
				min_val = sum;
				foods[sum].push_back(temp_foods);
			}
		}
	}

	// 답 출력
	sort(foods[min_val].begin(), foods[min_val].end());
	if (min_val == INT_MAX)cout << "-1";
	else {
		cout << min_val << '\n';
		for (auto i : foods[min_val][0]){
			cout << i+1 << ' ';
		}
	}

	return 0;
}

// 1. 비트마스킹을 이용한 조합 탐색
// (1) 2진법을 이용해 모든 경우의 수를 돌린다.
// (2) 각 요소별 for문을 돌린다.
// (3) (1)과 (2)를 비트 연산자로 비교해서 필요한 계산을 한다.
// 
// 