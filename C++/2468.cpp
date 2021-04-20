#include <iostream>
#include <string.h>
#define MAX     101
using namespace std;

int N;
int area[MAX][MAX];
int arr[MAX][MAX] = {0};
int visited[MAX][MAX] = {0};
int ad[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void DFS(int y, int x){
    for(int i=0;i<4;i++){
        int Dy = y + ad[i][0];
        int Dx = x + ad[i][1];
        if(Dy < 1 || Dx < 1 || Dy > N || Dx > N)
            continue;
        if(!arr[Dy][Dx] && !visited[Dy][Dx]){
            visited[Dy][Dx] = 1;
            DFS(Dy,Dx);
        }
    }
}

int main() {
    int H=0;
    int safe_area = 0;

    cin >> N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> area[i][j];
            // 최대높이(H) 구하기
            if(area[i][j] > H) H = area[i][j];
        }
    }

    for(int k=0; k <= H; k++){
        int tmp = 0;

        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        // 잠긴지역 1, 안 잠긴지역 0
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(k >= area[i][j]) arr[i][j] = 1;
            }
        }

        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(!arr[i][j] && !visited[i][j]){
                    tmp++;
                    visited[i][j]++;
                    DFS(i,j);
                }
            }
        }
        // safe_area의 최대 개수 측정
        if(tmp > safe_area) safe_area = tmp;
    }

    cout << safe_area;
    return 0;
}
