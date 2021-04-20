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
    if(x != y) {
        (x > y) ? parent[x] = y : parent[y] = x;
    };
}

bool isSameParent(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return true;
    else return false;
}

int main() {
    cin >> N >> M;
    char arr[N+1];
    for(int i=1;i<=N;i++){
        char c;
        cin >> c;
        arr[i] = c;
    }

    for(int i=0;i<M;i++){
        EDGE e;
        cin >> e.a >> e.b >> e.weight;
        if(arr[e.a] != arr[e.b])
            v.push_back(e);
    }

    sort(v.begin(),v.end(),comp);

    for(int i=1;i<=N;i++)
        parent[i] = i;

    for(int i=0;i<v.size();i++){
        if(isSameParent(v[i].a,v[i].b) == false){
            merge(v[i].a, v[i].b);
            ans += v[i].weight;
        }
    }
    int cmp = find(parent[1]);
    bool chk = true;
    for(int i=1;i<=N;i++){
        if(cmp != find(parent[i]))
            chk = false;
    }
    if(chk && ans != 0)
        cout << ans;
    else cout << -1;

    return 0;
}
