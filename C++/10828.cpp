#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<int> result;

void push(int x){
    v.push_back(x);
}

void pop(){
    if(!v.empty()){
        result.push_back(v.back());
        v.pop_back();
    } else
        result.push_back(-1);
}

void size(){
    //cout << v.size() << '\n';
    result.push_back(v.size());
}

void empty(){
    if(v.empty())
        //cout << 1 << '\n';
        result.push_back(1);
    else
        //cout << 0 << '\n';
        result.push_back(0);
}

void top(){
    if(!v.empty()){
        //cout << v.back() << '\n';
        result.push_back(v.back());
    } else
        //cout << -1 << '\n';
        result.push_back(-1);
}

int main() {
    int N;
    int param = 0;
    string str;
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> str;
        if(str == "push"){
            cin >> param;
            push(param);
        } else if(str == "pop")
            pop();
        else if(str == "size")
            size();
        else if(str == "empty")
            empty();
        else if(str == "top")
            top();
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << '\n';
    }

    return 0;
}
