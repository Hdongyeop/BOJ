#include <iostream>
#include <string.h>
using namespace std;

bool prime[1001];

void eratos(){
    prime[1] = false;
    for(int i=2;i*i<=1000;i++){
        if(prime[i]){
            for(int j=i*2;j<=1000; j+=i){
                prime[j] = false;
            }
        }
    }
}

int main() {
    memset(prime, true, sizeof(prime));
    int count =0 ;
    int N,M;
    cin >> N;

    eratos();

    for(int i=0;i<N;i++){
        cin >> M;
        if(prime[M])
            count++;
    }

    cout << count << '\n';

    return 0;
}
