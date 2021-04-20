#include <iostream>
#include <vector>
using namespace std;
int sum_of_height=0;
vector<int> v[500001];
int visited[500001];

void DFS(int start, int height){
    bool leaf = true;
    visited[start] = true;
    for(int i=0;i<v[start].size();i++){
        int x = v[start][i];
        if(!visited[x]){
            leaf = false;
            DFS(x,height+1);
        }
    }

    if(leaf) sum_of_height += height;
}

int main() {
    int N;
    cin >> N;
    for(int i=0;i<N-1;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    DFS(1,0);
    if(sum_of_height % 2 == 0)
        cout << "No";
    else cout << "Yes";
    return 0;
}
