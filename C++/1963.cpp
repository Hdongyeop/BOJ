#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#define MAX_INT     10001
using namespace std;

bool prime[MAX_INT];
int check[MAX_INT];
int N, start_node, end_node;
/*
 * 에라토스테네스의 체
 * 일정범위의 소수를 지워가며 구할 수 있다.
 */
void eratos(){
    for(int i=2;i*i<MAX_INT;i++){
        for(int j=i*i;j<MAX_INT;j+=i){
            prime[j] = false;
        }
    }
}
/*
 * BFS는 간선들의 가중치가 동일하거나 없을때 최소 거리를 구할수 있다.
 */
void BFS(int start){
    queue<int> q;
    q.push(start);
    check[start] = 0;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            string node_s = to_string(node);
            for(int j=0;j<10;j++){
                node_s[i] = j + '0';
                int next = atoi(node_s.c_str());
                if(next >= 1000 && prime[next] == true && check[next] == -1){
                    check[next] = check[node] + 1;
                    q.push(next);
                }
            }
        }
    }
}

int main(){
    memset(prime, true, sizeof(prime));

    eratos();

    cin >> N;

    while(N--){
        memset(check,-1,sizeof(check));

        cin >> start_node >> end_node;

        BFS(start_node);

        if(check[end_node] != -1){
            cout << check[end_node] << '\n';
        } else {
            cout << "Impossible\n";
        }
    }
}