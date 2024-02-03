// MergeSort và đếm số cặp nghịch thế với độ phức tạp O(nlog(n));

#include<bits/stdc++.h>
using namespace std;
int Merge(int a[], int l, int mid, int r){
    vector<int> x(a+l, a+mid+1);
    vector<int> y(a+mid+1, a+r+1);
    int i = 0, j = 0, dem = 0;
    while(i<x.size() && j < y.size()){
        if(x[i] <= y[j]){
            a[l++] = x[i++];
        }
        else {
            a[l++] = y[j++];
            dem += (x.size() - i); /*nếu có 1 cặp nghịch thế x[i]>y[j] (i<j) thì tất cả các phần tử
                                     sau i cũng tạo thành cặp nghịch thế với y[j] nên số cặp nghịch thế bằng x.size()-i;*/
        }
    }
    while (i < x.size())
    {
        a[l++] = x[i++];
    }
    while (j < y.size())
    {
        a[l++] = y[j++];
    }
    return dem;
}
void mergeSort(int a[], int l, int r){
    int dem = 0; //khi l=r thì dem = 0;
    if(l<r){
        int mid = (l+r)/2;
        dem += mergeSort(a, l, mid);
        dem += mergeSort(a, mid+1, r);
        dem += Merge(a, l, mid, r);
    }
    return dem;
}
int main(){
    int t; cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int &x : a) cin >> x;
        cout <<"Số cặp nghịch thế: " mergeSort(a, 0, n-1) << endl;
    }
}