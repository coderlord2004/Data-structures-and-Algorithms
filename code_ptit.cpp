/*
Cho mảng A[] gồm n phần tử. Hãy tìm số phép đổi chỗ ít nhất
giữa các phần tử của mảng để mảng A[] được sắp xếp. Ví dụ với A[] = {4, 3, 2, 1}
ta cần thực hiện ít nhất 2 phép đổi chỗ: Swap(A[0], A[3]),  Swap(A[1], A[2]).
*/
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
        sort(a, a+n); // so sánh 2 mảng a đã sắp xếp với mảng b chưa sắp xếp và đếm số lần đổi chỗ ít nhất.
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(b[i] != a[i]){ //tìm thấy phần tử đã bị swap.
                int min_pos = i; // tìm vị trí của phần tử nhỏ nhất và swap với phần tử hiện tại.
                for(int j = i+1; j<n; j++){
                    if(b[min_pos] > b[j]) min_pos = j;
                }
                swap(b[i], b[min_pos]);
                ++cnt;
            }
       }
       cout << cnt << endl;
    }
}