#include <iostream>
using namespace std;
int x,y,w,h;
int main() {
    cin >> x >> y >> w >> h;

    int ans = 987654321;

    if(ans > x) ans = x;
    if(ans > y) ans = y;
    if(ans > w-x) ans = w-x;
    if(ans > h-y) ans = h-y;

    cout << ans;
    return 0;
}
