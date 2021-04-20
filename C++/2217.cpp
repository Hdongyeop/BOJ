#include <iostream>
#include <algorithm>
using namespace std;
int N,ans=0;
int arr[100001];
int main() {
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    sort(arr,arr+N);

    for(int i=0;i<N;i++){
        int tmp = arr[i] * (N-i);
        ans = max(ans,tmp);
    }

    cout << ans;
    return 0;
}
