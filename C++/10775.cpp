#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int G,P,cnt=0;
int GATE[100001];
vector<int> v;

int main() {
    memset(GATE,0,sizeof(GATE));
    cin >> G >> P;
    for(int i=0;i<P;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    // GATE 배열에는 ( 아래에 수용된 비행기의 개수 ) / Clever Counting?
    for(int i=0;i<P;i++){
        int x = v[i];
        while(x > 0 && GATE[x] > 0){
            int t = GATE[x];
            GATE[x]++;
            x -= t;
        }
        if(x <= 0)
            break;
        else{
            GATE[x] = 1;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
