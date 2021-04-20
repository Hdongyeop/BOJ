#include <iostream>
#include <algorithm>
#include <string.h>
#define MAX     100001
using namespace std;
int N,M;
int up[MAX];
int down[MAX];

int solve(int n, int start, int end){
    int left = start;
    int right = end;

    while(left <= right){
        int mid = (left+right)/2;
        if(up[mid] == n) return 1;

        if(n < up[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    memset(up,0,sizeof(up));
    memset(down,0,sizeof(down));
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> up[i];
    }
    cin >> M;
    for(int i=0;i<M;i++){
        cin >> down[i];
    }

    sort(up,up+N);

    for(int i=0;i<M;i++){
        cout << solve(down[i],0,N-1) << '\n';
    }
    return 0;
}
