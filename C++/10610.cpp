#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool flag = false;
vector<int> v;

int main() {
    string str;
    cin >> str;
    int sum = 0;
    for(int i=0;i<str.size();i++){
        if(str[i] == '0') flag = true;
        v.push_back(str[i]-'0');
        sum += v[i];
    }

    if((sum%3 == 0) && flag){
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0;i<v.size();i++){
            cout << v[i];
        }
        cout << '\n';
    } else {
        cout << -1;
    }
    return 0;
}
