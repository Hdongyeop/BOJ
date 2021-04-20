#include <iostream>
#include <cstring>
#include <vector>
#define MAX     4000003
using namespace std;

vector<int> v;
bool prime[MAX];
int N, NUM = 0;

void eratos(){
    for(long long i=2;i*i<MAX;i++){
        for(long long j=i*i;j<MAX;j+=i){
            prime[j] = false;
        }
    }
}

void solve(int n){
    for(int i=2;i<=n;i++){
        if(prime[i]){
            v.push_back(i);
        }
    }
    /*
     * Tow Pointer
     */
    int start = 0, end = 0, sum = 0;

    while(true){
        if(sum >= n) sum -= v[start++];
        else if(end == v.size()) break;
        else sum += v[end++];

        if(sum == n) NUM++;
    }
}

int main() {
    memset(prime, true, sizeof(prime));
    cin >> N;

    eratos();

    solve(N);

    cout << NUM << '\n';

    return 0;
}
