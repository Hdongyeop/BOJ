#include <iostream>
#include <string.h>
using namespace std;
int N,M,K,cy,cx;
int dp[16][16];
int main() {
    memset(dp,0,sizeof(dp));
    cin >> N >> M >> K;

    if(K==0){ cy = N; cx = M;}
    else {
        cy = (K % M == 0) ? K / M : K / M + 1;
        cx = (K % M == 0) ? M : K%M;
    }

    dp[1][1] = 1;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(i == 1 && j == 1) continue;
            if((i > cy && j < cx) || (i < cy && j > cx)) continue;
            else
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    cout << dp[N][M];
    return 0;
}
