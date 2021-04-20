#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M,B;
vector<pair<int,int>> v;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second > b.second;
    } else return a.first < b.first;
}

int main() {
    cin >> N >> M >> B;

    int arr[N][M];
    int sum = B;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    int max_height = sum / (N*M);

    for(int k=0;k<=max_height;k++){
        int time=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(arr[i][j] == k) continue;
                else{
                    if(arr[i][j] > k){
                        int x = arr[i][j] - k;
                        time += x*2;
                    } else {
                        int x = k - arr[i][j];
                        time += x;
                    }
                }
            }
        }
        v.push_back({time,k});
    }

    sort(v.begin(),v.end(),comp);

    cout << v.front().first << " " << v.front().second << '\n';

    return 0;
}
