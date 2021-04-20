// ref : https://2pound2pound.tistory.com/209
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,K,cnt=0;

int main() {
    cin >> N >> K;
    vector<int> v,p;

    for(int i=0;i<K;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(auto it = v.begin();it != v.end();++it){
        // 이미 꽂혀 있으면 넘어간다
        if(find(p.begin(),p.end(),*it) != p.end())
            continue;

        // 플러그에 여유분이 있으면 꽂고 넘어간다
        if(p.size() < N){
            p.push_back(*it);
            continue;
        }

        // 교체해야 하는 상황
        auto last = it, idx = p.begin();
        for(auto t = p.begin();t != p.end(); ++t){
            auto tmp = find(it + 1, v.end(), *t);

            if(tmp > last) {
                idx = t;
                last = tmp;
            }
        }

        *idx = *it;
        cnt++;
    }
    cout << cnt;
}
