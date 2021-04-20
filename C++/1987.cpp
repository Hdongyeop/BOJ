#include <iostream>
#include <string.h>
#define MAX     20
using namespace std;

char arr[MAX][MAX];
int ALPHA[26];
int R,C,ALPHA_NUM;
int ad[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 북, 남, 서, 동
int result=0;

void DFS(int y, int x, int c){

    if(c > result) result = c;

    for(int i=0;i<4;i++){
        int Dy = y + ad[i][0];
        int Dx = x + ad[i][1];

        if(Dy < 0 || Dx < 0 || Dy >= R || Dx >= C)
            continue;
        if(ALPHA[(int)arr[Dy][Dx] - 65] != 1){
            ALPHA[(int)arr[Dy][Dx]-65] = 1;
            DFS(Dy,Dx,c+1);
            ALPHA[(int)arr[Dy][Dx]-65] = 0;
        }
    }
}

int main() {
    cin >> R >> C;
    memset(arr,0,sizeof(arr));
    memset(ALPHA, 0, sizeof(ALPHA));

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin >> arr[i][j];
        }
    }

    ALPHA[(int)arr[0][0] - 65] = 1;
    DFS(0,0,1);

    cout << result;
    return 0;
}
