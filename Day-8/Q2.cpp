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
    vector<string> curr;
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

        if (parent[2] == 'A') {
            curr.push_back(parent);
        }
    }

    n = ins.size();
    vector<int> dists(6);
    for (int i = 0; i < 1000000; i++) {
        bool left = true;
        if (ins[i % n] == 'R') left = false;
        for (int j = 0; j < curr.size(); j++) {
            if (left) {
                curr[j] = v[mp[curr[j]]].first;
            } else {
                curr[j] = v[mp[curr[j]]].second;
            }
            if (curr[j][2] == 'Z') {
                if (dists[j] == 0) dists[j] = i + 1;
            }
        }
        cout << newl;
        bool flag = true;
        for (int j = 0; j < 6; j++) {
            if (dists[j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }
    ll lcm = 1;
    for (int i = 0; i < 6; i++) {
        lcm = lcm * dists[i] / __gcd(lcm, (ll)dists[i]);
    }
    cout << lcm;
}

int32_t main() {
    ios_base::sync_with_stdio(false);

    solve();
    return 0;
}
