#include<bits/stdc++.h>
using namespace std;

int n, t, t1time, t2time, t1score, t2score, preTeam, preTime;
string s;

int S2S(string _s) {
	int m = atoi(_s.substr(0, 2).c_str());
	int s = atoi(_s.substr(3, 2).c_str());
	return m * 60 + s;
}
void print(int _s) {
	string m = "00" + to_string(_s / 60);
	string s = "00" + to_string(_s % 60);
	cout << m.substr(m.size()-2, 2) + ":" + s.substr(s.size() - 2, 2) << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	while (n--) {
		cin >> t >> s;
		int curTime = S2S(s);
		
		t == 1 ? t1score++ : t2score++;
		
		// 이전에 우세팀 있었고, 현재 동점이 되었으면
		if (preTeam != 0 && t1score == t2score) {
				if (preTeam == 1) t1time += curTime - preTime;
				else t2time += curTime - preTime;
				preTeam = 0;
		}
		// 동점 -> 우세
		else  if( preTeam == 0 ) preTeam= t, preTime = curTime; 
	}
	// 경기종료 및 우세팀이 있었으면
	if (t1score != t2score) {
		if (t1score > t2score) t1time += (48 * 60) - preTime;
		else t2time += (48 * 60) - preTime;
	}
	print(t1time);
	print(t2time);
	return 0;
}

// 1. string을 int로 바꾸기 -> c_str(), atoi()
// 
// int atoi (const char * str)
// C style의 문자열을 입력받아서 int (숫자) 타입으로 변환하여 리턴한다.
// 
// std::string c_str()
// string의 첫번재 문자의 주소값(포인터)를 반환합니다.
// 
// 
// 2. int를 string으로 바꾸기 -> to_string() 
//
// 
// 3. 부분적 문자역 추출하기 -> substr(시작위치, 크기)