#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int,int> a, pair<int,int> b){
    return a.second < b.second;
}

int main(){
    int N,n1,n2,min,cnt=0;
    vector<pair<int,int>> v;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> n1 >> n2;
        v.push_back({n1,n2});
    }

    sort(v.begin(),v.end());
    sort(v.begin(),v.end(),comp);

    min = v[0].second;
    cnt++;

    for(int i=1;i<N;i++){
        if(v[i].first >= min){
            min = v[i].second;
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}