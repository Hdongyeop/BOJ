#include <iostream>
using namespace std;

int weight[50] = {0};
int hight[50] = {0};
int main() {
    int N;
    cin >> N;
    int rank;

    for (int i = 0; i < N; i++)
        cin >> weight[i] >> hight[i];

    for (int i = 0; i < N; i++) {
        rank = 0;
        for (int j = 0; j < N; j++) {
            if ((weight[i] < weight[j]) && (hight[i] < hight[j]))
                rank++;
        }
        cout << rank+1 << " ";
    }

    return 0;
}