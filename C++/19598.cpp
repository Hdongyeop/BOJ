#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,cnt,res;
vector<pair<int,int>> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,1}), v.push_back({b,-1});
    }

    sort(v.begin(),v.end());

    for(auto& i : v){
        cnt += i.second;
        res = max(res,cnt);
    }
    cout << res;
}