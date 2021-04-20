#include <iostream>
#include <string.h>
#include <queue>
#define MAX     1000
using namespace std;

int N,M,ripe=0;
int DAY = 0;
int arr[MAX][MAX];
int visited[MAX][MAX];
int ad[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int,int>> q;
bool DO = false;

void BFS(){
    while(!q.empty()){
        int CN=0;
        DO = false;
        for(int i=0;i<ripe;i++) {
            pair<int, int> p = q.front();
            q.pop();
            visited[p.first][p.second] = 1;

            for (int i = 0; i < 4; i++) {
                int Dy = p.first + ad[i][0];
                int Dx = p.second + ad[i][1];
                if (Dy < 0 || Dx < 0 || Dy >= N || Dx >= M)
                    continue;
                if (arr[Dy][Dx] == 0 && !visited[Dy][Dx]) {
                    DO = true;
                    arr[Dy][Dx] = 1;
                    visited[Dy][Dx] = 1;
                    q.push(make_pair(Dy, Dx));
                    CN++;
                }
            }
        }
        ripe = CN;
        if(DO) DAY++;
    }
}

int main() {
    cin >> M >> N;
    memset(arr,0,sizeof(arr));

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                // 익은 토마토의 좌표와 개수
                q.push(make_pair(i,j));
                ripe++;
            }
        }
    }

    memset(visited,0,sizeof(visited));

    BFS();

    // 토마토가 모두 익지 못하는 상황 ( 0이 존재하는 상황 )
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j] == 0){
                cout << -1;
                return 0;
            }
        }
    }

    cout << DAY;
    return 0;
}
