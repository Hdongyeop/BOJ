#include <iostream>
#include <vector>
#include <string.h>
#define MAX         100001
using namespace std;

bool DO = true;
int length = 0;
int end_node = 0;
int V;
int visited[MAX];
vector<pair<int,int>> linkedlist[MAX];

void DFS(int node, int weight){
    if(!visited[node]){
        visited[node] = 1;

        if(length < weight){
            length = weight;
            end_node = node;
        }

        for(int i=0;i<linkedlist[node].size();i++){
            DFS(linkedlist[node][i].first, weight + linkedlist[node][i].second);
        }
    };
}

int main() {
    int a_node, b_node, weight;
    cin >> V;
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<V-1;i++){
        cin >> a_node >> b_node >> weight;
        linkedlist[a_node].push_back(make_pair(b_node,weight));
        linkedlist[b_node].push_back(make_pair(a_node,weight));
    }

    DFS(1,0);
    memset(visited, 0, sizeof(visited));
    length = 0;
    DFS(end_node, 0);

    cout << length;
    return 0;
}
