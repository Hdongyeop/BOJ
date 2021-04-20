#include <iostream>
#include <vector>
using namespace std;

vector<char> v;
int N;

int main() {
    cin >> N;
    for(int i=0;i<N;i++){
        string str;
        cin >> str;
        const char* arr = new char[str.size()];
        arr = str.c_str();
        for(int i=0;i<str.size();i++){
            v.push_back(arr[i]);
            if(v[v.size()-1] == ')' && v[v.size()-2] == '('){
                v.pop_back();
                v.pop_back();
            }
        }

        if(v.empty())
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

        v.clear();
    }

    return 0;
}
