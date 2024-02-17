/*Cho mảng A[] gồm n phần tử. Hãy tìm số phép đổi chỗ ít nhất giữa các phần tử 
của mảng để mảng A[] được sắp xếp. Ví dụ với A[] = {4, 3, 2, 1}
ta cần thực hiện ít nhất 2 phép đổi chỗ: Swap(A[0], A[3]),  Swap(A[1], A[2]). */

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n], b[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a+n);
        int cnt = 0;
        for(int i=0; i<n; i++){
            
            if(b[i] != a[i]){
                int min_pos = i;
                for(int j = i+1; j<n; j++){ // với mỗi phần tử a[i] tìm phần tử nhỏ nhất sau nó.
                    if(b[min_pos] > b[j]) min_pos = j;
                }
                swap(b[i], b[min_pos]); //hoán vị phần tử hiện tại với phần tử nhỏ nhất sau nó.
                ++cnt;
            }
       }
       cout << cnt << endl;
    }
}
