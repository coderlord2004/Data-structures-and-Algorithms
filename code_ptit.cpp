#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        ll a[n];
        for(ll &x : a) cin >> x;
        sort(a, a+n);
        ll dem = 0;
        for(int i=0; i<n-2; i++){
            if(a[i] > k) break;
            for(int j=i+1; j<n-1; j++){
                auto key = lower_bound(a+j+1, a+n, k-a[i]-a[j]);
                dem += (key - (a+j+1));
            }
        }
        cout << dem << endl;
    }
}