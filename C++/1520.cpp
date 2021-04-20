#include <iostream>
#define MAX     501
using namespace std;
int M,N;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int arr[MAX][MAX];
int visited[MAX][MAX];

int dfs(int y, int x){
    if(y == M-1 && x == N-1)
        return 1;
    else if(visited[y][x] == -1){
        visited[y][x] = 0;
        for(int i=0;i<4;i++){
            int ny = y + dir[i][0];
            int nx = x + dir[i][1];

            if(ny >= 0 && ny < M
               && nx >= 0 && nx < N
               && arr[y][x] > arr[ny][nx])
            {
                visited[y][x] += dfs(ny,nx);
            }
        }
    }
    return visited[y][x];
}

int main() {
    scanf("%d %d", &M, &N);
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            scanf("%d",&arr[i][j]);
            visited[i][j] = -1;
        }

    int ans = dfs(0,0);
    printf("%d",ans);
    return 0;
}
