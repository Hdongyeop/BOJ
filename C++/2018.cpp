#include <iostream>
using namespace std;
int num,cnt=0;

int main() {
    cin >> num;

    int s=1,e=1,sum=0;
    while(1){
        if(sum >= num) sum -= s++;
        else if(e == num) {cnt++; break;}
        else sum += e++;

        if(sum == num) cnt++;
    }

    cout << cnt;
    return 0;
}
