/*
 * MST
 * Kruskal's(union-find 기법) (Ref. https://victorydntmd.tistory.com/101?category=686701)
 *                           (Ref. https://yabmoons.tistory.com/186)
 * Prim's(priority_queue) (Ref. https://victorydntmd.tistory.com/102?category=686701)
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct EDGE {
    int a;
    int b;
    int weight;
};
int N,M,ans=0;
int parent[1001];
vector<EDGE> v;

bool comp(EDGE a, EDGE b){
    return a.weight < b.weight;
}

int find(int x){
    if(parent[x] == x) return x;
    else return parent[x] = find(parent[x]);
}

//union
void merge(int x, int y){
    x = find(x);
    y = find(y);
    if(x != y) parent[y] = x;
}

bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return true;
    else return false;
}

int main() {
    cin >> N >> M;
    for(int i=0;i<M;i++){
        EDGE e;
        cin >> e.a >> e.b >> e.weight;
        v.push_back(e);
    }

    sort(v.begin(),v.end(),comp);

    for(int i=1;i<=N;i++)
        parent[i] = i;

    for(int i=0;i<M;i++){
        if(isSameParent(v[i].a, v[i].b) == false){
            merge(v[i].a, v[i].b);
            ans += v[i].weight;
        }
    }

    cout << ans << '\n';
    return 0;
}
