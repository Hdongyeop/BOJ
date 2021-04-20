#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> v;
int arr[8002];
int N;
double sum=0;

int main() {
    int uno=0,dos=0,tres=0,quatro=0;
    memset(arr,0,sizeof(arr));
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        v.push_back(x);
        sum += x;
        x += 4000;
        arr[x]++;
    }

    uno = floor((sum/N)+0.5);

    sort(v.begin(),v.end());
    quatro = v.back() - v.front();
    dos = v[N/2];

    v.clear();
    int MAX = 0;
    for(int i=0;i<8002;i++){
        MAX = max(MAX, arr[i]);
    }
    for(int i=0;i<8002;i++){
        if(arr[i] == MAX){
            int x = i-4000;
            v.push_back(x);
        }
    }

    if(v.size() == 1){
        tres = v.front();
    } else {
        sort(v.begin(),v.end());
        tres = v[1];
    }

    cout << uno << '\n' << dos << '\n' << tres << '\n' << quatro;
    return 0;
}
