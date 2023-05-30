// 17298 - 짝짓기 - 스택
#include <bits/stdc++.h>
using namespace std;
int n, a[1000004], answer[1000004];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	memset(answer, -1, sizeof(answer));
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (s.size() && a[s.top()] < a[i]) {
			answer[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
	}
	
	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}

//
// 처음: 모르겠음
// 
// 방법1.
// (1) 입력을 받으면서, 오큰수를 결정한다.
// (2) 오큰수가 결정되지 않은 수들을 스택에 저장하고, 입력을 받으면서 결정한다.
// 스택의 자료구조를 사용하는 이유는(짝짓기 = 스택도 있지만) 자료에 내림차성이 있다
// 스택에는 인덱스를 저장한다.
//
// 방법2.
// (1) 1과는 달리 입력은 따로 처리하고, 새로운 for문에서 입력의 역순으로 처리한다.
// (2) 각 루프마다 자신보다 작은 스택.top()은 제거하고, 자신보다 큰 스택.top()이 오면, 자신을 push한다.
// 따라서, 스택에는 하강이 시작되는 수열이 저장 후보가 되며, 최종적으로는 오름차순으로 스택에 저장된다. 
//