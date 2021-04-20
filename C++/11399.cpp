#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int tmp = 0;
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += v[i];
        tmp += sum;
    }
    cout << tmp;
    return 0;
}
