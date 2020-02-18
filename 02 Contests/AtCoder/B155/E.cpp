#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cout << #x << " => " << x << "\n"
#define deba(x) cout << #x << "\n"; for (auto a : x) cout << a << " "; cout << "\n";
#define debm(x) cout << #x << "\n"; for (auto a : x){for(auto b : a) cout << b << " "; cout << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)

int32_t main() { fastio;
    string s; cin >> s;
    int sum = 0;
    int n = s.length();
    int carry_back = 0;
    for (int i = n - 1; i >= 0; i--) {
        int x = s[i] - '0';
        if ((x + carry_back) < (11 - x - carry_back)) {
            sum += x + carry_back;
            carry_back = 0;
        } else {
            sum += 10 - x - carry_back;
            carry_back = 1;
        }
    }
    sum += carry_back;
    cout << sum << endl;
    return 0;
}