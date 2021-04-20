#include <iostream>
using namespace std;

class NODE {
    string value;
    NODE *left,*right;

public:
    NODE() {
        value = "";
        left = NULL;
        right = NULL;
    }

    void setValue(char value) { this->value = value;}
    void setLeft(NODE *left) {this->left = left;}
    void setRight(NODE *right) {this->right = right;}

    //전위
    static void preorder(NODE *node){
        if(node){
            cout << node->value;
            preorder(node->left);
            preorder(node->right);
        }
    }

    //중위
    static void inorder(NODE *node){
        if(node){
            inorder(node->left);
            cout << node->value;
            inorder(node->right);
        }
    }

    //후위
    static void postorder(NODE *node){
        if(node){
            postorder(node->left);
            postorder(node->right);
            cout << node->value;
        }
    }
};

int main(){
    int N;
    cin >> N;

    NODE* node = new NODE[N];

    for(int i=0;i<N;i++){
        char value, left, right;
        cin >> value >> left >> right;

        if(value != '.')
            node[(int)(value-'A')].setValue(value);

        if(left != '.')
            node[(int)(value-'A')].setLeft(&node[(int)(left-'A')]);
        else
            node[(int)(value-'A')].setLeft(NULL);

        if(right != '.')
            node[(int)(value-'A')].setRight(&node[(int)(right-'A')]);
        else
            node[(int)(value-'A')].setRight(NULL);
    }

    NODE* root = &node[0];

    NODE::preorder(root);
    cout << endl;
    NODE::inorder(root);
    cout << endl;
    NODE::postorder(root);
    cout << endl;
}