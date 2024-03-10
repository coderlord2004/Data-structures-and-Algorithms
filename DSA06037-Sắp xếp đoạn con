/*
Cho dãy số nguyên A[] độ dài N. Xác định số lượng chỉ số M (M < N) thỏa mãn: nếu sắp xếp đoạn con (A1,…,AM) và (AM+1, …, AN) theo thứ tự tăng dần thì được dãy số A tăng dần.

Input

Dòng đầu tiên ghi số bộ test T
Mỗi bộ test bắt đầu bằng một dòng chứa số N (2 ≤ N ≤ 105)
Dòng tiếp theo ghi N số của dãy A (|Ai| ≤ 109)
Output

Với mỗi bộ test:

Dòng đầu tiên ghi số K là số lượng vị trí M tìm được
Dòng thứ 2 ghi ra K số theo thứ tự tăng dần lần lượt là các chỉ số thỏa mãn. Nếu K = 0 thì dòng này bỏ trống. 
*/
//Ý tưởng: duyệt lần lượt các phần tử của mảng, với mỗi phần tử có chỉ số i đang xét tìm MAX của mảng bên trái từ j=0 -> j=i và MIN của j=i+1 -> j=n-1 bằng cách sử dụng multiset.
#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t; cin >> t;
    while(t--){
      int n; cin >> n;
      int a[n];
      multiset<int> l, r;
      for(int i=0; i<n; i++) {
        cin >> a[i];
        if(i>=1) r.insert(a[i]);
      }
      int cnt_pos = 0;
      vector<int> v;
      for(int i=0; i<n-1; i++){
        l.insert(a[i]);
        if(*(l.rbegin()) <= *(r.begin())){
          ++cnt_pos;
          v.push_back(i+1);
        }
        r.erase(r.find(a[i+1]));
      }
      cout << cnt_pos << endl;
      for(int i=0; i<v.size(); i++) cout << v[i] << " ";
      cout << endl;
    }
}
