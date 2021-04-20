#include <iostream>
#include <string.h>
#define MAX     1000001
using namespace std;
int M,N;
bool prime[MAX];

void eratos(){
    prime[1] = false;
    for(int p=2;p*p<MAX;p++){
        if(prime[p]){
            for(int k=p*2;k<MAX;k+=p){
                prime[k] = false;
            }
        }
    }
}

int main() {
    cin >> M >> N;
    memset(prime,true,sizeof(prime));
    eratos();
    for(int i=M;i<=N;i++){
        if(prime[i])
            cout << i << '\n';
    }

    return 0;
}
