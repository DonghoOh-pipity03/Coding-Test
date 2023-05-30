#include <bits/stdc++.h>
using namespace std;
string input, output;
int main() {
	getline(cin, input);
	for (char i : input) {
		if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z')) {
			if (i < 'A' + 13 || ('a' <= i && i < 'a' + 13)) output += i + 13;
			else output += i - 13;
		}
		else output += i;
	}
	cout << output;
	return 0;
}

/*
내가 생각한 알고리즘
1. 문자열을 입력받는다
2. foreach문으로 돌면서, 문자열이면 13글자를 밀고, 'a'+26을 넘으면 -26을 해준다.
3. 바꾼 것을 출력한다.
*/

/*
#include<bits/stdc++.h>
using namespace std;   
string s; 
int main(){
    getline(cin, s); 
    for(int i = 0; i < s.size(); i++){
        // 대문자인경우
        if(s[i] >= 65 && s[i] < 97){
            if(s[i] + 13 > 90) s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }else if(s[i] >= 97 && s[i] <= 122){
            if(s[i] + 13 > 122)s[i] = s[i] + 13 - 26; 
            else s[i] = s[i] + 13;  
        }
        cout << s[i];  
    } 
    return 0; 
}
*/