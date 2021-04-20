#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<int> v[10];
int arr[1024];
int K;
/*
 * 중위순회 -> 전위순회
 */
void solve(int s, int e, int cnt){
    if(s > e) return;
    int mid = (s+e)/2;
    v[cnt].push_back(arr[mid]);
    solve(s,mid-1, cnt+1);
    solve(mid+1,e,cnt+1);
}

int main() {
    cin >> K;
    int n = (int)pow(2,K) - 1;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }

    solve(1,n,0);

    for(int i=0;i<K;i++){
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}