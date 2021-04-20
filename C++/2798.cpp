#include <iostream>
#include <vector>
using namespace std;
int N,M,ans=0;
vector<int> v;
int main() {
    cin >> N >> M;

    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                if(i!=j&&i!=k&&j!=k){
                    int sum = v[i]+v[j]+v[k];
                    if(sum > ans && sum <= M)
                        ans = sum;
                }
            }
        }
    }

    cout << ans;

    return 0;
}
