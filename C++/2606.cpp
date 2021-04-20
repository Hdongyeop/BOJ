#include <iostream>
#include <string.h>
#define MAX     101
using namespace std;

int matrix[MAX][MAX];
int visited[MAX];
int N,K,zombie=-1;

void DFS(int x){
    for(int i=1;i<=N;i++){
        if(matrix[x][i] == 1 && !visited[i]){
            visited[i] = 1;
            zombie++;
            DFS(i);
        }
    }
}

int main() {
    cin >> N;
    cin >> K;

    memset(matrix,0,sizeof(matrix));
    memset(visited,0,sizeof(visited));

    // 인접행렬 생성
    for(int i=0;i<K;i++){
        int x,y;
        cin >> x >> y;
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }

    DFS(1);

    if(zombie == -1){ cout << 0;}
    else { cout << zombie; }

    return 0;
}
