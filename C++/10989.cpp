#include <iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int N,tmp;
    int arr[10001] = {0,};
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        arr[tmp]++;
    }

    for(int i=0;i<10001;i++){
        int k=arr[i];
        while(k>0){
            cout << i << '\n';
            k--;
        }
    }
    return 0;
}