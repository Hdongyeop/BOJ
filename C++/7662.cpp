#include <iostream>
#include <set>
using namespace std;

int main(){
    int T;
    cin >> T;

    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        multiset<int> s;

        for(int j=0;j<N;j++){
            char c;
            int num;
            cin >> c >> num;

            if(c == 'I')
                s.insert(num);
            else {
                if(!s.empty()){
                    if(num == 1){
                        auto it = s.end();
                        it--;
                        s.erase(it);
                    } else
                        s.erase(s.begin());
                }
            }
        }

        if(s.empty())
            cout << "EMPTY\n";
        else {
            auto it = s.end();
            it--;
            cout << *it << " " << *s.begin() << '\n';
        }
    }
    return 0;
}