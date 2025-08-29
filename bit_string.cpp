#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& arr, int n) {
    // TODO: implement logic here
}

int main() {
    int n;
    int mod = 1e9+7;
    cin >> n;  
   long long ans = 1;

    for(int i=1;i<=n;i++){
        ans = (ans*2)%mod;
    }
   cout<<ans;
    return 0;
}