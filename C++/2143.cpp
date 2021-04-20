#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;
ll T,n,m,ans;
ll A[1001],B[1001];
vector<ll> Av, Bv;

int main() {
    cin >> T;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> A[i];
    cin >> m;
    for(int i=0;i<m;i++)
        cin >> B[i];

    for(int i=0;i<n;i++){
        ll sum = A[i];
        Av.push_back(sum);
        for(int j=i+1;j<n;j++){
            sum += A[j];
            Av.push_back(sum);
        }
    }


    for(int i=0;i<m;i++){
        ll sum = B[i];
        Bv.push_back(sum);
        for(int j=i+1;j<m;j++){
            sum += B[j];
            Bv.push_back(sum);
        }
    }

    sort(Bv.begin(), Bv.end());

    for(int i=0;i<Av.size();i++){
        int upper = upper_bound(Bv.begin(),Bv.end(),T-Av[i]) - Bv.begin();
        int lower = lower_bound(Bv.begin(),Bv.end(),T-Av[i]) - Bv.begin();

        ans += upper - lower;
    }

    cout << ans;
    return 0;
}
