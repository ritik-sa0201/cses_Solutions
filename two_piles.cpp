#include <bits/stdc++.h>
using namespace std;

int solve(long long a,long long b) {
  long long sum = a+b;
  if(sum%3!=0)return -1;
  long long maxi = max(a,b);
  long long mini = min(a,b);
   if(2*mini>=maxi){
    return 1;
   }
   else{
    return -1;
   }
}

int main() {
    int t;
    cin >> t;  
   
    for(int i=0;i<t;i++){
        long long a;long long b;
        cin>>a;
        cin>>b;
       int ans = solve(a,b);
       if(ans==-1){
        cout<<"NO\n";
       }
       else cout<<"YES\n";
    }
    
    return 0;
}