#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    vector<string> v;
    vector<string> ans;

    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    string str;
    for(int i=0;i<m;i++){
        cin >> str;

        if(binary_search(v.begin(),v.end(),str))
            ans.push_back(str);
    }

    sort(ans.begin(),ans.end());

    cout << ans.size() << '\n';
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << '\n';

    return 0;
}