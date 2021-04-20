#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,K,ans=0;
vector<pair<int,int>> v(300001);
vector<int> bag(300001);

int main() {
    cin >> N >> K;
    for(int i=0;i<N;i++)
        cin >> v[i].first >> v[i].second;
    for(int i=0;i<K;i++)
        cin >> bag[i];

    sort(v.begin(),v.begin()+N);
    sort(bag.begin(),bag.begin()+K);

    int j = 0;
    for(int i=0;i<K;i++){
        int MAX = 0;
        while(j < N && v[j].first <= bag[i]){
            MAX = max(MAX, v[j++].second);
        }
        ans += MAX;
    }

    cout << ans;
    return 0;
}
