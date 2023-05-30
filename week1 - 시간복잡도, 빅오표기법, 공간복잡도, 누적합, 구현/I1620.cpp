#include <bits/stdc++.h>
using namespace std;

int n, m;
map<string, int> mp;
string arr[100004], tmp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		mp[tmp] = i;
		arr[i] = tmp;
	}

	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (atoi(tmp.c_str()) == 0) cout << mp[tmp] << "\n";
		else cout << arr[atoi(tmp.c_str())] << "\n";
	}

	return 0;
}
	
// 1차 시도 실패
/*
#include <bits/stdc++.h>
using namespace std;

int kind, quest;

string tmp;
int main() {
	map<string, int> monster;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> kind >> quest;

	for (int i = 1; i <= kind; i++) {
		cin >> tmp;
		monster.insert({tmp, i});
	}

	for (int i = 0; i < quest; i++) {
		cin >> tmp;
		if (0 == isdigit(tmp[0])) { cout << monster.at(tmp) << endl; }
		else { cout << monster.find(tmp) -> first << endl; }
	}

	return 0;
}
*/

/*
개선점
1. 자료구조 선택을 하지 못함
2. map 사용법을 몰랐음
3. 자료구조 2개 사용할 생각을 하지 못함
4. String 타입의 데이터가 숫자인지 문자열인지 구분하기: 
atoi(변수명.c_str()) == 0 이면 문자열, 아니면 숫자
c_str(): 문자열을 문자*으로 변환한다.
5. 배열크기는 여유 4칸을 더 주자.
6. endl 보다 "\n"이 속도면에서 유리하다.
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n, m;
string s;
map<string, int> mp;
map<int, string> mp2;
string a[100004];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		mp[s] = i + 1;
		mp2[i + 1] = s;
		a[i + 1] = s;
	}
	for(int i = 0; i < m; i++){
		cin >> s;
		if(atoi(s.c_str()) == 0){
			cout << mp[s] << "\n";
		}else{
			cout << a[atoi(s.c_str())] << "\n";
			//cout << mp2[atoi(s.c_str())] << "\n";
		}
	}
}
*/