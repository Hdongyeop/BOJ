#include <iostream>
#include <vector>
#include <string.h>
#define MAX     50001
using namespace std;

int N,M;

vector<int> v[MAX];
bool visited[MAX];
int level[MAX];
int parent[MAX];
int l = 1;

void DFS(int node){
    if(!visited[node]){
        visited[node] = true;
        level[node] = l;
        l++;
        for(int i=0;i<v[node].size();i++){
            int next = v[node][i];
            if(!visited[next])
                parent[next] = node;
            DFS(next);
        }
        l--;
    }
}

int main() {
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a_node,b_node;
        cin >> a_node >> b_node;
        v[a_node].push_back(b_node);
        v[b_node].push_back(a_node);
    }

    memset(visited, false, sizeof(visited));
    DFS(1);

    cin >> M;
    for(int i=0;i<M;i++){
        int a_node, b_node;
        cin >> a_node >> b_node;
        while(level[a_node] < level[b_node])
            b_node = parent[b_node];
        while(level[a_node] > level[b_node])
            a_node = parent[a_node];

        while(a_node != b_node){
            a_node = parent[a_node];
            b_node = parent[b_node];
        }
        cout << b_node << '\n';
    }

    return 0;
}
