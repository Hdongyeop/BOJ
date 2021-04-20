#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 51
#define MAX_M 14
#define MAX_INF 987654321

int N,M,ans;
int city[MAX_N][MAX_N];
bool check[MAX_M];

vector<pair<int,int>> chicken;
vector<pair<int,int>> person;

void dfs(int cur_num, int cur_cnt){
    if(cur_num > chicken.size()) return;

    if(cur_cnt == M)
    {
        int cmp = 0;

        for(int i=0;i<person.size();i++){
            int dist = MAX_INF;
            for(int j=0;j<chicken.size();j++){
                if(check[j])
                {
                    int px = person[i].first, py = person[i].second;
                    int samx = chicken[j].first, samy = chicken[j].second;
                    int d = abs(px - samx) + abs(py - samy);
                    dist = min(dist,d);
                }
            }
            cmp += dist;
        }
        ans = min(ans,cmp);

        return;
    }

    check[cur_num] = true;
    dfs(cur_num + 1, cur_cnt + 1);
    check[cur_num] = false;
    dfs(cur_num + 1, cur_cnt);
}

int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> city[i][j];
            if(city[i][j] == 1)
                person.push_back({i,j});
            else if(city[i][j] == 2)
                chicken.push_back({i,j});
        }
    }

    ans = MAX_INF;

    dfs(0,0);

    cout << ans;
    return 0;
}
