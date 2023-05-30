#include<bits/stdc++.h>
using namespace std;
int n,m, k, x, y, visited[1004];
vector<int> v[1004];

void dfs(int cur){
    visited[cur] = 1;
    for(auto i : v[cur]){
        if(visited[i]) continue;
        else dfs(i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>> n;

    while(n--){
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < 1004; i++) v[i].clear();
        int cnt = 0, edge = 0;
        cin >> m;   
        cin >>k;
        edge = k;
        while(k--){
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        for(int i = 1; i <= m; i++){
            if(visited[i]) continue;
            else{
                cnt++;
                dfs(i);
            }
        }
        if(cnt != 1 || edge != m-1) cout << "graph\n";
        else cout << "tree\n";
    }


    return 0;
}

/*
    그래프
    (1) 노드간 2개 이상의 경로 가능
    (2) 부모-자식 개념X
    (3) 순환. 비순환 구조 가짐
    (4) 방향성, 비방향성 가짐

    트리
    (1) 그래프의 한 종류
    (2) 방향성이 있으며, 비순환 구조
    (3) 부모 자식 개념을 가짐
    (4) E = V - 1
*/

// 벡터 청소방법
//  for(int i = 0; i < 1004; i++) v[i].clear();

// memset으로 배열 청소방법
// 첫번째 인자는 배열포인터로 그냥 배열이름을 입력
