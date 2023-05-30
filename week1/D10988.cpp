#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
string input, a, b;
int main() {
	cin >> input;
	for (int i = 0; i < floor(input.length() / 2.0f); i++) a += input[i];	// floor(): 내림함수
	for (int i = ceil(input.length() / 2.0f); i < input.length(); i++) b += input[i];	// ceil(): 올림함수
	reverse(a.begin(), a.end());
	if ( (a.compare(b)) == 0 ) cout << 1;
	else cout << 0;
	return 0;
}

/*
내가 생각한 알고리즘
1. 입력받은 문자열을 짝/홀에 따라 앞뒤를 나누어 저장한다.
2. 앞 문자를 뒤집어 for문으로 대조한다.
3. 끝까지 이상이 없으면 true를 리턴한다.

개선점 가능점
1. 나누는 과정 필요없이 뒤집은 문자열을 복사하여, ==으로 같은지 검사한다.

실수 기록
문자열을 나눈 후 새로 저장하는 과정에서 
문자열 길이보다 길게 저장을 하였다 ( <= input.length() )
이 때문에 뒤에 (int) 0이 추가로 붙어서 제대로 작동되지 않았다.
*/

/*
#include<bits/stdc++.h>
using namespace std;   
string s, temp; 
int main(){
    cin >> s; 
    temp = s; 
    reverse(temp.begin(), temp.end()); 
    if(temp == s) cout << 1 << "\n"; 
    else cout << 0 << "\n"; 
      
    return 0; 
}
*/