#include <iostream>
#include <vector>
#include <queue>
#define MAX     501
using namespace std;

int in_degree[MAX];
int time[MAX];
int min_time[MAX];
vector<int> v[MAX];
int N;

void topologySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(in_degree[i] == 0){
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

    for(int i=1;i<=N;i++)
        cout << min_time[i] << '\n';
}

int main() {
    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> time[i];

        int x;
        while(1){
            cin >> x;
            if(x == -1) break;
            v[x].push_back(i);
            in_degree[i]++;
        }
    }

    topologySort();

    return 0;
}
