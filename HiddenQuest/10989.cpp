#include<bits/stdc++.h>
using namespace std;

int a[10001];
int cnt, tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		cin >> tmp;
		a[tmp]++;
	}

	for (int i = 1; i <= 10000; i++) {
		while (a[i]) {
			a[i]--;
			cout << i << '\n';
		}
	}

	return 0;
}


// 메모리초과 - 벡터 -> 배열에 개수를 저장하는 방식으로 변경