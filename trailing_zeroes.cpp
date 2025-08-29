#include <bits/stdc++.h>
using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}


int main() {
    int n;
    cin >> n;  
    cout<<trailingZeroes(n);
    return 0;
}