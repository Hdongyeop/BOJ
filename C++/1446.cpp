/*
 * https://wootool.tistory.com/33
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SHORTCUT{
    int start;
    int end;
    int len;
};

bool comp(SHORTCUT a, SHORTCUT b){
    return a.start < b.start;
}


int main(){
    int N,D,cnt=0,ccc=0;
    int arr[10000] = {0,};
    vector<SHORTCUT> v(10001);

    cin >> N >> D;
    for(int i=0;i<N;i++){
        SHORTCUT s;
        cin >> s.start >> s.end >> s.len;
        v[i] = s;
    }

    sort(v.begin(),v.begin() + N,comp);

    while(cnt != D){
        if(v[ccc].start == cnt){
            if(v[ccc].end <= D){
                if(arr[v[ccc].end] != 0){
                    arr[v[ccc].end] = min(arr[cnt] + v[ccc].len, arr[v[ccc].end]);
                } else
                    arr[v[ccc].end] = arr[cnt] + v[ccc].len;
            }
            ccc++;
        }
        else {
            if(arr[cnt+1] != 0)
                arr[cnt+1] = min(arr[cnt+1],arr[cnt]+1);
            else
                arr[cnt+1] = arr[cnt] + 1;
            cnt++;
        }
    }


    cout << arr[D];
    return 0;
}