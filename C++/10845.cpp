#include <iostream>
#include <cstring>
using namespace std;
int N,size=0;
int arr[10000];

void push(int a){
    arr[size] = a;
    size++;
}

void empty(){
   if(size){
       cout << 0 << '\n';
   } else {
       cout << 1 << '\n';
   }
}

void pop(){
    if(size){
        cout << arr[0] << '\n';
        for(int i=0;i<size;i++){
            arr[i] = arr[i+1];
        }
        size--;
    } else {
        cout << -1 << '\n';
    }
}

void qsize(){
    cout << size << '\n';
}

void front(){
    if(size){
        cout << arr[0] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

void back(){
    if(size){
        cout << arr[size-1] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    string str;
    cin >> N;
    while(N--){
        cin >> str;
        if(strcmp("push",str.c_str()) == 0){
            int a;
            cin >> a;
            push(a);
        } else if(strcmp("pop",str.c_str()) == 0){
            pop();
        } else if(strcmp("size",str.c_str()) == 0){
            qsize();
        } else if(strcmp("empty",str.c_str()) == 0){
            empty();
        } else if(strcmp("front",str.c_str()) == 0){
            front();
        } else if(strcmp("back",str.c_str()) == 0){
            back();
        }
    }

    return 0;
}
