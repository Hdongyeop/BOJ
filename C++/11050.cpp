/*
 * 1. nCr은 N! / K!(N-K)! 이다
 * 2. mod연산은 나눗셈에 대해 분배법칙이 통하지 않는다.
 * 3. 따라서 나눗셈을 곱셈으로 바꾸기위해 분모부분의 역원이 필요하다.
 * 4. mod p 상황이라면 페르마의 소정리를 이용해 역원을 구할 수 있다.

 * 페르마의 소정리
 * p가 소수이고 a가 p의 배수가 아니라면 a^(p-1) = 1 (mod p) 이다.
 * a^-1 * a^(p-1) = a^-1 (mod p)
 * a^(p-2) = a^-1 (mod p)
 * 즉, a의 역원은 mod p 안에서 a^(p-2)이다.
 */
#include <iostream>
using namespace std;
#define MOD     1000000007

long long exp_rem(long long base, unsigned int exponent, int mod){
    long long ans = 1;
    while(exponent > 0){
        if(exponent%2 == 1)
            ans = (ans * base) % mod;
        exponent /= 2;
        base = (base * base) % mod;
    }
    return ans;
}

int main(){
    int n,k;
    cin >> n >> k;
    /*
     * nCk = n!(=a) / (n-k)!k!(=b) 5C2 = 5! / 3!2!
     */
    long long a = 1, b = 1;
    for(int i=1;i<=n;i++){
        a = (a*i) % MOD;
        if(n-k == i) b *= a;
        if(k == i) b*= a;
    }

    b %= MOD;
    b = exp_rem(b, MOD-2, MOD);

    cout << (a*b)%MOD;
    return 0;
}

//#include <iostream>
//#include <algorithm>
//#define P 1000000007LL
//
//using namespace std;
//long long fac[4000001],n,k,inv[4000001];
//
//// N^M = power(N,M)
//long long power(long long x, long long y){
//    long long ret = 1;
//    while(y > 0){
//        if(y % 2){
//            ret *= x;
//            ret %= P;
//        }
//        x *= x;
//        x %= P;
//        y /= 2;
//    }
//    return ret;
//}
//int main(){
//    fac[1] = 1;
//    for(int i=2;i<=4000000;i++)
//        fac[i] = (fac[i-1] * i) % P;

//    inv[4000000] = power(fac[4000000],P-2);
//
//    for(int i=4000000 - 1;i>0;i--)
//        inv[i] = (inv[i+1] * (i+1)) % P;
//
//    cin >> n >> k;
//    if(n == k || !k){
//        cout << 1;
//        return 0;
//    }
//    long long r = (fac[n] * inv[n-k]) % P;
//    r = (r*inv[k]) % P;
//    cout << r;
//    return 0;
//}