#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
char arr[51][51];
char comp1[8][8] = {{'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'}
};
char comp2[8][8] = {{'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'},
                    {'B','W','B','W','B','W','B','W'},
                    {'W','B','W','B','W','B','W','B'}
};

int compare(char c1[8][8], char c2[8][8]){
    int cnt = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(c1[i][j] != c2[i][j]){
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int ans=987654321;
    cin >> N >> M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    char n_arr[8][8];

    for(int i=0;i<N-8+1;i++){
        for(int j=0;j<M-8+1;j++){
            int y=0;
            for(int k=i;k<i+8;k++){
                int x = 0;
                for(int m=j;m<j+8;m++){
                    n_arr[y][x] = arr[k][m];
                    x++;
                }
                y++;
            }

            int tmp = compare(comp1,n_arr);
            int tmp2 = compare(comp2,n_arr);

            ans = min(min(ans,tmp2),tmp);
        }
    }

    cout << ans;
    return 0;
}
