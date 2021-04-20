#include <iostream>
#include <string>
using namespace std;

int N,M;

struct TRIE {
    bool finish;
    TRIE* node[26];
    TRIE(){
        finish = false;
        for(int i=0;i<26;i++) node[i] = NULL;
    }
    void Insert(char* Str);
    bool Find(char* Str);
};

void TRIE::Insert(char *Str) {
    if(*Str == NULL){
        finish = true;
        return;
    }

    int Cur = *Str - 'a';
    if(node[Cur] == NULL)
        node[Cur] = new TRIE();
    node[Cur]->Insert(Str + 1);
}

bool TRIE::Find(char *Str) {
    if(*Str == NULL){
        if(finish == true) return true;
        return false;
    }
    int Cur =
            *Str - 'a';
    if(node[Cur] == NULL) return false;
    return node[Cur]->Find(Str + 1);
}

int main() {
    cin >> N >> M;
    int cnt=0;
    TRIE *ROOT = new TRIE();
    char *Str = new char[500];

    for(int i=0;i<N;i++){
        cin >> Str;
        ROOT->Insert(Str);
    }

    for(int i=0;i<M;i++){
        cin >> Str;
        if(ROOT->Find(Str)) cnt++;
    }

    cout << cnt;
    return 0;
}
