#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX_SIZE 500000
using namespace std;
// curSize를 쓰면 각 층별로 cnt를 증가시키기 때문에 개별 노드에 대해서는 확인하기 힘든점이 있다.
// 리프노드임을 확신할 수 있을 때는 더이상 방문할 게 없는지 확인하는 부분이다.
// -> 각 노드마다 이전 상태로부터 전파받아 cnt를 증가시키면 개별 노드를 확인하기 편하다.
int N; // 트리의 정점 개수
vector<int> graph[MAX_SIZE + 1];
int visited[MAX_SIZE + 1];
int ans;
void bfs(int start) {
    queue<int> q;
    memset(visited, 0, sizeof(visited));
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int curNode = q.front();
        bool notleaf = false;
        q.pop();
        for (int i = 0; i < graph[curNode].size(); i++) {
            int nx = graph[curNode][i];
            if (visited[nx] == 0) { // 리프노드일 때는 nx가 연결된 부모노드이므로 실행안됨
                visited[nx] = visited[curNode] + 1; // 한 칸이동
                notleaf = true; // if문에 들어왔다라는게 리프노드가 아님
                q.push(nx);
            }
        }
        if (!notleaf) ans += visited[curNode]-1;// 리프노드는 카운트를 세지않음
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    bfs(1);
    if (ans % 2 == 1) {
        cout << "YES" << '\n';
    } else {
        cout << "No" << '\n';
    }
}