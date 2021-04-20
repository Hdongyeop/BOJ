#include <iostream>
using namespace std;
const int mod = 1000000;
const int pisano_period = mod/10*15;
int fibo[pisano_period] = {0,1};
int main() {
    long long n;
    cin >> n;
    for (int i=2; i<pisano_period; i++) {
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod;
    }
    cout << fibo[n%pisano_period] << '\n';
    return 0;
}