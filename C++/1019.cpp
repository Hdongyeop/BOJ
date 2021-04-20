#include <iostream>
using namespace std;
long long arr[10] = {0};

void calc(long long n, long long digit){
    while(n>0){
        arr[n%10]+=digit;
        n /= 10;
    }
}

void solve(long long A, long long B, long long digit){
    while(A%10 != 0 && A<=B){
        calc(A,digit);
        A++;
    }

    if(A > B) return;

    while(B%10 != 9 && A<=B){
        calc(B,digit);
        B--;
    }

    long long tmp = (B/10-A/10)+1;
    for(int i=0;i<10;i++){
        arr[i] += tmp * digit;
    }

    solve(A/10,B/10,digit*10);
}

int main() {
    long long n;
    cin >> n;
    solve(1,n,1);
    for(int i=0;i<10;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
