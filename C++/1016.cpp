#include <iostream>
#define MAX     1000001

using namespace std;

long long arr[MAX] = {0};
int count = 0;

int main(){
    long long min;
    long long max;

    cin >> min >> max;

    for(long long i = 2;i*i<=max;i++){
        long long x = min / (i*i);

        if(min % (i*i) != 0){
            x++;
        }

        while(x*(i*i) <= max){
            arr[x*(i*i) - min] = 1;
            x++;
        }
    }

    for(int i=0;i<=max-min;i++){
        if(arr[i] == 0)
            count++;
    }

    cout << count << '\n';

    return 0;
}