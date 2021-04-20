#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int N,M;
int matrix[8][8];
int visited[8][8];
int tmp[8][8];
int tmp2[8][8];
int tmp3[8][8];
int virus_count=0;
int ad[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<pair<int,int>> virus_xy;

void DFS(int y, int x){
    for(int i=0;i<4;i++){
        int Dy = y + ad[i][0];
        int Dx = x + ad[i][1];
        if(Dy < 0 || Dx < 0 || Dy >= N || Dx >= M)
            continue;
        if(tmp3[Dy][Dx] == 0 && !visited[Dy][Dx]){
            visited[Dy][Dx] = 1;
            tmp3[Dy][Dx] = 2;
            DFS(Dy,Dx);
        }
    }
}

int main() {
    int result=0;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 2){
                //push_back와 다르게 임시 객체를 만들지 않는다 ( virus_xy.push_back(make_pair(i,j)) )
                virus_xy.emplace_back(i,j);
                virus_count++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            // 첫번째 상태 저장
            memcpy(tmp,matrix,sizeof(matrix));
            if(tmp[i][j] != 0)
                continue;
            tmp[i][j] = 1;

            for(int k=0;k<N;k++){
                for(int m=0;m<M;m++){
                    // 두번째 상태 저장
                    memcpy(tmp2,tmp,sizeof(tmp));
                    if(tmp2[k][m] != 0)
                        continue;
                    tmp2[k][m] = 1;

                    for(int n=0;n<N;n++){
                        for(int o=0;o<M;o++){
                            // 세번째 상태 저장
                            memcpy(tmp3,tmp2,sizeof(tmp2));
                            if(tmp3[n][o] != 0)
                                continue;
                            tmp3[n][o] = 1;

                            // 바이러스 퍼뜨리기
                            for(int l=0;l<virus_count;l++){
                                //방문 정보 삭제
                                memset(visited,0,sizeof(visited));
                                DFS(virus_xy[l].first,virus_xy[l].second);
                            }

                            // 바이러스가 퍼진 후 0의 개수 세기
                            int zero_cnt=0;
                            for(int a=0;a<N;a++){
                                for(int b=0;b<M;b++){
                                    if(tmp3[a][b] == 0)
                                        zero_cnt++;
                                }
                            }
                            // 0의 개수가 최대인 경우 구하기
                            if(zero_cnt > result) result = zero_cnt;
                        }
                    }
                }
            }
        }
    }

    cout << result;
    return 0;
}
