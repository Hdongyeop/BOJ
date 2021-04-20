#include <iostream>
#include <string.h>
#define MAX     20001
#define INF     987654321
using namespace std;

int V,E;
int firstnode;

int matrix[MAX][MAX];
int result[MAX] = {INF, };
bool select[MAX] = {false, };

int find(){
    int min_dist, min_idx;
    min_dist = INF;
    min_idx = -1;

    for(int i=1;i<=V;i++){
        if(select[i] == true) continue;
        if(result[i] < min_dist)
        {
            min_dist = result[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void update(int newnode){
    for(int i=1;i<=V;i++){
        if(select[i] == true) continue;
        if(result[i] > result[newnode] + matrix[newnode][i])
        {
            result[i] = result[newnode] + matrix[newnode][i];
        }
    }
}

void Dijkstra(){
    for(int i=1;i<=V;i++)
        result[i] = matrix[firstnode][i];

    result[firstnode] = 0;
    select[firstnode] = true;

    for(int i=0;i<V;i++){
        int newnode = find();

        select[newnode] = true;
        update(newnode);
    }
}

int main() {
    cin >> V >> E >> firstnode;

    for(int i=1;i<=V;i++){
        result[i] = INF;
        for(int j=1;j<=V;j++){
            if(i == j) matrix[i][j] = 0;
            else matrix[i][j] = INF;
        }
    }

    for(int i=0;i<E;i++){
        int a,b,c;
        cin >> a >> b >> c;
        matrix[a][b] = c;
    }

    Dijkstra();

    for(int i=1;i<=V;i++){
        if(result[i] == INF) cout << "INF" << '\n';
        else cout << result[i] << '\n';
    }

}
