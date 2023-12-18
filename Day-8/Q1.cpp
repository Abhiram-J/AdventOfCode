#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pii> vpi;
#define all(v) v.begin(), v.end()

const char newl = '\n';
const int N = 2e4 + 10;
const int mod = 1e9 + 7;
const ll inf = 2e18;

void solve() {
    string ins;
    cin >> ins;
    string temp;
    getline(cin, temp);
    getline(cin, temp);

    map<string, int> mp;
    int n = 0;
    vector<pair<string, string>> v(N);
    while (getline(cin, temp)) {
        string parent = temp.substr(0, 3);
        string left = temp.substr(7, 3);
        string right = temp.substr(12, 3);

        if (mp.find(parent) == mp.end()) {
            mp[parent] = n++;
        }
        if (mp.find(left) == mp.end()) {
            mp[left] = n++;
        }
        if (mp.find(right) == mp.end()) {
            mp[right] = n++;
        }
        v[mp[parent]] = {left, right};
    }
    n = ins.size();
    string curr = "AAA";
    for (int i = 0;; i++) {

        if (ins[i % n] == 'L') {
            curr = v[mp[curr]].first;
        } else {
            curr = v[mp[curr]].second;
        }
        if (curr == "ZZZ") {
            cout << i + 1;
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
