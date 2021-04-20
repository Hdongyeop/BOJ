#include <iostream>
#define MAX     501
using namespace std;
int N,M,result=0;
int arr[MAX][MAX];
bool check[MAX][MAX];

int dir[4][2] = {{0,-1},{0,1},{1,0},{-1,0}}; // 왼, 오, 아래, 위
/*
 * ㅜ, ㅏ, ㅗ, ㅓ ( 3*3 블록 왼쪽위 (0,0) 기준 )
 */
int ex[4][4] = {{0,1,2,1},{0,0,0,1},{0,1,2,1},{0,1,1,1}};
int ey[4][4] = {{0,0,0,1},{0,1,2,1},{0,0,0,-1},{0,-1,0,1}};

int max(int a, int b){
    return a > b ? a : b;
}

void DFS(int y, int x, int sum, int count){
    if(count >= 4){
        result = max(result, sum);
        return;
    }

    for(int i=0;i<4;i++){
        int ny = y + dir[i][0];
        int nx = x + dir[i][1];

        if(nx < 1 || nx > M || ny < 1 || ny > N) continue;

        if(!check[ny][nx]){
            check[ny][nx] = true;
            DFS(ny,nx,sum+arr[ny][nx],count+1);
            check[ny][nx] = false;
        }
    }
}

void check_e(int y, int x){
    for(int i=0;i<4;i++){
        bool isOut = false;
        int sum = 0;
        for(int j=0;j<4;j++){
            int ny = y + ey[i][j];
            int nx = x + ex[i][j];

            if(nx < 1 || nx > M || ny < 1 || ny > N) {
                isOut = true;
                break;
            } else {
                sum += arr[ny][nx];
            }
        }
        if(!isOut){
            result = max(result, sum);
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            check[i][j] = true;
            DFS(i,j,arr[i][j],1);
            check[i][j] = false;
            check_e(i,j);
        }
    }

    cout << result;

    return 0;
}