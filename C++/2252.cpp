#include <iostream>
#include <vector>
#include <queue>
#define MAX		32001
using namespace std;

int N, M;
int in_degree[MAX];
vector<int> v[MAX];

void topologySort() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        int x = q.front();
        q.pop();

        cout << x << " ";

        for (int j = 0; j < v[x].size(); j++) {
            int y = v[x][j];

            if (--in_degree[y] == 0)
                q.push(y);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        in_degree[y]++;
    }

    topologySort();

    return 0;
}