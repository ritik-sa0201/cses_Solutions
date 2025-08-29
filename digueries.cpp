#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int q;
    cin >> q;
    while (q--) {
        long long k;
        cin >> k;

        long long d = 1;
        long long lb = 1;
        long long ub = 9;

       
        while (true) {
            long long count = (ub - lb + 1) * d;
            if (k > count) {
                k -= count;
                d++;
                lb *= 10;
                ub = ub * 10 + 9; 
            } else {
                break;
            }
        }

        long long off = (k-1) / d;
        long long pos = (k-1) % d;
        long long num = lb + off;

        string s = to_string(num);
        cout << s[pos] << "\n";
    }
    return 0;
}
