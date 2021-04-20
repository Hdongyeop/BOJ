#include<iostream>

using namespace std;
typedef long long ll;

int a[100002] = {-1};
ll psum[100001] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }
    a[++n]=0;

    ll ret=0;
    int s[100002] ={0},top=0;
    for (int i = 1; i <= n; ++i){
        while(a[s[top]]>=a[i]){
            int height=a[s[top--]];
            ll val=height*(psum[i-1]-psum[s[top]]);
            if(ret<val)ret=val;
        }
        s[++top]=i;
    }
    cout<<ret;
}