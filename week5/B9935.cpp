#include<bits/stdc++.h>
using namespace std;

string s, token, tmp;
int pos, tokenLength;
stack<char> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> s >> token;
    tokenLength = token.length();

    for(auto i : s){
        stk.push(i);
        if(stk.size() >= tokenLength && i == token[tokenLength-1]){
            tmp = "";
            for(int j = 0; j < tokenLength; j++){
                tmp += stk.top();
                stk.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if( tmp != token ){
                reverse(tmp.begin(), tmp.end());
                for(int j = 0; j < tokenLength; j++){
                    stk.push(tmp[j]);
                }
            }
        }
    }

    if(stk.size()==0) cout << "FRULA";
    else{
        tmp="";
        for(int i =0; i< stk.size(); i++){
            tmp += stk.top();
            stk.pop();
        }
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
    }

    return 0;
}