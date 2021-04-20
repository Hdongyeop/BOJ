#include <iostream>
#include <algorithm>
using namespace std;

struct MEM {
    int age;
    int order;
    string name;
};

bool comp(const MEM &m1, const MEM &m2){
    if(m1.age == m2.age){
        if(m1.order < m2.order) return true;
        else return false;
    }
    return m1.age < m2.age;
}

int main() {
    int n,cnt=0;
    cin >> n;

    MEM *mem = new MEM[n];

    for(int i=0;i<n;i++){
        cnt++;
        cin >> mem[i].age >> mem[i].name;
        mem[i].order = cnt;
    }

    sort(mem,mem+n,comp);

    for(int i=0;i<n;i++){
        cout << mem[i].age << " " << mem[i].name << '\n';
    }

    delete[] mem;
    return 0;
}
