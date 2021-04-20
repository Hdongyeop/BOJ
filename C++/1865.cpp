/*
 * https://yabmoons.tistory.com/365
 *
 * 원래는 dist의 초기값을 INF로 줘서 단절되어 있는 노드들에 대해 제외를 해야하지만
 * 이 문제의 경우에는 단절된 노드에서도 음수사이클이 발생할 경우 YES를 출력해야 하기 때문에
 * INF로 초기화 하지 않는다.
 */
#include <iostream>
#include <vector>
#define INF     2e9+1
using namespace std;
int TC;

struct EDGE{
    int start;
    int end;
    int time;
};

int main() {
    cin >> TC;
    for(int i=0;i<TC;i++){
        int N,M,W;
        vector<EDGE> v;
        cin >> N >> M >> W;
        for(int j=0;j<M;j++){
            EDGE e;
            cin >> e.start >> e.end >> e.time;
            EDGE r;
            r.start = e.end;
            r.end = e.start;
            r.time = e.time;
            v.push_back(e);
            v.push_back(r);
        }
        for(int j=0;j<W;j++){
            EDGE e;
            cin >> e.start >> e.end >> e.time;
            e.time = -e.time;
            v.push_back(e);
        }

        int dist[N+1];
        fill(dist,dist+N+1,INF);

        //bellman_ford
        dist[1] = 0;
        for(int j=1;j<=N-1;j++){
            for(int k=0;k<v.size();k++){
                int start = v[k].start;
                int end = v[k].end;
                int time = v[k].time;

                if(dist[end] > dist[start] + time)
                    dist[end] = dist[start] + time;
            }
        }

        bool flag = true;
        for(int j=0;j<v.size();j++){
            int start = v[j].start;
            int end = v[j].end;
            int time = v[j].time;

            if(dist[end] > dist[start] + time){
                cout << "YES" << '\n';
                flag = false;
                break;
            }
        }
        if(flag) cout << "NO" << '\n';
    }
}
