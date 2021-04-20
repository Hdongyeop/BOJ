#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int alpha[26];

int pow(int g, int x){
    int ret = 1;
    for(int i=0;i<x;i++)
        ret *= g;

    return ret;
}

int main() {
    memset(alpha,0,sizeof(alpha));
    cin >> N;

    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        for(int j=0;j<str.size();j++){
            alpha[str[j]-65] += pow(10,str.size()-j-1);
        }
    }

    sort(alpha,alpha+26,greater<int>());

    int ans = 0,num = 9;

    for(int i=0;i<26;i++){
        if(alpha[i] == 0) break;
        ans += (num--) * alpha[i];
    }

    cout << ans;
    return 0;
}
