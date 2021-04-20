#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int cnt=0;

typedef struct node{
    int data;
    node* left;
    node* right;
}node;

node* firstnode;

void insert(int num){
    node* newnode = new node[1];

    newnode->data = num;
    newnode->left = NULL;
    newnode->right = NULL;

    if(cnt == 0){
        firstnode = newnode;
    } else {
        node* temp = firstnode;

        while(1){
            if(temp->data < num){
                if(temp->right == NULL){
                    temp->right = newnode;
                    break;
                }
                temp = temp->right;
            }
            else if(temp->data > num){
                if(temp->left == NULL){
                    temp->left = newnode;
                    break;
                }
                temp = temp->left;
            }
        }
    }
    cnt++;
    return;
}

void postorder(node* tmp){
    if(tmp){
        postorder(tmp->left);
        postorder(tmp->right);
        cout << tmp->data << '\n';
    }
}

int main() {
    int num;

    while(cin >> num){
        v.push_back(num);
    }

    for(int i=0;i<v.size();i++){
        insert(v[i]);
    }

    postorder(firstnode);
}
