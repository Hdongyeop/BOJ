#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[2001][2001];
vector<int> LEFT,RIGHT;

int dp(int l, int r){
    if(l >= N || r >= N) return 0;

    //반복체크
    int &result = arr[l][r];
    if(result != -1) return result;
    result = 0;

    //dp
    if(LEFT[l] > RIGHT[r])
        result += max(RIGHT[r] + dp(l,r+1), max(dp(l+1,r), dp(l+1,r+1)));
    else
        result += max(dp(l+1,r),dp(l+1,r+1));

    //결과
    return result;
}

int main(){
    memset(arr,-1,sizeof(arr));
    cin >> N;
    for(int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        LEFT.push_back(tmp);
    }
    for(int i=0;i<N;i++){
        int tmp;
        cin >> tmp;
        RIGHT.push_back(tmp);
    }

    cout << dp(0,0);
    return 0;
}