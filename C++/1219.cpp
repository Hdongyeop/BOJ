/*
4 1 3 4
0 1 0
0 1 100000
1 2 3
2 3 4
2 2 2 2

-1

3 0 2 4
0 1 9999
1 2 9999
1 1 9999
0 2 0
10000 10000 10000

Gee
 /--------------------------------- https://polohee81.tistory.com/33 --------------------------/
4 0 3 4
0 1 10
0 3 10
1 2 10
2 1 10
0 100 100 20

10

4 0 3 4
0 1 10
1 2 10
2 1 10
2 3 10
0 100 100 20

Gee
 /--------------------------------- https://polohee81.tistory.com/33 --------------------------/
 */
#include <iostream>
#include <vector>
#define ll long long
#define INF     -9e15-1
using namespace std;

struct EDGE {
    ll start;
    ll end;
    ll val;
};

int N,S,E,M;
vector<EDGE> v;
vector<int> prize;

int main() {
    cin >> N >> S >> E >> M;

    for(int i=0;i<M;i++){
        EDGE e;
        cin >> e.start >> e.end >> e.val;
        e.val = -e.val;
        v.push_back(e);
    }
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        prize.push_back(a);
    }

    ll dist[N];
    fill(dist,dist+N,INF);
    dist[S] = prize[S];

    for(int i=0;i<N-1;i++){
        for(int j=0;j<v.size();j++){
            ll start = v[j].start;
            ll end = v[j].end;
            ll val = v[j].val;

            if(dist[start] == INF) continue;
            if(dist[end] < dist[start] + val + prize[end])
                dist[end] = dist[start] + val + prize[end];
        }
    }

    if(dist[E] == INF){
        cout << "gg";
        return 0;
    }

    string str;

    for(int i=0;i<v.size();i++){
        ll start = v[i].start;
        ll end = v[i].end;
        ll val = v[i].val;

        if(dist[start] == INF) continue;
        // 양의 사이클이 발생했을 때 그 노드를 시작점으로 E에 도달할 수 있는지
        if(dist[end] < dist[start] + val + prize[end]){
            ll tmpdist[N];
            fill(tmpdist,tmpdist+N,INF);
            tmpdist[start] = prize[start];
            for(int k=0;k<N-1;k++){
                for(auto & j : v){
                    ll start2 = j.start;
                    ll end2 = j.end;
                    ll val2 = j.val;

                    if(tmpdist[start2] == INF) continue;
                    if(tmpdist[end2] < tmpdist[start2] + val2 + prize[end2])
                        tmpdist[end2] = tmpdist[start2] + val2 + prize[end2];
                }
            }
            if(tmpdist[E] != INF){
                cout << "Gee";
                return 0;
            }
        }
    }
    cout << dist[E];
    return 0;
}
