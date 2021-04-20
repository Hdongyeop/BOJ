#include <iostream>
#include <algorithm>
#define ll long long
#define MAX     1000000
using namespace std;
int N;
ll arr[MAX];
ll M;
// 높이를 h로 해서 잘랐을때 나오는 나무의 길이가 원하는
// 나무의 길이보다 크거나 같으면 true 아니면 false
bool check(ll h){
    ll ch = 0;
    for(int i=0;i<N;i++){
        if(arr[i] > h)
            ch += arr[i]-h;
    }
    if(ch >= M) return true;
    else return false;
}

int main(){
    ll low = 1, high = 0;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        cin >> arr[i];
        if(arr[i] > high) high = arr[i];
    }
    ll ans = 0;
    while(low <= high){
        ll mid = (low+high)/2;

        /* 체크를 했을 때 잘린 나무의 총 길이가 원하는 것보다 크다면
          자르는 높이를 높여서 잘린 나무의 총 길이를 줄여본다. */
        if(check(mid)){
            ans = max(ans,mid);
            low = mid+1;
        } else
            high = mid-1;
    }
    cout << ans << '\n';
    return 0;
}