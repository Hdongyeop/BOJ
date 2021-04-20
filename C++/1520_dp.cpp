#include <iostream>
#include <cstring>
#define MAX     501
using namespace std;
int M,N;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int arr[MAX][MAX];
int dp[MAX][MAX];

int main() {
    cin >> M >> N;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++)
            cin >> arr[i][j];
    memset(dp,-1,sizeof(dp));
    dp[0][0] = 0;

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<4;k++){
                int ny = i + dir[k][0];
                int nx = j + dir[k][1];

                if(ny >=0 && ny < M
                && nx >=0 && nx < N
                && arr[i][j] > arr[ny][nx])
                {
                    dp[ny][nx] = arr[i][j] + 1;
                }
            }
        }
    }

    cout << dp[M-1][N-1];
    return 0;
}
