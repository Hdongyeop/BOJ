/*
 * Ref : https://mygumi.tistory.com/291
 */
#include <iostream>
#include <string>
#define MOD    1000000
using namespace std;
int dp[5001][3];
void solve() {
    // dp[N][L] - L자리 수면서 N번째 수까지의 가능한 배열 갯수 L => 일의 자리, 십의 자리
    // 카드로 표현할 수 있는 수는 일의 자리와 십의 자리 밖에 존재하지 않음.
    string array;
    cin >> array;
    int len = array.size();
    int prev = (array[0] - '0') * 10;
    if(prev == 0){
        cout << 0 << '\n';
        return;
    }
    dp[1][1] = 1;

    for (int i = 2; i <= len; i++) {
        int v = array[i - 1] - '0';
        if (v == 0) {
            if (prev + v <= 26) {
                dp[i][2] = dp[i - 1][1] % MOD;
            }
            continue;
        }

        if (prev + v <= 26) {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][1]) % MOD; //일의 자리로 쓸꺼면 그냥 갖다 붙이기만 해도 된다.
            dp[i][2] = dp[i - 1][1] % MOD; //십의 자리로 쓸꺼면 앞의 수가 일의자리로 써진 경우여야 한다.
        } else {
            // 26보다 큰 수라면 십의 자리가 될 수 없다. = 일의 자리로 그냥 써야한다.
            dp[i][1] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
        }
        prev = v * 10;
    }
    cout << (dp[len][1] + dp[len][2]) % MOD;
}

int main() {
    solve();
    return 0;
}
