#include <iostream>
#define ll long long
using namespace std;
ll arr[101];
int main() {
    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;
    arr[4] = 2;
    arr[5] = 2;

    for(int i=6;i<=100;i++){
        arr[i] = arr[i-1] + arr[i-5];
    }

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        cout << arr[x] << '\n';
    }
    return 0;
}
