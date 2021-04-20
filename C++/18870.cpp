#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v,index;
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
        index.push_back(tmp);
    }

    sort(index.begin(),index.end());
    index.erase(unique(index.begin(),index.end()),index.end());

    for(int i : v){
        int pos = lower_bound(index.begin(),index.end(),i) - index.begin();
        cout << pos << " ";
    }
    return 0;
}
