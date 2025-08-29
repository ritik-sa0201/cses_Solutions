#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& arr, int n) {
  long long ans=0;
  for(int i=1;i<arr.size();i++){
    if(arr[i]==arr[i-1])continue;
    if(arr[i]<arr[i-1]){
        ans+=arr[i-1]-arr[i];
        arr[i] += arr[i-1]-arr[i];
    }
  }
  return ans;
}

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; 
    }

   long long ans =  solve(arr, n);
   cout<<ans;
    return 0;
}