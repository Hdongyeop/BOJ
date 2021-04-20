#include <iostream>
#define MAX     1000001
using namespace std;

int arr[MAX];

int calc(int n){
    int ret = n;
    int c = 10;
    while(n/c != 0){
        int tmp = n%c;
        n /= c;
        ret += tmp;
    }
    ret += n;
    return ret;
}

int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int m = calc(i);
        if(arr[m] == 0) arr[m] = i;
        else if(i < arr[m])
            arr[m] = i;
    }

    cout << arr[n];
    return 0;
}

