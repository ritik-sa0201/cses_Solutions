#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<string> result;
bool solved = false;

bool isValid(int r, int c, char ch) {
    if (r > 0 && result[r-1][c] == ch) return false;
    if (c > 0 && result[r][c-1] == ch) return false; 
    return true;
}

void backtrack(int r, int c) {
    if (r == n) { 
        solved = true;
        return;
    }

    int nr = (c == m-1 ? r+1 : r);
    int nc = (c == m-1 ? 0 : c+1);

    for (char ch : {'A','B','C','D'}) {
        if (ch == grid[r][c]) continue; 
        if (isValid(r, c, ch)) {
            result[r][c] = ch;
            backtrack(nr, nc);
            if (solved) return;
        }
    }
    result[r][c] = '.';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    grid.resize(n);
    result.assign(n, string(m, '.'));

    for (int i = 0; i < n; i++) cin >> grid[i];

    backtrack(0, 0);

    if (!solved) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) cout << result[i] << "\n";
    }
    return 0;
}
