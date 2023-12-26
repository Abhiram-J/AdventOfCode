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

// have to use ray tracing algorithm
bool isValid(int x, int y, int n, int m) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

bool rayTrace(vector<string> &grid, int x, int y) {
    int n = grid.size(), m = grid[0].size();
    int left = 0, up = 0;
    int f = 0, j = 0, l = 0, s = 0;
    for (int i = y - 1; i >= 0; i--) {
        if (grid[x][i] == 'F') f++;
        if (grid[x][i] == 'J') j++;
        if (grid[x][i] == 'L') l++;
        if (grid[x][i] == '7') s++;
        if (grid[x][i] == '|') left++;
    }
    left += min(f, j) + min(l, s);

    f = 0, j = 0, l = 0, s = 0;
    for (int i = x - 1; i >= 0; i--) {
        if (grid[i][y] == 'F') f++;
        if (grid[i][y] == 'J') j++;
        if (grid[i][y] == 'L') l++;
        if (grid[i][y] == '7') s++;
        if (grid[i][y] == '-') up++;
    }
    up += min(f, j) + min(l, s);
    return up % 2;
}

void findS(vector<string> &grid) {
    int n = grid.size(), m = grid[0].size();
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                x = i, y = j;
            }
        }
    }
    char left = grid[x][y - 1], right = grid[x][y + 1];
    char up = grid[x - 1][y], down = grid[x + 1][y];

    if ((left == 'F' || left == '-' || left == 'L') &&
        (down == 'J' || down == '|' || down == 'L')) {
        grid[x][y] = '7';
    } else if ((left == 'F' || left == '-' || left == 'L') &&
               (up == '7' || up == '|' || up == 'F')) {
        grid[x][y] = 'J';
    } else if ((right == '7' || right == '-' || right == 'J') &&
               (down == 'J' || down == '|' || down == 'L')) {
        grid[x][y] = 'F';
    } else if ((right == '7' || right == '-' || right == 'J') &&
               (up == '7' || up == '|' || up == 'F')) {
        grid[x][y] = 'L';
    } else if ((left == 'F' || left == '-' || left == 'L') &&
               (right == '7' || right == '-' || right == 'J')) {
        grid[x][y] = '-';
    } else if ((up == '7' || up == '|' || up == 'F') &&
               (down == 'J' || down == '|' || down == 'L')) {
        grid[x][y] = '|';
    }
}
void mark(vector<string> &grid, int x, int y, vector<vector<bool>> &vis) {
    int n = grid.size(), m = grid[0].size();
    if (!isValid(x, y, n, m)) return;
    if (vis[x][y]) return;

    char c = grid[x][y];

    vis[x][y] = true;
    if (c == 'S') {
        if (isValid(x, y + 1, n, m) &&
            (grid[x][y + 1] == 'J' || grid[x][y + 1] == '7' ||
             grid[x][y + 1] == '-')) {
            mark(grid, x, y + 1, vis);
        }
        if (isValid(x + 1, y, n, m) &&
            (grid[x + 1][y] == 'J' || grid[x + 1][y] == 'L' ||
             grid[x + 1][y] == '|')) {
            mark(grid, x + 1, y, vis);
        }
        if (isValid(x, y - 1, n, m) &&
            (grid[x][y - 1] == 'F' || grid[x][y - 1] == 'L' ||
             grid[x][y - 1] == '-')) {
            mark(grid, x, y - 1, vis);
        }
        if (isValid(x - 1, y, n, m) &&
            (grid[x - 1][y] == 'F' || grid[x - 1][y] == '7' ||
             grid[x - 1][y] == '|')) {
            mark(grid, x - 1, y, vis);
        }
    }
    if (c == 'J') {
        if (isValid(x, y - 1, n, m) &&
            (grid[x][y - 1] == 'F' || grid[x][y - 1] == 'L' ||
             grid[x][y - 1] == '-')) {
            mark(grid, x, y - 1, vis);
        }
        if (isValid(x - 1, y, n, m) &&
            (grid[x - 1][y] == 'F' || grid[x - 1][y] == '7' ||
             grid[x - 1][y] == '|')) {
            mark(grid, x - 1, y, vis);
        }
    }
    if (c == 'L') {
        if (isValid(x, y + 1, n, m) &&
            (grid[x][y + 1] == 'J' || grid[x][y + 1] == '7' ||
             grid[x][y + 1] == '-')) {
            mark(grid, x, y + 1, vis);
        }
        if (isValid(x - 1, y, n, m) &&
            (grid[x - 1][y] == 'F' || grid[x - 1][y] == '7' ||
             grid[x - 1][y] == '|')) {
            mark(grid, x - 1, y, vis);
        }
    }
    if (c == '7') {
        if (isValid(x, y - 1, n, m) &&
            (grid[x][y - 1] == 'F' || grid[x][y - 1] == 'L' ||
             grid[x][y - 1] == '-')) {
            mark(grid, x, y - 1, vis);
        }
        if (isValid(x + 1, y, n, m) &&
            (grid[x + 1][y] == 'J' || grid[x + 1][y] == 'L' ||
             grid[x + 1][y] == '|')) {
            mark(grid, x + 1, y, vis);
        }
    }
    if (c == 'F') {
        if (isValid(x, y + 1, n, m) &&
            (grid[x][y + 1] == 'J' || grid[x][y + 1] == '7' ||
             grid[x][y + 1] == '-')) {
            mark(grid, x, y + 1, vis);
        }
        if (isValid(x + 1, y, n, m) &&
            (grid[x + 1][y] == 'J' || grid[x + 1][y] == 'L' ||
             grid[x + 1][y] == '|')) {
            mark(grid, x + 1, y, vis);
        }
    }
    if (c == '|') {
        if (isValid(x + 1, y, n, m) &&
            (grid[x + 1][y] == 'J' || grid[x + 1][y] == 'L' ||
             grid[x + 1][y] == '|')) {
            mark(grid, x + 1, y, vis);
        }
        if (isValid(x - 1, y, n, m) &&
            (grid[x - 1][y] == 'F' || grid[x - 1][y] == '7' ||
             grid[x - 1][y] == '|')) {
            mark(grid, x - 1, y, vis);
        }
    }
    if (c == '-') {
        if (isValid(x, y + 1, n, m) &&
            (grid[x][y + 1] == 'J' || grid[x][y + 1] == '7' ||
             grid[x][y + 1] == '-')) {
            mark(grid, x, y + 1, vis);
        }
        if (isValid(x, y - 1, n, m) &&
            (grid[x][y - 1] == 'F' || grid[x][y - 1] == 'L' ||
             grid[x][y - 1] == '-')) {
            mark(grid, x, y - 1, vis);
        }
    }
}

void solve() {
    vector<string> grid;
    string temp;
    while (cin >> temp) {
        grid.push_back(temp);
    }
    int x = 0, y = 0, ans = 0, cnt = 0;
    vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 'S') mark(grid, i, j, vis);
        }
        cout << newl;
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (!vis[i][j]) grid[i][j] = '.';
        }
    }
    findS(grid);

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '.') {
                ans += rayTrace(grid, i, j);
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
