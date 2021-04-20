#include <iostream>
#include <queue>
#define MAX     100000
using namespace std;

bool check[MAX+1] = {false,};
int N,K,NUM,len=1,result=0;

int main() {
    queue<int> q;
    cin >> N >> K;
    q.push(N);
    while(!q.empty()){
        NUM=0;
        for(int i=0;i<len;i++){
            int v = q.front();
            q.pop();

            if(v == K){
                cout << result;
                return 0;
            }

            check[v] = true; //check는 시행횟수를 줄이려고..(메모리초과남)

            if(v+1 <= MAX && !check[v+1]){
                q.push(v+1);
                NUM++;
                check[v+1] = true;
            }

            if(v-1 >= 0 && !check[v-1]){
                q.push(v-1);
                NUM++;
                check[v-1] = true;
            }

            if(v*2 <= MAX && !check[v*2]){
                q.push(v*2);
                NUM++;
                check[v*2] = true;
            }
        }
        len = NUM;
        result++;
    }
    return 0;
}
