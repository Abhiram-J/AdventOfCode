#include <bits/stdc++.h>
using namespace std;
// #define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
#define all(v) v.begin(), v.end()

const char newl = '\n';
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const ll inf = 2e18;

void solve() {
    string t;
    int sum = 0;
    while (getline(cin, t)) {
        string s = t;
        int first = -1, second = -1;
        for (int j = 0; j < s.size(); j++) {
            if ((s[j] >= '0' && s[j] <= '9')) {
                if (first == -1) {
                    first = j;
                    second = j;
                } else {
                    second = j;
                }
            }
        }
        int a, b;
        a = (s[first] - '0');

        b = (s[second] - '0');
        sum += a * 10 + b;
    }
    cout << sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
