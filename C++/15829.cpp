#include <iostream>
#define ll long long
#define MOD     1234567891
using namespace std;
int N;

ll mhash(char *c){
    ll sum = 0;
    int cnt;
    for(int i=0;i<N;i++){
        ll coef = 1;
        cnt = i;
        ll x = (int)c[i] - 96;
        while(cnt){
            coef *= 31;
            coef %= MOD;
            cnt--;
        }
        x *= coef;
        x %= MOD;

        sum += x;
        sum %= MOD;
    }
    return sum;
}

int main() {
    cin >> N;
    char text[N];
    for(int i=0;i<N;i++){
        char c;
        cin >> c;
        text[i] = c;
    }
    ll ret = mhash(text);
    cout << ret << '\n';

    return 0;
}
