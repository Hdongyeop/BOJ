#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct PT{
    int x;
    int y;
};
int N;
vector<PT> v;

bool comp(PT a, PT b){
    if(a.y == b.y) {
        return a.x < b.x;
    }
    return a.y < b.y;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        PT p;
        cin >> p.x >> p.y;
        v.push_back(p);
    }
    sort(v.begin(),v.end(),comp);
    for(int i=0;i<N;i++){
        cout << v[i].x << " " << v[i].y << '\n';
    }
    return 0;
}
