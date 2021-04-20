#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int arr[10000];
int K,N;
ll ans;
/*
 * 이진탐색 : 어떤 수를 찾을 때 시간을 획기적으로 줄여주는..
 */
void solve(ll s, ll e){
    if(s > e) return;
    ll mid = (s+e)/2, n = 0;

    for(int i=0;i<K;i++)
        n += arr[i]/mid;

    if(n >= N){
        ans = max(ans,mid);
        solve(mid+1,e);
    }

    if(n < N)
        solve(s, mid-1);
}

int main() {
    cin >> K >> N;
    for(int i=0;i<K;i++)
        cin >> arr[i];
    sort(arr,arr+K);

    solve(1,arr[K-1]);

    cout << ans;
    return 0;
}
