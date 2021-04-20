#include <iostream>
#include <vector>
using namespace std;

vector<int> node[100001];
int parent[100001];
int visited[100001] = {0,};

void DFS(int num){
    visited[num] = 1;

    for(int i=0;i<node[num].size();i++){
        int n = node[num][i];

        if(!visited[n]){
            // node[num]에 연결된 숫자의 노드들은 부모가 node[num]이다.( visited로 겹쳐진 숫자는 거른다 )
            parent[n] = num;
            DFS(n);
        }
    }
}

int main() {
    int N;
    cin >> N;

    for(int i=0;i<N-1;i++){
        int a,b;
        cin >> a >> b;
        // a와 b는 서로 연결되어있다.
        node[a].push_back(b);
        node[b].push_back(a);
    }

    DFS(1);

    for(int i=2;i<=N;i++){
        cout << parent[i] << '\n';
    }

    return 0;
}
