#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll N,M,s=0,e=0,ans=2e9+1;
ll v[100001];

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> v[i];

    sort(v,v+N);

    while(s < N){
        ll sub = v[e] - v[s];
        if(sub >= M) s++;
        else e++;

        if(ans > sub && sub >= M) ans = sub;
    }

    cout << ans;
    return 0;
}
