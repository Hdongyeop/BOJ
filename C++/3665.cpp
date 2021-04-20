#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX     510
using namespace std;
int TC,TS; // TestCase, TeamSize
int inDegree[MAX];
vector<int> v[MAX];
vector<int> pp; //pre-prized

void TPsort(){
    vector<int> result;
    queue<int> q;
    for(int i=1;i<=TS;i++)
        if(inDegree[i] == 0) q.push(i);

    bool certain = true;

    while(!q.empty()){
        if(q.size() > 1){
            certain = false;
            break;
        }
        int x = q.front();
        q.pop();
        result.push_back(x);
        for(int j=0;j<v[x].size();j++){
            int y = v[x][j];
            if(--inDegree[y] == 0){
                q.push(y);
            }
        }
    }

    if(!certain)
        cout << "?" << '\n';
    else if(result.size() == TS){
        for(auto a : result)
            cout << a << " ";
        cout << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}

int main() {
    cin >> TC;
    while(TC--){
        for(int i=0;i<MAX;i++) v[i].clear();
        pp.clear();
        memset(inDegree,0,sizeof(inDegree));

        cin >> TS;

        for(int i=0;i<TS;i++){
            int x;
            cin >> x;
            pp.push_back(x);
        }

        for(auto it = pp.begin();it!=pp.end();it++) {
            for (auto tmp = it + 1; tmp != pp.end(); tmp++) {
                v[*it].push_back(*tmp);
                inDegree[*tmp]++;
            }
        }

        int C; //change
        cin >> C;
        for(int i=0;i<C;i++){
            int a,b;
            cin >> a >> b;

            if(find(v[a].begin(),v[a].end(),b) != v[a].end()){
                auto it = find(v[a].begin(),v[a].end(),b);
                v[a].erase(it);
                v[b].push_back(a);
                inDegree[b]--;
                inDegree[a]++;
            }
            else if(find(v[b].begin(),v[b].end(),a) != v[b].end()){
                auto it = find(v[b].begin(),v[b].end(),a);
                v[b].erase(it);
                v[a].push_back(b);
                inDegree[a]--;
                inDegree[b]++;
            }
        }
        TPsort();
    }
    return 0;
}
