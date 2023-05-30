#include<bits/stdc++.h>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    while (1) {
        // 뒤에부터 0값 자리들 제거 
        while (1) {
            if (!deliveries.empty() && deliveries.back() == 0) deliveries.pop_back();
            else break;
        }
        while (1) {
            if (!pickups.empty() && pickups.back() == 0) pickups.pop_back();
            else break;
        }

        // 최대 이동 거리 구하기
        int maxDis = 0;
        maxDis = max(deliveries.size(), pickups.size());
        answer += (maxDis * 2);

        // 하차하기
        int capacity = cap;
        while (capacity > 0) {
            if (deliveries.empty()) break;
            if (deliveries.back() > capacity) {
                deliveries.back() -= capacity;
                capacity = 0;
            }
            else if (deliveries.back() == capacity) {
                deliveries.pop_back();
                capacity = 0;
            }
            else if (deliveries.back() < capacity) {
                capacity -= deliveries.back();
                deliveries.pop_back();
            }
        }

        // 상차하기
        capacity = cap;
        while (capacity > 0) {
            if (pickups.empty()) break;
            if (pickups.back() > capacity) {
                pickups.back() -= capacity;
                capacity = 0;
            }
            else if (pickups.back() == capacity) {
                pickups.pop_back();
                capacity = 0;
            }
            else if (pickups.back() < capacity) {
                capacity -= pickups.back();
                pickups.pop_back();
            }
        }

            
        if (maxDis == 0) break;
    }

    return answer;
}

int main() {
    vector<int> deliveries = { 1, 0, 2, 0, 1, 0, 2 };
    vector<int> pickups = { 0, 2, 0, 1, 0, 2, 0 };
    cout << solution(2, 7, deliveries, pickups);
	return 0;
}

// 1. 탐욕법