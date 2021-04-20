#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define MAX     25
using namespace std;

int N,SIZE=0;
int arr[MAX][MAX];
int visited[MAX][MAX];
int ad[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; //하,상,우,좌
vector<int> v;

void DFS(int y, int x){
    for(int i=0;i<4;i++){
        int Dy = y + ad[i][0];
        int Dx = x + ad[i][1];

        if(Dy < 0 || Dx < 0 || Dy >= N || Dx >= N)
            continue;
        if(arr[Dy][Dx] && !visited[Dy][Dx]){
            visited[Dy][Dx] = 1;
            SIZE++;
            DFS(Dy,Dx);
        }
    }
}

int main() {
    cin >> N;

    memset(arr,0,sizeof(arr));
    memset(visited,0,sizeof(visited));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%1d",&arr[i][j]);
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] && !visited[i][j]){
                SIZE = 1;
                visited[i][j] = 1;
                DFS(i,j);
                v.push_back(SIZE);
            }
        }
    }

    sort(v.begin(),v.end());

    int num = v.size();
    cout << num << endl;

    for(int i=0;i<num;i++){
        cout << v[i] << endl;
    }

    return 0;
}
