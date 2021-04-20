/*
 * time에 대해서 long long 으로 해야...
 */
#include <iostream>
#include <vector>
#define INF     9e15+1
#define ll long long
using namespace std;
struct BUS{
    int start;
    int end;
    ll time;
};
int N,M;
vector<BUS> v;

int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++){
        BUS b;
        cin >> b.start >> b.end >> b.time;
        v.push_back(b);
    }

    ll dist[N+1];
    fill(dist,dist+N+1,INF);
    dist[1] = 0;

    for(int i=1;i<=N-1;i++){
        for(int j=0;j<v.size();j++){
            int start = v[j].start;
            int end = v[j].end;
            ll time = v[j].time;

            if(dist[start] == INF) continue;
            if(dist[end] > dist[start] + time)
                dist[end] = dist[start] + time;
        }
    }

    for(auto &i : v){
        int start = i.start;
        int end = i.end;
        ll time = i.time;

        if(dist[start] == INF) continue;
        if(dist[end] > dist[start] + time){
            cout << -1;
            return 0;
        }

    }

    for(int i=2;i<=N;i++)
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';

    return 0;
}
