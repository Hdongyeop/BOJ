#include <iostream>
using namespace std;
int main() {
    while(1){
        int cnt=0;
        string str;
        cin >> str;
        if(str == "0") break;
        const char *c = str.c_str();

        for(int i=0;i<str.size()/2;i++){
            if(c[i] == c[str.size()-1-i]) cnt++;
        }

        if(str.size()/2 == cnt) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
    return 0;
}
