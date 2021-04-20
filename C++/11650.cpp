#include <iostream>
#include <algorithm>
using namespace std;

struct DOT{
    int x;
    int y;
};

bool comp(const DOT &d1, const DOT &d2){
    if(d1.x == d2.x){
        if(d1.y < d2.y) return true;
        else return false;
    }
    return d1.x < d2.x;
}

int main() {
    int n;
    cin >> n;

    DOT *dot = new DOT[n];

    for(int i=0;i<n;i++){
        cin >> dot[i].x >> dot[i].y;
    }

    sort(dot,dot+n,comp);

    for(int i=0;i<n;i++){
        cout << dot[i].x << " " << dot[i].y << '\n';
    }

    delete[] dot;
    return 0;
}
