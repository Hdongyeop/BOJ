#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[1000001];
int dp[1000001][2];
int N;

int solve(int p, int h, bool check){
    int &ret = dp[h][check];

    if(ret != -1)
        return ret;

    ret = 0;

    for(int i=0;i<v[h].size();i++){
        int next = v[h][i];
        if(next == p)
            continue;

        if(check)
            ret += min(solve(h,next,0),solve(h,next,1)+1);
        else
            ret += solve(h,next,1)+1;
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=0;i<N-1;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));

    cout << min(solve(-1,1,0), solve(-1,1,1)+1);

    return 0;
}
