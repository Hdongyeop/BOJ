#include <iostream>
using namespace std;
//int LCM,GCD=1,K=2,N,M;
int N,M,GCD,LCM;

void sort(int a, int b){
    if(a < b){
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
}

void getGCD(int a, int b){
    int k=a%b;
    if(k==0){
        GCD = b;
        return;
    }
    getGCD(b,k);
}

int main() {
//    cin >> N >> M;
//
//    while(true){
//        if(K>N || K>M)
//            break;
//        if(N%K == 0 && M%K == 0){
//            N /= K;
//            M /= K;
//            GCD *= K;
//            K = 2;
//        }
//        K++;
//    }
//    LCM = GCD * N * M;
//
//    cout << GCD << '\n' << LCM;
//
//    return 0;

    cin >> N >> M;
    sort(N,M); // N > M

    getGCD(N,M);
    LCM = N * M / GCD;

    cout << GCD << '\n' << LCM;

    return 0;
}
