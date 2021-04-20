#include <iostream>
#include <stack>
using namespace std;
int main() {
    stack<int> s;
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x == 0) s.pop();
        else s.push(x);
    }
    int ret = 0;
    while(s.size()){
        ret += s.top();
        s.pop();
    }
    cout << ret << '\n';
    return 0;
}
