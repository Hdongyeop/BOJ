#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX     1001
#define ll long long
using namespace std;

int time[MAX];
int T,N,K,X,Y,W;
vector<int> v[MAX];
ll dp[MAX];

int main() {
    cin >> T;
    while(T--){
        memset(dp,0,sizeof(dp));
        cin >> N >> K;
        for(int i=1;i<=N;i++){
            cin >> time[i];
            dp[i] = time[i];
        }

        for(int i=0;i<K;i++){
            cin >> X >> Y;
            v[Y].push_back(X);
            dp[Y] = max(dp[Y], dp[X] + time[Y]);
        }

//        for(int i=2;i<=N;i++){
//            for(int j=0;j<v[i].size();j++){
//                dp[i] = max(dp[i], dp[v[i][j]] + time[i]);
//            }
//        }

        cin >> W;
        cout << dp[W] << '\n';
    }
    return 0;
}
