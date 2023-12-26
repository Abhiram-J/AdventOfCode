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
int maxi = 0;
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void bfs(vector<string> &grid, int x, int y, int dist,
         vector<vector<bool>> &vis) {
    int n = grid.size(), m = grid[0].size();

    queue<tuple<int, int, int>> q;
    q.push({x, y, dist});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        int x = get<0>(p), y = get<1>(p), dist = get<2>(p);
        if (vis[x][y]) continue;
        maxi = max(maxi, dist);
        vis[x][y] = true;
        if (isValid(x, y + 1, n, m) &&
            (grid[x][y + 1] == '-' || grid[x][y + 1] == 'J' ||
             grid[x][y + 1] == '7')) {
            q.push({x, y + 1, dist + 1});
        }
        if (isValid(x + 1, y, n, m) &&
            (grid[x + 1][y] == '|' || grid[x + 1][y] == 'J' ||
             grid[x + 1][y] == 'L')) {
            q.push({x + 1, y, dist + 1});
        }
        if (isValid(x, y - 1, n, m) &&
            (grid[x][y - 1] == '-' || grid[x][y - 1] == 'F' ||
             grid[x][y - 1] == 'L')) {
            q.push({x, y - 1, dist + 1});
        }
        if (isValid(x - 1, y, n, m) &&
            (grid[x - 1][y] == '|' || grid[x - 1][y] == 'F' ||
             grid[x - 1][y] == '7')) {
            q.push({x - 1, y, dist + 1});
        }
    }
}

void solve() {
    vector<string> grid;
    string temp;
    while (cin >> temp) {
        grid.push_back(temp);
    }
    int x = 0, y = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'S') {
                x = i;
                y = j;
                break;
            }
        }
    }
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
    bfs(grid, x, y, 0, vis);
    cout << maxi;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
