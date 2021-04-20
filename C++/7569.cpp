#include <iostream>
#include <string.h>
#include <queue>
#define MAX     100
using namespace std;

struct Point {
    int y;
    int x;
    int h;
};

int N,M,H,ripe=0;
int DAY = 0;
int arr[MAX][MAX][MAX];
int visited[MAX][MAX][MAX];
int ad[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,1},{0,0,-1}};
queue<Point> q;
bool DO = false;

void BFS(){
    while(!q.empty()){
        int CN=0;
        DO = false;
        for(int i=0;i<ripe;i++) {
            Point p = q.front();
            q.pop();
            visited[p.y][p.x][p.h] = 1;

            for (int i = 0; i < 6; i++) {
                int Dy = p.y + ad[i][0];
                int Dx = p.x + ad[i][1];
                int Dh = p.h + ad[i][2];

                if (Dy < 0 || Dx < 0 || Dh < 0 || Dy >= N || Dx >= M || Dh >= H)
                    continue;
                if (arr[Dy][Dx][Dh] == 0 && !visited[Dy][Dx][Dh]) {
                    DO = true;
                    arr[Dy][Dx][Dh] = 1;
                    visited[Dy][Dx][Dh] = 1;
                    Point tmp; tmp.y = Dy; tmp.x = Dx; tmp.h = Dh;
                    q.push(tmp);
                    CN++;
                }
            }
        }
        ripe = CN;
        if(DO) DAY++;
    }
}

int main() {
    cin >> M >> N >> H;
    memset(arr,0,sizeof(arr));

    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                // arr[y][x][h]
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    Point p;
                    p.y = i;
                    p.x = j;
                    p.h = k;
                    q.push(p);
                    ripe++;
                }
            }
        }
    }

    memset(visited,0,sizeof(visited));

    BFS();

    // 토마토가 모두 익지 못하는 상황 ( 0이 존재하는 상황 )
    for(int k=0;k<H;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j][k] == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    cout << DAY;
    return 0;
}
