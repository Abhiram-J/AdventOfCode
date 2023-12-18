#include <bits/stdc++.h>
using namespace std;
#define int long long

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
vector<int> splitString(string& inputString) {
    istringstream iss(inputString);
    vector<int> result;

    string word;
    while (iss >> word) {
        result.push_back(stoi(word));
    }

    return result;
}
void solve() {
    int ans = 0;
    string s;
    while (getline(cin, s)) {
        vector<int> old = splitString(s);
        vector<int> curr, last;

        for (bool allZero = false; !allZero; old = curr, curr.clear()) {
            allZero = true;
            for (int i = 1; i < old.size(); i++) {
                curr.push_back(old[i] - old[i - 1]);
                if (curr.back() != 0) allZero = false;
            }
            last.push_back(old[0]);
        }
        int val = 0;
        for (int i = last.size() - 1; i >= 0; i--) {
            val = last[i] - val;
        }
        ans += val;
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
