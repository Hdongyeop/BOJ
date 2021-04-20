#include <iostream>
#include <vector>
#include <queue>
#define MAX     1001
using namespace std;

int in_degree[MAX];
vector<int> v[MAX];
vector<int> result;
int N,M,x,y;
bool cycle = false;

void topology(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if(in_degree[i] == 0)
            q.push(i);
    }

    for(int i=1;i<=N;i++){
        int x = q.front();
        q.pop();

        result.push_back(x);

        for(int j=0;j<v[x].size();j++){
            int y = v[x][j];
            if(--in_degree[y] == 0)
                q.push(y);
        }

        if(i != N && q.empty()){
            cout << 0;
            cycle = true;
            return;
        }
    }
}

int main() {
    cin >> N >> M;
    if(N == 1){
        cout << 1;
        return 0;
    }
    while(M--){
        cin >> x;

        int prev = 0;
        for(int i=0;i<x;i++){
            cin >> y;
            if(prev != 0){
                v[prev].push_back(y);
                in_degree[y]++;
            }
            prev = y;
        }
    }

    topology();

    if(!cycle){
        for(auto i : result)
            cout << i << '\n';
    }

    return 0;
}
