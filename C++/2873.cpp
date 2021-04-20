/*
 * REF : https://jaimemin.tistory.com/729
 */
#include <iostream>
using namespace std;
int R,C;
int arr[1001][1001];

void func_F(int n,char c){
    for(int i=0;i<n;i++)
        printf("%c",c);
}

int main() {
    cin >> R >> C;
    for(int i=1;i<=R;i++)
        for(int j=1;j<=C;j++)
            cin >> arr[i][j];

    if(R%2 == 1 && C%2 == 1){
        //case 1 홀/홀
        for(int i=1;i<=R;i++){
            if(i%2 == 1)
                func_F(C-1,'R');
            else
                func_F(C-1,'L');

            if(i != R)
                printf("%c",'D');
        }
    } else if(R%2 == 1 && C%2 == 0){
        //case 2 홀/짝
        for(int i=1;i<=R;i++){
            if(i%2 == 1)
                func_F(C-1,'R');
            else
                func_F(C-1,'L');

            if(i != R)
                printf("%c",'D');
        }
    } else if(R%2 == 0 && C%2 == 1) {
        //case 2 짝/홀
        for(int i=1;i<=C;i++){
            if(i%2 == 1)
                func_F(R-1,'D');
            else
                func_F(R-1,'U');

            if(i != C)
                printf("%c",'R');
        }
    } else {
        //case 3 짝/짝
        pair<int,int> pos;
        int min = 2e9+1;
        for(int i=1;i<=R;i++)
            for(int j=1;j<=C;j++)
                if((i+j)%2 == 1 && arr[i][j] < min){
                    min = arr[i][j];
                    pos.first = i;
                    pos.second = j;
                }

        int newR = pos.first % 2 ? pos.first : pos.first-1;
        //                            홀            짝
        for(int i=1;i<newR;i++){
            for(int j=1;j<=C-1;j++){
                if(i%2 == 1)
                    printf("%c",'R');
                else
                    printf("%c",'L');
            }
            printf("%c",'D');
        }

        int newC = pos.second;
        for(int j=1;j<newC;j++){
            if(j % 2 == 1)
                printf("%s","DR");
            else
                printf("%s","UR");
        }

        for(int j=newC;j<=C-1;j++){
            if(j%2 == 1)
                printf("%s","RD");
            else
                printf("%s","RU");
        }

        if(pos.first % 2 == 1)
            newR = pos.first + 2;
        else
            newR = pos.first + 1;

        for(int i=newR;i<=R;i++){
            printf("%c",'D');
            for(int j=1;j<=C-1;j++){
                if(i%2 == 1)
                    printf("%c",'L');
                else
                    printf("%c",'R');
            }
        }
    }

    return 0;
}