#include <iostream>
#include <vector>
//#include <algorithm>

using ULL = unsigned long long;
using namespace std;

ULL nonrecursive_cmn(int m, int n) {
    if (n < 0 || n > m) return 0;
    if (n == 0 || m == n) return 1;
    if (n > m - n) n = m - n;

    ULL res = 1;
    for (int i = 1; i <= n; ++i) {
        res = res * (m - i + 1) / i;
    }
    return res;
};

// C(m, n) = C(m-1, n-1) + C(m-1, n)
ULL recursive_cmn(int m, int n) {
    if (n < 0 || n > m) return 0;
    if (n == 0 || m == n) return 1;
    return recursive_cmn(m - 1, n - 1) + recursive_cmn(m - 1, n);
};

// Pascal's Triangle
ULL dynamic_cmn(int m, int n) {
    static vector<vector<ULL>> v;   // (m + 1, vector<ULL>(n + 1, 0));
    static int max_m = -1;
    if (n < 0 || n > m) return 0;
    if (n == 0 || m == n) return 1;

    if (m <= max_m) return v[m][n];
    else {
        //v.resize(m, vector<ULL>(m, 0));
        for (int i = max_m + 1; i <= m; ++i) {
            v.push_back(vector<ULL>());
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i) {
                    v[i].push_back(1);
                }
                else {
                    v[i].push_back(v[i - 1][j - 1] + v[i - 1][j]);
                }
            }
        }
        max_m = m;
    }
    return v[m][n];
};

int main() {
    int m, n;
    while (cin >> m >> n) {
        cout << "Non-recursive CMN:\n" << nonrecursive_cmn(m, n) << "\n";
        cout << "Recursive CMN:\n" << recursive_cmn(m, n) << "\n";
        cout << "Dynamic CMN:\n" << dynamic_cmn(m, n) << "\n";
    }
    return 0;
};
