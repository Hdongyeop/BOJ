#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct POKETMON {
    string name;
    int index;
};

vector<POKETMON> v_dic;
vector<POKETMON> v_dig;

bool comp_dic(POKETMON a, POKETMON b){
    return a.name < b.name;
}

bool comp_dig(POKETMON a, POKETMON b){
    return a.index < b.index;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        POKETMON p;
        cin >> p.name;
        p.index = i+1;
        v_dic.push_back(p);
        v_dig.push_back(p);
    }

    sort(v_dic.begin(),v_dic.end(),comp_dic);
    sort(v_dig.begin(),v_dig.end(),comp_dig);

    for(int i=0;i<m;i++){
        string tmp;
        int l,h,mid;
        cin >> tmp;
        if(isdigit(tmp[0])){
            int x = atoi(tmp.c_str());
            l=0; h=n-1;

            while(l <= h){
                mid = (l+h)/2;
                if(v_dig[mid].index == x){
                    cout << v_dig[mid].name << '\n';
                    break;
                } else if(v_dig[mid].index < x)
                    l = mid + 1;
                else h = mid - 1;
            }
        } else {
            l=0; h=n-1;

            while(l <= h){
                mid = (l+h)/2;
                if(v_dic[mid].name == tmp){
                    cout << v_dic[mid].index << '\n';
                    break;
                } else if(v_dic[mid].name < tmp)
                    l = mid + 1;
                else h = mid - 1;
            }
        }
    }

    return 0;
}
