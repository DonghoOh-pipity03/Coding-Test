// 9996 - 
// split 구현, reverse 복습

#include<bits/stdc++.h>
using namespace std;

int n, length;
string ptn, input;
vector<string> word;
bool result;

vector<string> split(string input, string delimeter) {
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ( (pos = input.find(delimeter)) != string::npos  ) {
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimeter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> ptn;
	word = split(ptn, "*");
	reverse(word[1].begin(), word[1].end());
	length = ptn.length() - 1;

	while (n--) {
		result = true;
		cin >> input;
		//글자수 체크
		if (input.length() < length) {
			cout << "NE" << endl;
			continue;
		}
		//앞 체크
		for (int i = 0; i < word[0].length(); i++) {
			if (input[i] != word[0][i]) {
				result = false;
				break;
			}
		}
		if (result == false) {
			cout << "NE" << endl;
			continue;
		}
		//뒤 체크
		reverse(input.begin(), input.end());
		for (int i = 0; i < word[1].length(); i++) {
			if (input[i] != word[1][i]) {
				result = false;
				break;
			}
		}
		if (result == false) {
			cout << "NE" << endl;
			continue;
		}
		cout << "DA" << endl;
	}
}