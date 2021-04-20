#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

int main(){
    char c;
    while(1){
        stack<char> s;
        char text[100];
        scanf("%[^\n]%*c",&text);
        if(text[0] == '.') break;

        for(int i=0;i<strlen(text)+1;i++){
            if(text[i] == '(' || text[i] == '[') s.push(text[i]);

            if(text[i] == ')' || text[i] == ']') {
                if(s.empty()){
                    s.push('X');
                    break;
                }

                if((s.top() == '(' && text[i] == ')') || (s.top() == '[' && text[i] == ']')) s.pop();
                else {
                    s.push('X');
                    break;
                }
            }
        }

        if(s.empty()) cout << "yes\n";
        else cout << "no\n";
    }
}