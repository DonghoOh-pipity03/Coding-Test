#include<bits/stdc++.h>
using namespace std;

int n, cnt;
long long input, answer;
stack<pair<long long, int>> stk;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for(int i=0; i < n; i++){
        cin >> input;
        cnt = 0;
        while(1){
            if(stk.size() == 0) break;
            else if( stk.top().first < input){
                stk.pop();
                answer++;
            }
            else if(stk.top().first > input){
                cnt++;
                answer++;
                break;
            }
            else{
                cnt += (stk.top().second + 1);
                answer += cnt;
                break;
            }
        }
        stk.push({input, cnt});
    }

    cout << answer;
    return 0;
}
