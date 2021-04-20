#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

struct WORD {
    int length;
    char arr[51];
};

bool comp(const WORD &s1, const WORD &s2){
    if(s1.length == s2.length){
        for(int i=0;i<s1.length;i++){
            if(s1.arr[i] == s2.arr[i]) continue;
            else if(s1.arr[i] < s2.arr[i]) return true;
            else return false;
        }
    }
    return s1.length < s2.length;
}

int main() {
    int n;
    cin >> n;

    WORD *word = new WORD[n];

    for(int i=0;i<n;i++){
        cin >> word[i].arr;
        word[i].length = strlen(word[i].arr);
    }

    sort(word,word+n,comp);

    for(int i=0;i<n;i++){
        if(i!=0){
            if(!strcmp(word[i].arr,word[i-1].arr))
                continue;
        }
        cout << word[i].arr << '\n';
    }

    delete[] word;
    return 0;
}
