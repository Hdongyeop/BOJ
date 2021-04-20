#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n,tmp;
    priority_queue<int,vector<int>,greater<int>> min_heap; //greater : 내림차순, less : 오름차순

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&tmp);
        if(tmp == 0){
            if(min_heap.empty()) printf("0\n");
            else {
                printf("%d\n",min_heap.top());
                min_heap.pop();
            }
        } else {
            min_heap.push(tmp);
        }
    }

    return 0;
}
