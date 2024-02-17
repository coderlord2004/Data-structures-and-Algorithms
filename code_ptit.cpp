
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int a[n], b[m], Min = min(m, n);
        for(int &x : a) cin >> x;
        for(int &y : b) cin >> y;
        sort(a, a+n); sort(b, b+m);
        int hop[m+n], giao[Min];
        int i=0, j = 0, hop_idx = 0, giao_idx = 0;
        while(i < n && j < m){
            if(a[i] == b[j]){
                hop[hop_idx++] = a[i++];
                giao[giao_idx++] = b[j++];
            }
            else if(a[i] < b[j]){
                hop[hop_idx++] = a[i++];
            }
            else hop[hop_idx++] = b[j++];
        }        
        while(i<n){
             hop[hop_idx++] = a[i++];
        }        
        while(j<m){
            hop[hop_idx++] = b[j++];
        } 
        for(int i=0; i<hop_idx; i++) cout << hop[i] << " ";
        cout << endl;
        for(int i=0; i<giao_idx; i++) cout << giao[i] << " ";
        cout << endl;
    }
}