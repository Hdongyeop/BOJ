#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX     10001
using namespace std;
int N,M,s,e,cnt=0;

int inDegree[MAX];
vector<pair<int,int>> v[MAX];
vector<pair<int,int>> Rv[MAX]; // REVERSE vector
int weight[MAX];
bool visited[MAX];

void tpSort(){
    queue<int> q;
    for(int i=s;i<=e;i++){
        if(inDegree[i] == 0) q.push(i);
    }

    for(int i=s;i<=e;i++){
        int x = q.front();
        q.pop();
        for(int j=0;j<v[x].size();j++){
            int y = v[x][j].first;
            weight[y] = max(weight[y],weight[x] + v[x][j].second);
            if(--inDegree[y] == 0) q.push(y);
        }
    }
}
// --------------------------------- https://yabmoons.tistory.com/443 ----------------------------- //
void cntRoad(){
    queue<int> q;
    q.push(e);
    visited[e] = true;

    while(!q.empty()){
        int x = q.front();
        q.pop();

        for(int i=0;i<Rv[x].size();i++){
            int prev = Rv[x][i].first;
            int Pweight = Rv[x][i].second;
            // 여기서 보니까 weight배열에서 최대값을 넣어야함 (원래는 weight이 vector였음)
            if(weight[x] - Pweight == weight[prev]){
                cnt++;
                if(!visited[prev]){
                    visited[prev] = true;
                    q.push(prev);
                }
            }
        }
    }
}
// --------------------------------- https://yabmoons.tistory.com/443 ----------------------------- //

int main() {
    cin >> N >> M;
    memset(inDegree,0,sizeof(inDegree));
    memset(visited,false,sizeof(visited));
    memset(weight,0,sizeof(weight));
    for(int i=0;i<M;i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].emplace_back(b,c);
        Rv[b].emplace_back(a,c);
        inDegree[b]++;
    }
    cin >> s >> e;
    tpSort();
    cntRoad();
    cout << weight[e] << '\n' << cnt;
    return 0;
}
