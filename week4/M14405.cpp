#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> s;

    bool flag = true;
    while(1){
        if(s.size() == 0) break;
        if(s.substr(0,2) == "pi") s.erase(0,2);
        else if(s.substr(0,2) == "ka") s.erase(0,2);
        else if(s.substr(0,3) == "chu")s.erase(0,3);
        else{
            flag = false;
            break;
        }
    }

    if(flag) cout << "YES";
    else cout << "NO";
    return 0;
}