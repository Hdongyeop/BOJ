#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int N, arr[1001][1001], visited[3][1001][1001];

int next(int x){
    return x==2 ? 0 : x+1;
}

int solve(int y, int x, int milk){ // milk : 다음에 먹어야되는 우유
    if(y == N || x == N) return 0;
    int& ret = visited[milk][y][x];

    if(ret == -1){
        if(arr[y][x] == milk)
            ret = max({
                     //solve(y+1,x,milk),
                     //solve(y,x+1,milk),
                     1+solve(y+1,x,next(milk)),
                     1+solve(y,x+1,next(milk))
                    });
        else ret = max(solve(y+1,x,milk),solve(y,x+1,milk));
    }

    return ret;
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j];

    memset(visited,-1,sizeof(visited));
    cout << solve(0,0,0);
    return 0;
}