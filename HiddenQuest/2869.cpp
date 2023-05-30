#include<bits/stdc++.h>
using namespace std;

int a, b, v;
int answer;

int main() {
	
	cin >> a >> b >> v;

	cout << 1 + (int)ceil((double)(v - a) / (double)(a - b));

	return 0;
}

// int 형을 나누어서 소수점을 구할 때
// int 형 범위