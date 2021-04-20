#include <iostream>
#include <cmath>
using namespace std;
int N,r,c,ans=0;

int solve(int n, int y, int x){
    int m = ((int)pow(2,n)-1)/2;

    n -= 1;

    int area;
    if(y <= m && x <= m) area = 0;
    else if(y <= m && x > m) area = 1;
    else if(y > m && x <= m) area = 2;
    else if(y > m && x > m) area = 3;

    ans += (int)pow(2,n) * (int)pow(2,n) * area;

    if(n == 0) return ans;

    int new_y = y - (int)pow(2,n);
    int new_x = x - (int)pow(2,n);
    if(new_y < 0) new_y = y;
    if(new_x < 0) new_x = x;

    solve(n,new_y,new_x);

    return 0; // can't reach
}

int main() {
    cin >> N >> r >> c;

    solve(N,r,c);

    cout << ans << '\n';
    return 0;
}
