#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    long long target = sum / 2;

    vector<int> set1, set2;
    for (int i = n; i >= 1; i--) {
        if (i <= target) {
            set1.push_back(i);
            target -= i;
        } else {
            if(i==target){
                set1.push_back(i);
            }
            else set2.push_back(i);
        }
    }
    sort(set1.begin(),set1.end());
    sort(set2.begin(),set2.end());
    cout << set1.size() << "\n";
    for (int x : set1) cout << x << " ";
    cout << "\n";

    cout << set2.size() << "\n";
    for (int x : set2) cout << x << " ";
    cout << "\n";
}
