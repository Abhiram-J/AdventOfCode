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

vector<int> dx = {0, 1, -1};
vector<int> dy = {1, -1, 0};

int findNum(vector<string>& grid, int i, int j) {
    string num = "";
    for (int k = j; k < grid[i].size(); k++) {
        if (grid[i][k] >= '0' && grid[i][k] <= '9') {
            num.push_back(grid[i][k]);
            grid[i][k] = '.';
        } else {
            break;
        }
    }
    reverse(num.begin(), num.end());
    for (int k = j - 1; k >= 0; k--) {
        if (grid[i][k] >= '0' && grid[i][k] <= '9') {
            num.push_back(grid[i][k]);
            grid[i][k] = '.';
        } else {
            break;
        }
    }
    reverse(num.begin(), num.end());
    return stoi(num);
}

bool valid(vector<string>& grid, int i, int j) {
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size()) return false;
    return true;
}

void dfs(vector<string>& grid, int i, int j, vector<int>& nums) {
    if (valid(grid, i, j) && grid[i][j] >= '0' && grid[i][j] <= '9') {
        int num = findNum(grid, i, j);
        nums.push_back(num);
        return;
    }
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
            vector<int> nums;
            if (grid[i][j] == '*') {
                string num = "";
                bool flag = false;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (dx[k] == 0 && dy[l] == 0) continue;
                        dfs(grid, i + dx[k], j + dy[l], nums);
                    }
                }
                if (nums.size() == 2) {
                    ans += nums[0] * nums[1];
                }
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
