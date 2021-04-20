#include <iostream>
#include <algorithm>
using namespace std;
int N,K;
int dp[1000001];
int W[101];
int V[101];

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++)
        cin >> W[i] >> V[i];

    //각 무게가 i 일때 최대로 되는 값을 구한다.
    // max( 현재 최대의 값, i일때 최대의값 + (j-i의 무게)의 최대값 )
    for(int i=0;i<N;i++){
        for(int j=K;j>=0;j--){
            if(W[i] <= j){
                dp[j] = max(dp[j],dp[j-W[i]] + V[i]);
            }
        }
    }

    cout << dp[K];
    return 0;
}
