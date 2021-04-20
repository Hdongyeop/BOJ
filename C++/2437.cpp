#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int main() {
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> arr[i];

    sort(arr,arr+N);
    if(arr[0] != 1) { cout << 1; return 0; }

    int tmp = 0;
    for(int i=0;i<N-1;i++){
        tmp += arr[i];
        if(tmp+2 <= arr[i+1]) break;
        else if(i == N-2) tmp += arr[i+1]; // 1 1 2 3 6 끝까지 다돌아야 되는 경우
    }

    cout << tmp+1;
    return 0;
}
