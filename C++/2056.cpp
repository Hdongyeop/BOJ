#include <iostream>
#include <vector>
#include <queue>
#define MAX		10001
using namespace std;
int N,ans=0;
int in_degree[MAX];
int time[MAX];
int min_time[MAX];
vector<int> v[MAX];

void topologySort() {
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (in_degree[i] == 0) {
            q.push(i);
            min_time[i] = time[i];
        }

    for (int i = 1; i <= N; i++) {
        int x = q.front();
        q.pop();

        for (int j = 0; j < v[x].size(); j++) {
            int y = v[x][j];
            in_degree[y]--;
             /*
              *  최소 시간 이라는게 어색하지만 맞는말이다
              *  왜냐하면 자신의 작업을 수행하기 위해 충족되어야 하는
              *  조건 중 최대로 오래걸리는 시간 + 자신의 수행시간 이기 때문이다.
              */
            if (min_time[y] < min_time[x] + time[y]) {
                min_time[y] = min_time[x] + time[y];
            }
            if (in_degree[y] == 0)
                q.push(y);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (min_time[i] > ans)
            ans = min_time[i];
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        time[i] = a;
        for (int j = 0; j < b; j++) {
            int x;
            cin >> x;
            v[x].push_back(i);
            // 진입차수
            in_degree[i]++;
        }
    }

    topologySort();

    cout << ans;
    return 0;
}