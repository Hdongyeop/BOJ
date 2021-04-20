#include <iostream>
#include <string.h>
using namespace std;

int T,M,N,K;
int arr[50][50] = {0};
int visited[50][50] = {0};
int ad[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 하, 상, 우, 좌

void DFS(int y, int x){ //visited에 마킹만 해준다
    for(int i=0;i<4;i++){
        int Dy = y + ad[i][0];
        int Dx = x + ad[i][1];
        if(Dy<0 || Dx<0 || Dy>=N || Dx>=M)      // Dy의 최대는 50(49+1) >= N의 최대는 50
            continue;
        if(arr[Dy][Dx] && !visited[Dy][Dx]){
            visited[Dy][Dx] = 1;
            DFS(Dy,Dx);
        }
    }
}

int main(){
    int x=0,y=0;
    cin >> T;

    for(int tcase=0;tcase<T;tcase++){
        int A = 0;
        cin >> M >> N >> K;

        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        for(int i=0;i<K;i++){
            cin >> x >> y;
            arr[y][x] = 1;
        }

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] && !visited[i][j]) {
                    A++;
                    visited[i][j]++;
                    DFS(i,j);
                }
            }
        }
        cout << A << endl;
    }
    return 0;
}