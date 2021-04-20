#include <iostream>
#include <vector>
#define ll long long
using namespace std;
ll G,N=1,P=1;
vector<int> v;

ll pow(ll a, int b){
    int tmp = a;
    while(--b)
        a *= tmp;
    return a;
}

int main() {
    cin >> G;
    // N^2 = G + P^2

    while(1){
        ll dN = pow(N,2);
        ll dP = pow(P,2);
        //if(dN - dP > G) break;
        if(N+P > G) break;
        if(dN < G + dP)
            N++;
        else if(dN > G + dP)
            P++;
        else{
            v.push_back(N);
            N++;
        }
    }

    if(v.empty())
        cout << -1 << '\n';
    else{
        for(int i : v)
            cout << i << '\n';
    }
    return 0;
}
