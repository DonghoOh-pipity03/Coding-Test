#include <bits/stdc++.h>
using namespace std;
int n, m, num[15000], input, cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n; cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        num[i] = input;
    }
    sort(num, num + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (num[i] + num[j] == m) cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}


/*
문제를 잘못 읽었다.: 고유번호를 물질의 개수로 잘못 생각했다.
배열은 접근이 1, map은 접근이 logn -> 한번 정렬하고 순차 접근할 것이므로 배열이 좋다

개선 가능 부분
1. 예외처리를 미리해서 시간을 단축시키자
ex) 고유번호 합이 초과되어, 연산이 의미없는 경우
2. 배열 정렬하는법
sort( 배열 포인터, 배열끝나는 지점(=배열포인터 + 배열의 크기))
ex) sort( num, num + n)
*/

/*
#include<bits/stdc++.h>
using namespace std;
int n, m, a[150001], cnt;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if(m > 200000) cout << 0 << "\n";
    else{
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(a[i] + a[j] == m)cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
*/