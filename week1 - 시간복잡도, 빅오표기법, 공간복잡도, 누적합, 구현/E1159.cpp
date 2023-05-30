#include <bits/stdc++.h>
using namespace std;
int nameCount, abc[26];
string temp;
bool resign;
int main() {
	cin >> nameCount;
	for (int i = 0; i < nameCount; i++) {
		cin >> temp;
		abc[temp[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (abc[i] >= 5) {
			cout << (char)(i + 'a');
			resign = true;
		}
	}
	if (!resign) cout << "PREDAJA";
	return 0;
}

/*
내가 생각한 알고리즘
1. 이름 갯수를 받는다
2. 갯수만큼 이름을 받아 첫 글자별로 알파벳 배열의 개수를 증가시킨다.
3. for문으로 5개 이상의 알파벳을 출력한다.
4. 출력이 없으면 특정글자를 출력한다.

*/

/*
#include<bits/stdc++.h>
using namespace std; 
int n, cnt[26]; 
string s, ret; 
int main(){
    cin >> n; 
    for(int i = 0; i < n; i++){
        cin >> s; 
        cnt[s[0] - 'a']++;
    }
    for(int i = 0; i < 26; i++)if(cnt[i] >= 5) ret+=  i + 'a'; 
    if(ret.size()) cout << ret << "\n"; 
    else cout << "PREDAJA" << "\n";
}
*/