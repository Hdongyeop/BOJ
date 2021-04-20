#include <iostream>
#include <queue>
using namespace std;
vector<long long> v;
priority_queue<long long, vector<long long>, greater<> > pq;
int K,N;
int main() {
    cin >> K >> N;
    for(int i=0;i<K;i++){
        int a;
        cin >> a;
        v.push_back(a);
        pq.push(a);
    }

    for(int k=0;k<N-1;k++){
        long long top = pq.top(); pq.pop();
        for(int i : v) {
            long long tmp = i * top;
            pq.push(tmp);
            if(top % i == 0) break;
        }

    }

    cout << pq.top() << '\n';
    return 0;
}
