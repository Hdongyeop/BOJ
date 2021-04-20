#include <iostream>
using namespace std;
int C,P,ans=0;
int arr[101];

void solve_two(int f, int b){
    for(int i=0;i<=C-2;i++){
        int front = arr[i];
        int back = arr[i+1];
        while(1){
            if(front == 0 || back == 0) {
                if(front == f && back == b){
                    ans++;
                }
                break;
            }
            front--,back--;
        }
    }
}

void solve_three(int f, int m, int b){
    for(int i=0;i<=C-3;i++){
        int front = arr[i];
        int mid = arr[i+1];
        int back = arr[i+2];
        while(1){
            if(front == 0 || mid == 0 || back == 0){
                if(front == f && mid == m && back == b){
                    ans++;
                }
                break;
            }
            front--,mid--,back--;
        }
    }
}

int main() {
    cin >> C >> P;
    for(int i=0;i<C;i++){
        int x;
        cin >> x;
        arr[i] = x;
    }

    if(P == 1){
        ans += C;
        for(int i=0;i<=C-4;i++){
            bool chk = true;

            for(int j=i;j<i+4;j++){
                if(arr[i] != arr[j])
                    chk = false;
            }

            if(chk) ans++;
        }
    } else if(P == 2){
        solve_two(0,0);
    } else if(P == 3){
        solve_three(0,0,1);
        solve_two(1,0);
    } else if(P == 4){
        solve_three(1,0,0);
        solve_two(0,1);
    } else if(P == 5){
        solve_three(0,0,0);
        solve_three(1,0,1);
        solve_two(1,0);
        solve_two(0,1);
    } else if(P == 6){
        solve_three(0,0,0);
        solve_three(0,1,1);
        solve_two(2,0);
        solve_two(0,0);
    } else if(P == 7){
        solve_three(0,0,0);
        solve_three(1,1,0);
        solve_two(0,0);
        solve_two(0,2);
    }

    cout << ans;
    return 0;
}
