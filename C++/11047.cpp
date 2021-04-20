#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int N,K,ans=0;
int cnt = 0;

void solve(int K){
    while(K != 0){
        while(K-v[cnt] >= 0){
            K -= v[cnt];
            ans++;
        }
        cnt++;
    }
}

int main() {
    cin >> N >> K;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end(),greater<>());

    solve(K);

    cout << ans;

    return 0;
}
