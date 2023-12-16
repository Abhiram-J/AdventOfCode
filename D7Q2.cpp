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
map<char, int> p;

int findPoint(string s) {
    map<char, int> m;
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != 'J') {
            m[s[i]]++;
        } else {
            j++;
        }
    }
    int maxi = 0;
    int smaxi = 0;
    for (auto it : m) {
        if (it.second >= maxi) {
            smaxi = maxi;
            maxi = it.second;
        } else if (it.second >= smaxi) {
            smaxi = it.second;
        }
    }
    maxi += j;
    if (maxi == 5) {
        return 0;
    } else if (maxi == 4) {
        return 1;
    } else if (maxi == 3) {
        return smaxi == 2 ? 2 : 3;
    } else if (maxi == 2) {
        return smaxi == 2 ? 4 : 5;
    } else {
        return 6;
    }
}

bool comparatorFunc(string a, string b) {
    for (int i = 0; i < a.size(); i++) {
        if (p[a[i]] > p[b[i]]) {
            return false;
        } else if (p[a[i]] < p[b[i]]) {
            return true;
        }
    }
    return false;
}

void solve() {
    string input;
    vector<pair<string, int>> v;
    while (getline(cin, input)) {
        string card = input.substr(0, input.find(" "));
        int value = stoi(input.substr(input.find(" ") + 1));
        v.push_back({card, value});
    }
    sort(all(v));

    vector<vector<string>> hands(7);
    for (int i = 0; i < v.size(); i++) {
        int point = findPoint(v[i].first);
        hands[point].push_back(v[i].first);
    }

    for (int i = 0; i < hands.size(); i++) {
        if (hands[i].size() > 1) {
            sort(all(hands[i]), comparatorFunc);
        }
    }

    int rank = 1;
    map<string, int> ranks;
    for (int i = hands.size() - 1; i >= 0; i--) {
        for (int j = hands[i].size() - 1; j >= 0; j--) {
            ranks[hands[i][j]] = rank;
            cerr << hands[i][j] << " " << rank << endl;
            rank++;
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        ans += ranks[v[i].first] * v[i].second;
    }

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    p['A'] = 0;
    p['K'] = 1;
    p['Q'] = 2;
    p['T'] = 4;
    p['9'] = 5;
    p['8'] = 6;
    p['7'] = 7;
    p['6'] = 8;
    p['5'] = 9;
    p['4'] = 10;
    p['3'] = 11;
    p['2'] = 12;
    p['J'] = 13;

    solve();

    return 0;
}
