#include <iostream>
using namespace std;
/*
 * bitset STL을 사용하면 된다.
 */
int main() {
    int n;
    scanf("%d",&n);
    char tmp[10];
    string str;
    unsigned int m,bm=0;

    for(int i=0;i<n;i++){
        scanf("%s",tmp);
        str = tmp;
        if(!str.compare("add")){
            scanf("%d",&m);
            bm |= (1<<(m-1));
        } else if(!str.compare("remove")){
            scanf("%d",&m);
            bm &= ~(1<<(m-1));
        } else if(!str.compare("check")){
            scanf("%d",&m);
            if(bm & (1<<(m-1))) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if(!str.compare("toggle")){
            scanf("%d",&m);
            bm ^= (1<<(m-1));
        } else if(!str.compare("all")){
            bm = (1<<20)-1;
        } else if(!str.compare("empty")){
            bm = 0;
        }
    }
    return 0;
}
