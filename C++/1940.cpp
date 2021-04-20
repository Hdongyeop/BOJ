#include <iostream>
#include <algorithm>
using namespace std;
int N,M,cnt=0;
int arr[15001];

int main() {
    cin >> N >> M;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    sort(arr,arr+N);

    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            int sum = arr[i]+arr[j];
            if(sum == M) cnt++;
            else if(sum > M) break;
        }
    }

    cout << cnt;
    return 0;
}
