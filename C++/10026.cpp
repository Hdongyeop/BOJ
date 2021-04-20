#include <iostream>
#include <string.h>
#define MAX     101
using namespace std;

int N,normal_Area=0,bilnd_Area=0;
char color;
char matrix[MAX][MAX];
int bearing[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool visited[MAX][MAX];
bool first = true;

void DFS(int y, int x){
    color = matrix[y][x];
    visited[y][x] = true;

    for(int i=0;i<4;i++) {
        int new_y = y + bearing[i][0];
        int new_x = x + bearing[i][1];

        if(new_y > 0 && new_y <= N && new_x > 0 && new_x <= N
        && !visited[new_y][new_x]
        && matrix[new_y][new_x] == color)
        {
            DFS(new_y,new_x);
        }
    }
}

int main() {
    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            char a;
            cin >> a;
            matrix[i][j] = a;
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visited[i][j]){
                DFS(i,j);
                normal_Area++;
            }
        }
    }

    memset(visited,0,sizeof(visited));

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(matrix[i][j] == 'R')
                matrix[i][j] = 'G';
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(!visited[i][j]){
                DFS(i,j);
                bilnd_Area++;
            }
        }
    }

    cout << normal_Area << " " << bilnd_Area << '\n';

    return 0;
}
