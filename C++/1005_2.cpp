#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define MAX     1001
using namespace std;

int in_degree[MAX];
int time[MAX];
int min_time[MAX];
vector<int> v[MAX];
int T,N,K,X,Y,W;

void init(){
    memset(in_degree,0,sizeof(in_degree));
    memset(time,0,sizeof(time));
    memset(min_time,0,sizeof(min_time));
    for(int i=0;i<MAX;i++)
        v[i].clear();
}

void topology(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(in_degree[i] == 0) {
            q.push(i);
            min_time[i] = time[i];
        }
    }

    for(int i=1;i<=N;i++){
        int x = q.front();
        q.pop();

        for(int j=0;j<v[x].size();j++){
            int y = v[x][j];
            in_degree[y]--;

            if(min_time[y] < min_time[x] + time[y])
                min_time[y] = min_time[x] + time[y];

            if(in_degree[y] == 0)
                q.push(y);
        }
    }
}

int main() {
    cin >> T;
    while(T--){
        init();
        cin >> N >> K;

        for(int i=1;i<=N;i++)
            cin >> time[i];

        for(int i=0;i<K;i++){
            cin >> X >> Y;
            v[X].push_back(Y);
            in_degree[Y]++;
        }

        cin >> W;
        topology();

        cout << min_time[W] << '\n';
    }
    return 0;
}
