#include <iostream>
using namespace std;
int N,M;

int main() {
    cin >> N >> M;

    if(N == 1)
        cout << 1;
    else if(N == 2){
        if(M < 3)
            cout << 1;
        else if(M < 5)
            cout << 2;
        else if(M < 7)
            cout << 3;
        else
            cout << 4;
    } else if(N >= 3){
        if(M <= 6){
            if(M >= 4)
                cout << 4;
            else
                cout << M;
        } else {
            cout << M-2;
        }
    }

    return 0;
}
