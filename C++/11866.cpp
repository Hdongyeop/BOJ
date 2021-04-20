#include <iostream>
#include <vector>
using namespace std;
int arr[1001];
int main() {
    vector<int> ans;
    int n,k;
    cin >> n >> k;
    int round = k;
    for(int i=1;i<=n;i++){
        arr[i] = i;
    }

    while(1){
        ans.push_back(arr[k]);
        if(ans.size() == n) break;
        arr[k] = -1;
        int cnt = 0;
        while(cnt != round){
            k++;
            if(k > n) k -= n;
            if(arr[k] != -1) cnt++;
        }
    }

    cout << "<";
    for(int i=0;i<ans.size()-1;i++){
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size()-1] << ">" << '\n';

    return 0;
}
