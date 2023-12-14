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
map<string, int> m;
bool num(string s, int idx) {
    for (int len = 1; len < s.size() - idx + 1; len++) {
        if (m[s.substr(idx, len)]) {
            return true;
        }
    }
    return false;
}

int findNUm(string s, int idx) {
    for (int len = 1; len < s.size() - idx + 1; len++) {
        if (m[s.substr(idx, len)]) {
            return m[s.substr(idx, len)];
        }
    }
}

void solve() {
    string t;
    int sum = 0;
    while (getline(cin, t)) {
        string s = t;
        int first = -1, second = -1;
        for (int j = 0; j < s.size(); j++) {
            if ((s[j] >= '0' && s[j] <= '9') || num(s, j)) {
                if (first == -1) {
                    first = j;
                    second = j;
                } else {
                    second = j;
                }
            }
        }
        int a, b;
        if (s[first] >= '0' && s[first] <= '9') {
            a = (s[first] - '0');
        } else {
            a = findNUm(s, first);
        }

        if (s[second] >= '0' && s[second] <= '9') {
            b = (s[second] - '0');
        } else {
            b = findNUm(s, second);
        }
        sum += a * 10 + b;
    }
    cout << sum;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;

    solve();

    return 0;
}
