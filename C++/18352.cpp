#include <iostream>
#include <queue>
#include <vector>
#define INF     2e9+1
using namespace std;
int N,M,K,X;

int main() {
    cin >> N >> M >> K >> X;

    // from -> to / val = 1
    vector<pair<int,int>> v[N+1];
    for(int i=0;i<M;i++){
        int from, to;
        cin >> from >> to;
        v[from].emplace_back(to,1);
    }

    // distance is filled INF
    int dist[N+1];
    fill(dist,dist+N+1,INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0,X});
    dist[X] = 0;

    while(!pq.empty()){
        int pos = pq.top().second;

        pq.pop();

        for(int i=0;i<v[pos].size();i++){
            int Npos = v[pos][i].first;
            int Ncost = v[pos][i].second;

            if(dist[Npos] > dist[pos]+Ncost){
                dist[Npos] = dist[pos]+Ncost;
                pq.push({dist[Npos],Npos});
            }
        }
    }

    bool flag = true;
    for(int i=1;i<=N;i++){
        if(dist[i] == K){
            cout << i << '\n';
            flag = false;
        }
    }
    if(flag) cout << -1;
    return 0;
}
