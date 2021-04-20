#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int N,d,k,c,len=0,ans=0;
int arr[30001];
int check[3001];
queue<int> q;

int main() {
    cin >> N >> d >> k >> c;
    memset(arr,0,sizeof(arr));
    for(int i=0;i<N;i++)
        cin >> arr[i];

    for(int i=0;i<k;i++){
        q.push(arr[i]);
        if(check[arr[i]-1] == 0)
            len++;
        check[arr[i]-1]++;
    }

    if(check[c-1] != 0)
        ans = len;
    else
        ans = len+1;

    for(int i=k;i<N+k;i++){
        int tmp = len;

        int front = q.front();
        check[front-1]--;
        if(check[front-1] == 0)
            tmp--;
        q.pop();

        q.push(arr[i%N]);
        if(check[arr[i%N]-1] == 0)
            tmp++;
        check[arr[i%N]-1]++;

        if(check[c-1] != 0)
            ans = max(ans, tmp);
        else
            ans = max(ans, tmp+1);

        len = tmp;
    }

    cout << ans;
    return 0;
}
