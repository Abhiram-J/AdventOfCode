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
bool isSymbol(char c) { return !(c >= '0' && c <= '9' || c == '.'); }
bool check(vector<string>& grid, int i, int j) {
    if (i - 1 >= 0 && j - 1 >= 0 && isSymbol(grid[i - 1][j - 1])) return true;
    if (i - 1 >= 0 && isSymbol(grid[i - 1][j])) return true;
    if (i - 1 >= 0 && j + 1 < grid[i].size() && isSymbol(grid[i - 1][j + 1]))
        return true;
    if (j + 1 < grid[i].size() && isSymbol(grid[i][j + 1])) return true;
    if (i + 1 < grid.size() && j + 1 < grid[i].size() &&
        isSymbol(grid[i + 1][j + 1]))
        return true;
    if (i + 1 < grid.size() && isSymbol(grid[i + 1][j])) return true;
    if (i + 1 < grid.size() && j - 1 >= 0 && isSymbol(grid[i + 1][j - 1]))
        return true;
    if (j - 1 >= 0 && isSymbol(grid[i][j - 1])) return true;
    return false;
}

void dfs(vector<string>& grid, int i, int j, bool& flag) {
    if (flag) {
        return;
    }
    if (check(grid, i, j)) {
        flag = true;
        return;
    }
    if (j + 1 < grid[i].size() && grid[i][j + 1] >= '0' &&
        grid[i][j + 1] <= '9')
        dfs(grid, i, j + 1, flag);
}

void solve() {
    vector<string> grid;
    string s;
    while (getline(cin, s)) {
        grid.push_back(s);
    }
    int ans = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            if (grid[i][j] >= '0' && grid[i][j] <= '9') {
                string num = "";
                bool flag = false;
                dfs(grid, i, j, flag);

                if (flag) {
                    for (int k = j; k < grid[i].size(); k++) {
                        if (grid[i][k] >= '0' && grid[i][k] <= '9') {
                            num += grid[i][k];
                            grid[i][k] = '.';
                        } else {
                            break;
                        }
                    }
                }
                if (num.size() > 0) ans += stoi(num);
            }
        }
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
