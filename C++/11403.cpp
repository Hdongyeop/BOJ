#include <iostream>
#include <string.h>
#define MAX     101
using namespace std;

int matrix[MAX][MAX];
int visited[MAX];
int N;

void DFS(int a){
    for(int i=0;i<N;i++){
        if(matrix[a][i] && !visited[i]){
            visited[i]++;
            DFS(i);
        }
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int tmp;
            cin >> tmp;
            matrix[i][j] = tmp;
        }
    }

    for(int i=0;i<N;i++){
        memset(visited,0,sizeof(visited));
        /*
         * visited가 각 라인마다 생성된다.
         */
        DFS(i);

        for(int j=0;j<N;j++){
            if(visited[j])
                matrix[i][j] = 1;
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }
}
