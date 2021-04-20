#include <iostream>
#include <queue>
using namespace std;

int N,M,V;
int matrix[1001][1001]={0};
int visit[1001]={0};

void dfs(int v){
    cout << v << " ";
    visit[v] = 1;
    for(int i=1;i<=N;i++){
        if(visit[i] == 0 && matrix[v][i] == 1) // 방문한 적이 없고, 정점 v와 연결되어 있다
            dfs(i);
    }
}

void bfs(int v){
    queue<int> q;
    q.push(v);
    visit[v] = 2;
    while(!q.empty()){
        v = q.front();
        cout << q.front() << " ";
        q.pop();
        for(int i=1;i<=N;i++){
            if(visit[i] != 2 && matrix[v][i] == 1) // bfs로 방문한적이 없고, 정점 v와 연결되어 있다.
            {
                q.push(i);
                visit[i] = 2;
            }
        }
    }
}

int main(){
    int x,y;
    cin >> N >> M >> V; // N : 정점의 개수, M : 간선의 개수, V : 시작할 정점
    for(int i=0;i<M;i++){
        cin >> x >> y;
        matrix[y][x] = matrix[x][y] = 1; // 인접행렬 생성 (양방향으로 연결이 가능하다고 함)
    }
    dfs(V);
    cout << endl;
    bfs(V);
    return 0;
}