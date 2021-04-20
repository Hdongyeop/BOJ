#include <iostream>
#include <vector>
#define MOD     1000
using namespace std;
int A;
long long B;
/*
 * 비트의 자리수 구하기
 */
template <typename T>
int binary_len(T n) {
    long long power_of_2 = 1;
    int ret = 0;
    while (power_of_2 <= n)power_of_2 <<= 1, ++ret;
    return ret;
}
/*
 * 비트 역으로 뒤집기
 */
template <typename T>
T bit_reverse(T n) {
    T ret = 0;
    while (n) {
        ret <<= 1;
        ret |= n & 1;
        n >>= 1;
    }
    return ret;
}

vector<vector<int> > mat_mul(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, int mod) {
    int m = matrix_A.size();
    vector<vector<int> > ret(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                ret[i][j] += ((long long)matrix_A[i][k] * matrix_B[k][j]) % mod;
                ret[i][j] %= mod;
            }
        }
    }
    return ret;
}

vector<vector<int> > matrix_power_N(vector<vector<int> > matrix, long long N, int mod, bool print) {
    int m = matrix.size(), len = binary_len(N);
    vector<vector<int> > original = matrix;
    vector<vector<int> > ret = vector<vector<int> >(m, vector<int>(m));
    for (int i = 0; i < m; i++)
        ret[i][i] = 1;

    N = bit_reverse(N);
    while (len--) {
        ret = mat_mul(ret, ret, mod);
        if (N & 1) {
            ret = mat_mul(ret, original, mod);
        }
        N >>= 1;
    }
    if (print) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++)
                cout << ret[i][j] << " ";
            cout << '\n';
        }
    }
    return ret;
}

vector<vector<int> > matrix_plus(vector<vector<int> > matrix_A, vector<vector<int> > matrix_B, int mod){
    int m = matrix_A.size();
    vector<vector<int> > ret (m,vector<int>(m));
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            ret[i][j] = matrix_A[i][j] + matrix_B[i][j];
            ret[i][j] %= mod;
        }
    }
    return ret;
}

int main() {
    cin >> A >> B;

    vector<vector<int> > original = vector<vector<int> >(A, vector<int>(A));
    for (int i = 0; i < A; i++)
        for (int j = 0; j < A; j++)
            cin >> original[i][j];

    vector<vector<int> > ans = original;
    vector<vector<int> > ret = original;
    for(long long i=1;i<B;i++){
        ans = mat_mul(ans,original,MOD);
        ret = matrix_plus(ret, ans, MOD);
    }

    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++)
            cout << ret[i][j] << " ";
        cout << '\n';
    }

    return 0;

}