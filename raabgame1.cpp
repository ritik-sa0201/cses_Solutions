#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n) {
            cout << "NO\n";
            continue;
        }
    
        if ((a == 0 && b > 0) || (b == 0 && a > 0)) {
            cout << "NO\n";
            continue;
        }

        vector<int> A(n), B(n, 0);
        iota(A.begin(), A.end(), 1);

        unordered_set<int> used;
        used.reserve(n * 2);

        // Ties
        for (int i = b; i < n - a; ++i) {
            B[i] = A[i];    
            used.insert(A[i]);
        }

        int cur = n;
        for (int i = b - 1; i >= 0; --i) {
            while (used.count(cur)) --cur;
            B[i] = cur;
            used.insert(cur);
        }

        cur = 1;
        for (int i = n - a; i < n; ++i) {
            while (used.count(cur)) ++cur;
            B[i] = cur;
            used.insert(cur);
        }

        int ra = a, rb = b;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (B[i] < 1 || B[i] > n) { ok = false; break; }
            if (A[i] > B[i]) --ra;
            else if (A[i] < B[i]) --rb;
        }
        if (!ok || ra != 0 || rb != 0) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << A[i];
        }
        cout << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << B[i];
        }
        cout << '\n';
    }
    return 0;
}