#include <iostream>
using namespace std;
int N,M,s=0,e=0,cnt=0,tmp=0;
int arr[10001];
int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++)
        cin >> arr[i];

    while(1){
        if(tmp >= M) tmp -= arr[s++];
        else if(e >= N) break;
        //tmp가 M보다 더 작은 경우에서 e가 N보다 크거나 같다면 tmp가 증가할수 없기 때문에 종료.
        else tmp += arr[e++];

        if(tmp == M) cnt++;
    }
    cout << cnt;
    return 0;
}
