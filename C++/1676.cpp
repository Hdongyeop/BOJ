#include <iostream>
using namespace std;
int N,cnt=0;
int main() {
    cin >> N;
    while(N/5 != 0){
        cnt += N/5;
        N /= 5;
    }
    cout << cnt << '\n';
    return 0;
}
