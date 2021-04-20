#include <iostream>
#include <vector>
using namespace std;
int N,D;
vector<pair<int,int>> v[10101];
int dp[10101];

int main() {
    cin >> N >> D;
    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[b].emplace_back(a,c);
    }
    dp[0]=0;
    for(int i=1;i<=D;i++){
        dp[i] = dp[i-1]+1;
        for(auto &it : v[i])
            dp[i] = min(dp[i], dp[it.first] + it.second);
    }
    cout << dp[D];
    return 0;
}
