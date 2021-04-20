#include <iostream>
using namespace std;
#define MAX     51

int N,M,x,y,result,dir;
int arr[MAX][MAX];

int main(){
    cin >> N >> M;
    cin >> x >> y >> dir;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }

    while(1){
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        if(arr[x][y] == 0){
            arr[x][y] = 2;
            result++;
        }

        int check = 0;

        for(int i=0;i<4;i++){
            dir = dir - 1;
            if(dir<0)
                dir = 3;
            int tmp_x = x + dx[dir];
            int tmp_y = y + dy[dir];

            if(arr[tmp_x][tmp_y] == 0){
                x = tmp_x;
                y = tmp_y;
                check = 1;
                break;
            }
        }

        if(check == 1)
            continue;

        int tmp_dir = dir - 2;
        if(tmp_dir == -2)
            tmp_dir = 2;
        if(tmp_dir == -1)
            tmp_dir = 3;

        x = x + dx[tmp_dir];
        y = y + dy[tmp_dir];

        if(arr[x][y] == 1)
            break;
    }

    cout << result;

    return 0;
}