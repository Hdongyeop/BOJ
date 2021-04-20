#include <iostream>
#include <vector>
#include <queue>
#define INF  2e9+1
using namespace std;
int main() {
    int a,b,N,M;
    cin >> a >> b >> N >> M;

    vector<pair<int,int>> v[N+1];
    for(int i=0;i<M;i++){
        int from,to;
        cin >> from >> to;
        v[from].emplace_back(to,1);
        v[to].emplace_back(from,1);
    }

    int dist[N+1];
    fill(dist,dist+N+1,INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,a});
    dist[a] = 0;

    while(!pq.empty()){
        int pos = pq.top().second;
        pq.pop();
        for(int i=0;i<v[pos].size();i++){
            int Npos = v[pos][i].first;
            int Ncost = v[pos][i].second;

            if(dist[Npos] > dist[pos] + Ncost){
                dist[Npos] = dist[pos] + Ncost;
                pq.push({dist[Npos],Npos});
            }
        }
    }

    if(dist[b] == INF)
        cout << -1;
    else
        cout << dist[b];

    return 0;
}
