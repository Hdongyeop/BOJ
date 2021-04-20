#include <iostream>
#include <algorithm>
using namespace std;
int arr[101];
int visited[10001];
int n,k;

int main() {
    cin >> n >> k;

    for(int i=1;i<=k;i++){
        visited[i] = 987654321;
    }

    for(int i=1;i<=n;i++){
        cin >> arr[i];
        if(arr[i] <= k)
            visited[arr[i]] = 1;
    }

    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            int tmp = i - arr[j];
            if(tmp > 0){
                visited[i] = min(visited[i], visited[tmp] + 1);
            }
        }
    }
    if(visited[k] == 987654321)
        cout << -1 << '\n';
    else
        cout << visited[k] << '\n';
    return 0;
}
