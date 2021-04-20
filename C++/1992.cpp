#include <iostream>
using namespace std;
int N;
int arr[64][64];

void div(int n, int m, int len){
    int cur = arr[m][n];
    bool chk = true;
    for(int i=m; (i<m+len) && chk;i++){
        for(int j=n; (j<n+len) && chk; j++){
            if(cur != arr[i][j]) chk = false;
        }
    }
    if(chk) cout << cur;
    else {
        cout << "(";
        div(n,m,len/2);
        div(n+len/2, m, len/2);
        div(n,m+len/2,len/2);
        div(n+len/2,m+len/2,len/2);
        cout << ")";
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    div(0,0,N);
    return 0;
}
