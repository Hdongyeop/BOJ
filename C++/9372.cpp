/*
 * MST(Minimum Spanning Tree)
 * 그래프의 모든 정점을 연결하되 사이클이 존재하지 않도록 모든 정점을 간선으로 연결하는 것
 * 간선들이 가중치를 가지고 있다면 합을 최소로해서 구해야 한다.
 * 가중치가 없다면 간선의 개수의 최소는 (정점의개수 - 1) 이다.
 */
#include <iostream>
using namespace std;
int main() {
    int T;
    cin >> T;
    while(T--){
       int N,M;
       cin >> N >> M;
       for(int i=0;i<M;i++){
           int a,b;
           cin >> a >> b;
       }
       cout << N - 1 << '\n';
    }
    return 0;
}
