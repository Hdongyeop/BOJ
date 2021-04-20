#include <iostream>
#include <algorithm>
#include <climits> //LLONG_MAX
using namespace std;

const int MAX = 100000;
int N, idx1, idx2;
long long minimum;
long long liquid[MAX];

void print2Liquid(void)
{
    int i = 0, j = N - 1;
    while (i < j)
    {
        long long sum = liquid[i] + liquid[j];
        //최소값 갱신 때마다 idx1~idx2 초기화
        if (llabs(sum) < minimum)
        {
            minimum = llabs(sum);

            idx1 = i;
            idx2 = j;
        }
        //오름차순 정렬했으므로
        if (sum < 0)
            i++;
        else
            j--;
    }
    cout << liquid[idx1] << " " << liquid[idx2] << endl;
}

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> liquid[i];

    sort(liquid, liquid + N);

    minimum = LLONG_MAX;
    print2Liquid();
    return 0;
}
