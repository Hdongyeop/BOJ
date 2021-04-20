#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#define MAX     10001

using namespace std;

class NODE{
public:
    int value;
    int level;
    NODE *left, *right, *parent;

    NODE(){
        value = 0;
        level = 1;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};

NODE node[MAX];
vector<pair<int,int>> v;
int N;
int level = 0;
int ab_level = 0;
int cnt = 0;

void function(int a, int b, int c){
    node[a].value = a;

    if(b != -1){
        node[a].left = &node[b];
        node[b].parent = &node[a];
    }
    else
        node[a].left = NULL;

    if(c != -1){
        node[a].right = &node[c];
        node[c].parent = &node[a];
    }
    else
        node[a].right = NULL;
}

void DFS(int n){
        ab_level++;
        level++;
        node[n].level = level;
        if(node[n].left != NULL)
            DFS(node[n].left->value);
        cnt++;
        v.push_back(make_pair(level,cnt));
        if(node[n].right != NULL)
            DFS(node[n].right->value);
        level--;
}

int main() {
    int maxLength = 0;
    int maxLevel = 0;
    int root = 0;
    bool DO = true;
    cin >> N;

    memset(node,0,sizeof(node));

    // 입력받으면서 node 채우기
    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;
        function(a,b,c);
    }

    // root 찾기
    int i = 0;
    while(DO){
        i++;
        if(node[i].value != 0 && node[i].parent == NULL){
            root = node[i].value;
            DO = false;
        }
    }

    // vector v 채우기, first = level
    DFS(root);
    // vector<pair<int,int>> 의 경우 sort는 first를 기준으로 sorting된다.
    sort(v.begin(), v.end());
    for(int i=1;i<=v.back().first;i++){
        vector<pair<int,int>> tmp = v;
        vector<pair<int,int>> tmp2;
        for(int j=0;j<cnt;j++){
            if(tmp[j].first == i){
                tmp2.push_back(make_pair(tmp[j].first, tmp[j].second));
            }
        }
        sort(tmp2.begin(), tmp2.end());
        int length = tmp2.back().second - tmp2.front().second + 1;
        if(length > maxLength){
            maxLength = length;
            maxLevel = i;
        }
    }

    cout << maxLevel << " " << maxLength;
    return 0;
}
