#include <iostream>
#include <deque>
using namespace std;
int main() {
    deque<int> v;
    int n;

    cin >> n;

    for(int i=n;i>=1;i--){
        v.push_back(i);
    }

    while(v.size() != 1){
        v.pop_back();
        int end = v.back();
        v.pop_back();
        v.push_front(end);
    }

    cout << v[0] << '\n';
    return 0;
}
