#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int n ,m, a[50][50], visited[50][50], maxSumSize = INT_MIN;

vector<int> roomSize;   // 룸번호 -1로 저장

int dfs(int cy, int cx, int roomNum){
    int size = 1;
    visited[cy][cx] = roomNum;
    for(int i = 0; i< 4; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) continue;    // 맵 밖
        if(visited[ny][nx]) continue;    // 탐색된 길
        if( a[cy][cx] & (1<<i) ) continue; // 지나가기 불가
        else{  size += dfs(ny,nx,roomNum); }    // 탐색
    }
    return size;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }

    // 방 정보 구하기
    int roomNum=0;
    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if( visited[i][j] ) continue;
            else{
                roomNum++;
                roomSize.push_back( dfs(i, j, roomNum) );
            }
        }
    }

    // 방 크기 정렬
    vector<int> tmp = roomSize;
    sort(tmp.begin(), tmp.end(), greater<>());

    for(int i = 0; i < m;i++){
        for(int j = 0; j < n; j++){
            if( j + 1 < n && visited[i][j] != visited[i][j+1]){
                maxSumSize = max(maxSumSize, roomSize[visited[i][j]-1] + roomSize[visited[i][j+1]-1]);
            }
            if( i + 1 < m && visited[i][j] != visited[i+1][j]){
                maxSumSize = max(maxSumSize, roomSize[visited[i][j]-1] + roomSize[visited[i+1][j]-1]);
            }
        }
    }

    cout << roomNum << '\n' << tmp.front() << '\n' << maxSumSize;

    return 0;
}

// 방 2개를 합쳐서 가장 큰 경우를 구하는 방법을 잘 못 생각하고, 구현하지 못했음
// -> 무식한 방법으로 구하는 방법이 정답이였다.