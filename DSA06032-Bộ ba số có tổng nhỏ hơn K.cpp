
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int first_pos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x){
            res = m;
            r = m-1;
        }
        else if(a[m] < x) l = m+1;
        else r = m-1;
    }
    return res;
}
int last_pos(int a[], int l, int r, int x){
    int res = -1;
    while(l <= r){
        int m = (l+r)/2;
        if(a[m] == x){
            res = m;
            l = m+1;
        }
        else if(a[m] < x) l = m+1;
        else r = m-1;
    }
    return res;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        int a[n];
        map<int, int> mp;
        for(int &x : a) {
            cin >> x;
            mp[x]++;
        }
        sort(a, a+n);
        ll cnt = 0;
        for(int i=0; i<n; i++){
            int key1 = last_pos(a, i+1, n-1, k-a[i]);
            int key2 = first_pos(a, i+1, n-1, k-a[i]);
            if(key1 != -1){
                cnt += (key1 - key2 + 1); 
            }
        }        
        cout << cnt << endl;
   }
}
