#include <bits/stdc++.h>
using namespace std;

class Solution {
    set<string> st; // use set to avoid duplicates
public:

    void solve(int i, string &s) {
        if(i == s.size()) {
            st.insert(s); // store only unique permutations
            return;
        }

        for(int j=i; j<s.size(); j++) {
            swap(s[i], s[j]);
            solve(i+1, s);
            swap(s[i], s[j]);
        }
    }

    vector<string> generate(string s) {
        solve(0, s);
        // copy set to vector (automatically sorted)
        return vector<string>(st.begin(), st.end());
    }
};

int main() {
    string s;
    cin >> s;

    Solution sol;
    vector<string> res = sol.generate(s);

    cout << res.size() << "\n";
    for(auto &str : res) {
        cout << str << "\n";
    }
}
