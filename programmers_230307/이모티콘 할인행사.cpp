// 완전 탐색 유형
// 티콘 7개 * 할인 경우 4개 * 사용자 100명 = 2800가짓수

#include<bits/stdc++.h>
using namespace std;

int emoticonsDiscount[7];
int maxUser, maxValue;

// 가입자와 이익 계산
void computeResult(vector<int> emoticons, vector<vector<int>> users) {
    int predUser=0, predValue=0;
    
    // 유저 수만큼 반복문
    for (auto i : users) {
        int sum = 0;
        // 이모티콘 수만큼 반복문
        for (int j = 0; j < emoticons.size(); j++) {
            if (emoticonsDiscount[j] >= i[0]) 
                sum += (emoticons[j] / 100 * (100 - emoticonsDiscount[j]));
        }
        // 이모티콘 플러스 가입 분기점
        if (sum >= i[1]) predUser++;
        else predValue += sum;
    }

    if (predUser > maxUser) {
        maxUser = predUser;
        maxValue = predValue;
    }
    if (predUser == maxUser) maxValue = max(maxValue, predValue);
}

// 이모티콘 수만큼 재귀하면서, 할인률 조합을 꾸리는 함수
void comb(int cnt, vector<int> emoticons, vector<vector<int>> users) {
    if (cnt == 0) computeResult(emoticons, users);
    else {
        cnt--;
        for (int i = 1; i <= 4; i++) {
            emoticonsDiscount[cnt] = i * 10;
            comb(cnt, emoticons, users);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer; // 가입자수, 이익

    comb(emoticons.size(), emoticons, users);
    
    answer.push_back(maxUser);
    answer.push_back(maxValue);

    return answer;
}

int main() {
    vector<vector<int>> users = { {40, 10000} ,{25, 10000} };
    vector<int> emoticons = {7000, 9000};
    vector<int> a = solution(users, emoticons);
    cout << a[0] << ' ' << a[1];

	return 0;
}

// 1. 쿠폰과 할인 조합 만들기
// 2. 이익 계산