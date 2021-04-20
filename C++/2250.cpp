#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

queue<int> q;

class NODE {
    int value;
    int level;
    NODE *left,*right;

public:
    NODE() {
        value = 0;
        level = 1;
        left = NULL;
        right = NULL;
    }

    void setValue(int value) { this->value = value;}
    void setLeft(NODE *left) {
        this->left = left;
        if(left != NULL) left->level = getLevel() + 1;
    }
    void setRight(NODE *right) {
        this->right = right;
        if(right != NULL) right->level = getLevel() + 1;
    }

    int getLevel(){
        return this->level;
    }

    int getValue(){
        return this->value;
    }

    NODE *getLeft(){
        return left;
    }

    NODE *getRight(){
        return right;
    }

    //중위
    static void inorder(NODE *node){
        if(node){
            inorder(node->left);
            q.push(node->value);
            inorder(node->right);
        }
    }
};

int main() {
    int N;
    int maxLength=0;
    int maxLevel = 0;
    cin >> N;

    NODE *node = new NODE[N+1];

    for(int i=0;i<N;i++){
        int a,b,c;
        cin >> a >> b >> c;

        // value
        node[a].setValue(a);
        // Left
        if(b != -1)
            node[a].setLeft(&node[b]);
        else
            node[a].setLeft(NULL);
        // Right
        if(c != -1)
            node[a].setRight(&node[c]);
        else
            node[a].setRight(NULL);
    }

    NODE *root;
    for(int i=1;i<N+1;i++){
        int cnt = 0;
        for(int j=1;j<N+1;j++){
            if(node[j].getLeft() == &node[i] || node[j].getRight() == &node[i]){
                cnt++;
            }
        }
        if(cnt == 0) root = &node[i];
    }

    NODE::inorder(root);

    // Matrix 생성
    int col = node[q.size()].getLevel();
    int row = q.size();

    int **matrix = new int*[col+1];
    for(int i=0; i <= col; i++){
        matrix[i] = new int[row+1];
    }

    for(int i=0;i<=col;i++){
        memset(matrix[i],0,(row+1) * sizeof(matrix[i]));
    }

    // Matrix에 집어넣기
    for(int i=1;i<=row;i++){
        int mLevel = node[q.front()].getLevel();
        matrix[mLevel][i] = i;
        q.pop();
    }

    // 최대 너비 구하기
    for(int i=1;i<=col;i++){
        int row_max=0;
        int row_min=10001;

        for(int j=1;j<=row;j++){
            if(matrix[i][j] > row_max) row_max = matrix[i][j];
            if(matrix[i][j] < row_min && matrix[i][j] != 0) row_min = matrix[i][j];
            else
                continue;
        }

        int Length = 0;

        if(row_min == row_max){
            Length = 1;
        } else {
            Length = row_max - row_min + 1;
        }

        if(Length >= maxLength) {
            if(Length != maxLength){
                maxLevel = i;
            }
            maxLength = Length;
        }
    }

    cout << maxLevel << " " << maxLength;
    return 0;
}
