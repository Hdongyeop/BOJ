/*
 * TRIE 구조
 * 문자열을 빠르게 탐색하게 해주는 자료구조
 * 참고 : https://yabmoons.tistory.com/379
 */
#include <iostream>
#include <string>
#define N_MAX   10001
#define L_MAX   11
#define NODE_MAX    N_MAX * L_MAX
using namespace std;

struct TRIE{
    bool finish;
    TRIE* node[L_MAX];

    void Insert(char* Str);
    bool Call(char* Str);
};

int N, N_Idx;
char Phone[N_MAX][L_MAX];
string Answer;
TRIE *Root, Nodepool[NODE_MAX];

TRIE *Nodeset(){
    TRIE *NewNode = &Nodepool[N_Idx++];
    NewNode->finish = false;
    for(int i=0;i<L_MAX;i++)
        NewNode->node[i] = NULL;

    return NewNode;
}

void TRIE::Insert(char *Str) {
    if(*Str == NULL){
        finish = true;
        return;
    }

    int Cur = *Str - '0';
    if(node[Cur] == NULL) node[Cur] = Nodeset();
    node[Cur]->Insert(Str + 1);
}

bool TRIE::Call(char *Str) {
    if(*Str == NULL) return true;
    if(finish == true) return false;

    int Cur = *Str - '0';
    return node[Cur]->Call(Str + 1);
}

void Init(){
    N_Idx = 0;
    Root = Nodeset();
}

void Input(){
    cin >> N;
    for(int i=0;i<N;i++)
        cin >> Phone[i];
}

void Solution(){
    for(int i=0;i<N;i++)
        Root->Insert(Phone[i]);

    bool Flag = true;

    for(int i=0;i<N;i++){
        if(Flag == true) Flag = Root->Call(Phone[i]);
        if(Flag == false) break;
    }

    if(Flag == true) Answer = "YES";
    else Answer = "NO";
}

void Solve(){
    int Tc;
    cin >> Tc;
    for(int T=1;T<=Tc;T++){
        Init();
        Input();
        Solution();

        cout << Answer << '\n';
    }
}

int main() {
    Solve();

    return 0;
}
