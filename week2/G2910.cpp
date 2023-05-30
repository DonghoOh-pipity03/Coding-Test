// 2910 - 커스텀 오퍼레이터 
// 정렬 기준: 카운팅, 먼저 나온 순서 
#include<bits/stdc++.h>
using namespace std;

int n, c, a[1001];
vector< pair<int, int>> v;	// 숫자, 개수
map<int, int> m, m_first;	// m-숫자, 갯수 // m_first-숫자, 순서

// 입력 m
// true 반환시 왼쪽 입력변수가 큰 것
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return m_first[a.first] < m_first[b.first];
	}
	return a.second > b.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
		if (m_first[a[i]] == 0) m_first[a[i]] = i + 1;
	}
	// 벡터 삽입
	for (auto i : m) {
		v.push_back({i.first, i.second});
	}
	// 정렬
	sort(v.begin(), v.end(), cmp);
	// 출력
	for (auto i : v) {
		for (int j = 0; j < i.second; j++) {
			cout << i.first << " ";;
		}
	}

}


// 1. map
// 키와 쌍으로 이루어진 트리
// 레드블랙트리로 구성
// 자동으로 오름차순 정렬
// 삽입1: m.insert( {ㅁㅁ,ㅁㅁ} )
// 삽입2: m[i] = value;
// 접근: m.first, m.second
//
//
// 2. 정렬 커스텀 (커스텀 오퍼레이션)
// sort(m.begin(), m.end(), cmp)
// 
// bool cmp(비교 매개변수 2개){
//	true 반환시 -> 첫번째 매개변수가 먼저 저장
//	false 반환시 -> 두번째 매개변수가 먼저 저장
// }
// 
//
// 3. 알고리즘
// (1) 입력 그대로 저장하는 배열
// (2) 숫자와 갯수를 저장하는 map
// (3) 숫자와 입력 순서를 저장하는 map
// (4) 출력할 데이터를 저장하는 vector
//
//  맵: 일반적 상황
//	벡터: 커스텀 정렬