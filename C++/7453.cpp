#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
int N;
ll A[4001], B[4001], C[4001], D[4001];
ll AB[4001*4001], CD[4001*4001];

int main() {
    cin >> N;

    for(int i=0;i<N;i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    ll k=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            AB[k] = A[i] + B[j];
            CD[k++] = C[i] + D[j];
        }
    }

    sort(CD, CD+N*N);

    ll cnt = 0;
    for(int i=0;i<N*N;i++){
        ll o = AB[i];
        ll up_idx = upper_bound(CD, CD + N * N, -o) - CD;
        ll lo_idx = lower_bound(CD, CD + N * N, -o) - CD;
        cnt += up_idx - lo_idx;
    }

    cout << cnt;
    return 0;
}
