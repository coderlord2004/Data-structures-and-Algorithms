#include<bits/stdc++.h>
using namespace std;
int n, k;
int x[100], a[100];
vector<vector<int>> v;
void Try(int i){
    for(int j=0; j<=1; j++){
        x[i] = j;
        if(i == n){
            int sum = 0;
            for(int c=1; c<=n; c++){
                if(x[c]){
                    sum += a[c];
                }
            }
            if(sum == k){
                vector<int> b;
                for(int c=1; c<=n; c++){
                    if(x[c]){
                        b.push_back(a[c]);
                    }
                }
                v.push_back(b);
            }
        }
        else Try(i+1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1);
        Try(1);
        if(v.empty() == true) cout << -1 << endl;
        else {
            sort(v.begin(), v.end());
            for(int i=0; i<v.size(); i++){
                cout << "[";
                for(int j=0; j<v[i].size(); j++){
                    if(j < v[i].size()-1) cout << v[i][j] << " ";
                    else cout << v[i][j] << "] ";
                }
            }
            cout << endl;
            v.clear();

        }
    }
}