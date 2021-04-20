#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,ans=0;
vector<int> p;
vector<int> m;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        if(x > 0) p.push_back(x);
        else m.push_back(x);
    }

    //if(N == 1) { cout << arr[0]; return 0; }
    sort(p.begin(),p.end(),greater<int>());
    sort(m.begin(),m.end(),less<int>());

    for(int i=0;i<p.size();i++){
        if(i == p.size()-1) { ans += p[i]; break; }
        int mul = p[i] * p[i+1];
        int sum = p[i] + p[i+1];
        if(mul > sum){
            ans += mul;
            i++;
        } else {
            ans += p[i];
        }
    }

    for(int i=0;i<m.size();i++){
        if(i == m.size()-1) { ans += m[i]; break;}
        int mul = m[i] * m[i+1];
        int sum = m[i] + m[i+1];
        if(mul > sum){
            ans += mul;
            i++;
        } else {
            ans += m[i];
        }
    }

    cout << ans;
    return 0;
}
