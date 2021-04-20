#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, temp;
queue<int> q;
stack<int> s;
queue<char> ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        q.push(temp);
    }
    int l = 1;
    while (q.size()) {
        if (s.size() && s.top() == q.front()) {
            s.pop();
            q.pop();
            ans.push('-');
        }
        else if (l <= q.front()) {
            while (l <= q.front()) {
                s.push(l++);
                ans.push('+');
            }
        }
        else {
            printf("NO");
            return 0;
        }
    }
    while (ans.size()) {
        cout << ans.front() << '\n';
        ans.pop();
    }
    return 0;
}
