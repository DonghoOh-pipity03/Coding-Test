#include <bits/stdc++.h>
using namespace std;

int main() {
	string input;
	int output[26] = {0,};

	cin >> input;

	for (char i : input) {
		output[(int)i - 97]++;
	}

	for (int i : output) {
		cout << i << " ";
	}
	
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;  
string str; 
int cnt[26];    // 전역변수로 선언하면 0으로 초기화, 지역변수로 선언하면 쓰레기값으로 초기화
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> str; 
    for(char a : str){
    	cnt[a - 'a']++;
	}
	for(int i = 0; i < 26; i++) cout << cnt[i] << " ";
	 
	return 0; 
}

*/