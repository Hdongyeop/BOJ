#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,cnt;
vector<int> u;
vector<int> d;
vector<int> ans;

int lowerBound(int n){
    int low = 0;
    int high = u.size();
    while(low < high) {
        int mid = low + (high-low)/2;
        if(n <= u[mid]){
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

int upperBound(int n){
    int low = 0;
    int high = u.size();
    while(low < high) {
        int mid = low + (high-low)/2;
        if(n >= u[mid]){
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        u.push_back(x);
    }

    sort(u.begin(),u.end());

    cin >> M;
    for(int i=0;i<M;i++){
        int x;
        cin >> x;
        d.push_back(x);
    }

    for(int i=0;i<M;i++){
        int lower = lowerBound(d[i]);
        int upper = upperBound(d[i]);
        if(lower == upper) ans.push_back(0);
        else
            ans.push_back(upper-lower);
    }

    for(int i : ans){
        cout << i << " ";
    }

    return 0;
}
