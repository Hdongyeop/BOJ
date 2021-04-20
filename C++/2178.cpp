#include <iostream>
#include <queue>

#define MAX     101
using namespace std;

int N,M;
int arr[MAX][MAX];
bool visited[MAX][MAX] = {false,};

struct Man{
    int x,y,time;
};

int main() {
    cin >> N >> M;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    queue<Man> q;
    Man man = {1,1,1};
    visited[1][1] = true;
    q.push(man);

    while(!q.empty()){
        Man m = q.front();
        q.pop();

        if(m.x == M && m.y == N){
            cout << m.time;
            return 0;
        }

        // (-1,0) (1,0) (0,-1) (0,1) 상 하 좌 우
        // Man이 범위 안에 있고 방문하지 않았으며 이동할 수 있는 길
        if(m.y-1 > 0 && !visited[m.y-1][m.x] && arr[m.y-1][m.x] == 1){
            Man tmp = {m.x, m.y, m.time};
            visited[m.y-1][m.x] = true;
            tmp.y--;
            tmp.time++;
            q.push(tmp);
        }

        if(m.y+1 <= MAX && !visited[m.y+1][m.x] && arr[m.y+1][m.x] == 1){
            Man tmp = {m.x, m.y, m.time};
            visited[m.y+1][m.x] = true;
            tmp.y++;
            tmp.time++;
            q.push(tmp);
        }

        if(m.x-1 > 0 && !visited[m.y][m.x-1] && arr[m.y][m.x-1] == 1){
            Man tmp = {m.x, m.y, m.time};
            visited[m.y][m.x-1] = true;
            tmp.x--;
            tmp.time++;
            q.push(tmp);
        }

        if(m.x+1 <= MAX && !visited[m.y][m.x+1] && arr[m.y][m.x+1] == 1){
            Man tmp = {m.x, m.y, m.time};
            visited[m.y][m.x+1] = true;
            tmp.x++;
            tmp.time++;
            q.push(tmp);
        }
    }
}
