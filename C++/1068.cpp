#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int,int> m;
vector<int> v;
map<int,int>::iterator it;
map<int,int>::iterator it2;

int N,E;

void CHECK(int key){
    for(int i=key;i<m.size();i++){
        if(m[i] == key)
            CHECK(i);
    }
    v.push_back(key);
}

int main() {
    int A=0;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> m[i];
    }

    cin >> E;
    if(E == 0){ cout << 0; return 0;}

    CHECK(E);

    sort(v.begin(),v.end());
    for(int i=v.size()-1;i>=0;i--){
        m.erase(v.at(i));
    }

    // 자신을 부모노드로 가지는 노드가 없으면 leafNode
    for(it = m.begin(); it != m.end(); it++){
        int tmp = 0;
        for(it2 = m.begin();it2 != m.end();it2++){
            if(it->first == it2->second)
                tmp++;
        }
        if(tmp == 0) A++;
    }

    cout << A;
    return 0;
}
