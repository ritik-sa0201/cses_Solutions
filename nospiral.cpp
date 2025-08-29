#include <bits/stdc++.h>
using namespace std;

void print(int n,vector<vector<int>>&mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<"\n";
    }
}


void solve(int n) {
    vector<vector<int>>mat(n,vector<int>(n,0));
         int i=1;
         int r=0,c=0;
         bool right=true;
         bool down=false;
         bool flag=false;
         bool left=false;
         

         while(r!=n && c!=n){
            mat[r][c] = i;
            i++;
         
            if(right){
                int curr=c;
                while(curr<c+1){
                curr++;
                down=true;
                left=false;
                right=false;
                }
                c=curr;
            }
            else if(down){
                int curr=r;
                while(curr<r+1){
                r++;
                left=true;
                down=false;
                right=false;
                }
                r=curr;
            }
            else if(left){
                int curr=c;
                while(curr>=0){
                curr--;
                down=true;
                right=false;
                left=false;
                }
                c=curr;
            }
         }


    print(n,mat);
}

int main() {
    int n;
    cin >> n;  

    // vector<int> arr(n);
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];  
    // }

    solve(n);
    return 0;
}