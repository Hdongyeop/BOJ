#include <iostream>
using namespace std;
int main() {
    int a,b,c;
    while(1){
        cin >> a >> b >> c;
        if(a ==0 && b == 0 && c == 0) break;
        cout<<(a*a+b*b-c*c&&b*b+c*c-a*a&&c*c+a*a-b*b?"wrong":"right")<<'\n';
    }
    return 0;
}
