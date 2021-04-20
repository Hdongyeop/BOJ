#include <iostream>
#include <queue>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tc = 0; tc<t;tc++){
        int N,M,cnt=0;
        queue<pair<int,int>> q;
        priority_queue<int> pq;

        cin >> N >> M;
        for(int i=0;i<N;i++){
            int a;
            cin >> a;
            q.push({i,a}); // i : index, a : 우선순위
            pq.push(a);
        }

        while(!q.empty()){
            int n_idx = q.front().first; //now_index
            int n_pri = q.front().second; //now_priority
            q.pop();

            if(pq.top() == n_pri){
                pq.pop();
                cnt++;
                if(n_idx == M){
                    cout << cnt << '\n';
                    break;
                }
            } else {
                q.push({n_idx,n_pri});
            }
        }
    }
    return 0;
}