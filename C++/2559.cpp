#include <iostream>
using namespace std;
int N,K,MAX;
int arr[100001];

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    int s=0,e=K-1;
    int sum = 0;
    for(int i=s;i<=e;i++)
        sum += arr[i];

    MAX = sum;

    while(e < N-1){
        sum -= arr[s++];
        sum += arr[++e];
        if(sum > MAX) MAX = sum;
    }

    if(sum > MAX) MAX = sum;
    cout << MAX;
    return 0;
}
