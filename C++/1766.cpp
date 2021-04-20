/*
 * Ref. https://m.blog.naver.com/ndb796/221236874984
 * 위상정렬 (Topology Sort)
 */
#include <iostream>
#include <queue>
#include <vector>
#define MAX		32001
using namespace std;
int N, M;
int in_degree[MAX];
vector<int> v[MAX];

void topologySort() {
    int result[MAX];
    priority_queue<int,vector<int>,greater<int>> q;

    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    for (int i = 1; i <= N; i++) {
        int x = q.top();
        q.pop();
        result[i] = x;
        for (int j = 0; j < v[x].size(); j++) {
            int y = v[x][j];
            if (--in_degree[y] == 0)
                q.push(y);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        // 진입 차수
        in_degree[b]++;
    }

    topologySort();

    return 0;
}