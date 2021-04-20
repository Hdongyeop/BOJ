#include <iostream>
#include <algorithm>
#define INF     987654321
using namespace std;
int arr[100001];
int N,S,l=0,r=0,sum=0,min_len=INF;
int main() {
    cin >> N >> S;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    while(1){
        if(sum >= S) sum -= arr[l++];
        else if(r >= N) break;
        else sum += arr[r++];

        if(sum >= S) min_len = min(min_len, r-l);
        // S 가 아니라 S이상
    }

    if(min_len == INF) cout << 0;
    else cout << min_len;

    return 0;
}
