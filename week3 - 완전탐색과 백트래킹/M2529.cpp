// 2529 - 깊이탐색
// 1회차 - 성공

#include<bits/stdc++.h>
using namespace std;

bool flag = false;
int k, number[10];
char s[10];
string answer;

// 왼쪽부터 큰수를 넣는다.
// 막히면 리턴하고, 재귀함수 특성을 활용하여 복귀시 다음 경우수를 시도한다.
// 현재 인덱스를 받아온다.
void GetMax(int curIndex) {
	if (flag) return;	// 답이 완성되면 복귀한다.
	if (answer.length() == k + 1) {	// 답이 완성되면 복귀한다.
		cout << answer << '\n';
		flag = true;
		return;
	}
	for (int i = 9; i >= 0; i--) {
		if (number[i]) continue;	// 사용되었으면, 넘어간다.
		else if ((s[(curIndex-1)] == '>') && (int(answer[curIndex-1]-'0') < i)) continue; // 이전 수와 조건이 맞지않으면 넘어간다.
		else if ((s[(curIndex-1)] == '<') && (int(answer[curIndex-1]-'0') > i)) continue; // 이전 수와 조건이 맞지않으면 넘어간다.
		else {						// 사용가능하면 넣어본다.
			number[i] = 1;
			answer = answer + char(i+'0');
			GetMax(curIndex+1);
			answer.pop_back();
			number[i] = 0;
			if (flag) return;
		}
	}
}

void GetMin(int curIndex) {
	if (flag) return;	// 답이 완성되면 복귀한다.
	if (answer.length() == k + 1) {	// 답이 완성되면 복귀한다.
		cout << answer << '\n';
		flag = true;
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (number[i]) continue;	// 사용되었으면, 넘어간다.
		else if ((s[(curIndex-1)] == '>') && (int(answer[curIndex - 1] - '0') < i)) continue; // 이전 수와 조건이 맞지않으면 넘어간다.
		else if ((s[(curIndex-1)] == '<') && (int(answer[curIndex - 1] - '0') > i)) continue; // 이전 수와 조건이 맞지않으면 넘어간다.
		else {						// 사용가능하면 넣어본다.
			number[i] = 1;
			answer = answer + char(i + '0');
			GetMin(curIndex + 1);
			answer.pop_back();
			number[i] = 0;
			if (flag) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++) { cin >> s[i]; }

	// 가장 큰 수
	flag = false;
	for (int i = 9; i >= 0; i--) {
		number[i] = 1;
		answer = answer + char(i+'0');
		GetMax(1);
		answer.pop_back();
		number[i] = 0;
		if (flag) break;
	}


	// 가장 낮은 수
	flag = false;
	memset(&number[0], 0,sizeof(number));
	answer = "";
	for (int i = 0; i <= 9; i++) {
		number[i] = 1;
		answer = answer + char(i + '0');
		GetMin(1);
		answer.pop_back();
		number[i] = 0;
		if (flag) break;
	}
	return 0;
}

// 한 자리 수 int를 char로 변환하는 방법
// char(int(5) + '0')
// 
// 아스키코드에서 최소숫자의 아스키코드 수 만큼 증가시켜, 숫자로 변환

// 1. cin 다음에 getline(cin, s)를 사용하면, getline에 정상적으로 입력되지 않는다.
// 이를 해결하기 위해서는 cin 사용 후, cin.ignore()로 버퍼를 비워주어야한다.

// 2. int char 간의 변환을 간과함
// "형변환" 할 때는 주의하기!

// 3. 문제의 입력 환경을 정확히 파악하지 못해, 디버그에 시간소비

// 4. 함수를 복사하면서,이름을 바꾸지 않았음