#include <iostream>
using namespace std;
int main() {
    int i,N,index=1;
    cin >> N;
    if(N==1) {cout << "666" << '\n'; return 0;}
    for(i=667;;i++){
        int tmp = i;
        while(tmp){
            bool ch = true;
            if(tmp%1000==666 && ch){
                index++;
                ch = false;
                break;
            }
            tmp /= 10;
        }
        if(index==N) break;
    }
    cout << i << '\n';
    return 0;
}
