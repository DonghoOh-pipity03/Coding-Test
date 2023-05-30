#include<bits/stdc++.h>
using namespace std;

long long solution(vector<int> sequence) {
	long long answer = 0;

    // 1. 펄스 값을 곱해 누적합 벡터를 만든다.
	vector<long long> v;
	long long sum = 0;
	int pulse = 1;
	for (auto i : sequence) {
		i *= pulse;
		pulse *= -1;
		sum += i;
		v.push_back(sum);
	}

    // 2. 가장 큰 누적합의 인덱스를 구한다. (여러 개일 수 있다.)
	vector<int> maxIndex;
	maxIndex.push_back( max_element(v.begin(), v.end()) - v.begin() );	
	while (1) {
		int temp;
		temp = max_element(v.begin()+maxIndex.front(), v.end()) - (v.begin() + maxIndex.front());
		if (v[temp] == v[maxIndex.front()] && temp > maxIndex.front()) maxIndex.push_back(temp);
		else break;
	}

    // 2. 가장 작은 누적합의 인덱스를 구한다. (여러 개일 수 있다.)
	vector<int> minIndex;
	minIndex.push_back(min_element(v.begin(), v.end()) - v.begin());
	while (1) {
		int temp;
		temp = min_element(v.begin() + minIndex.front(), v.end()) - (v.begin() + minIndex.front());
		if (v[temp] == v[minIndex.front()] && temp > minIndex.front()) minIndex.push_back(temp);
		else break;
	}

    // 3. 가장 큰 연속 수열의 합을 구한다.
	long long maxVal = INT_MIN;
	for (auto i : maxIndex) {
		int j = 1;
		if (i == 0) maxVal = v[i];
		else {
			while (true) {
				if (v[i - j] < 0) {
					maxVal = max(maxVal, v[i] - v[i - j]);
					break;
				}
				j++;
			}
		}
	}

    // 3. 가장 작은 연속 수열의 합을 구한다.
	long long minVal = INT_MAX;
	for (auto i : minIndex) {
		int j = 1;
		if (i == 0) minVal = v[i];
		else {
			while (true) {
				if (v[i - j] > 0) {
					minVal = min(minVal, v[i] - v[i - j]);
					break;
				}
				j++;
			}
		}
	}

    // 4. 절댓값이 가장 큰 수를 반환한다.
	answer = max(abs(maxVal), abs(minVal));

	return answer;
}

// 1. 입력 값에 따라 펄스값을 곱한 누적합 벡터를 만든다.
// 2. 누적합에서 가장 큰(작은) 수와 인덱스를 구한다. // 중복 문제 발생 가능
// 3. 가장 큰(작은) 수의 앞을 탐색하면서 반대 부호가 되는 곳을 찾아 a - b 해준다.
// 4. 구하게 된 max, min의 절댓값이 큰 수를 반환한다.

int main() {
	vector<int> sequence = { 2, 3, -6, 1, 3, -1, 2, 4 };
	cout << solution(sequence);
	return 0;
}

// 배열 - 가장 큰 수 인덱스 찾기
// iterator