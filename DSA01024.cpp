/*
Kỳ thi ICPC có K đội của PTIT tham gia và đội tuyển đang rất đau đầu không biết chọn các cái tên như thế nào cho các đội. Yêu cầu phải đảm bảo tên không có khoảng trống và không được trùng nhau. Sau khi thảo luận, có N cái tên được đề xuất (có thể bị trùng nhau). Với K<15 và 4 < N < 30.

Hãy liệt kê tất cả danh sách các tổ hợp K cái tên khác nhau có thể được tạo ra theo thứ tự từ điển.

Input

Dòng đầu ghi 2 số N và K.

Tiếp theo là 1 dòng ghi N cái tên, mỗi cái tên có độ dài không quá 15 và cách nhau một khoảng trống. Tất cả đều là ký tự in hoa.

Output

Ghi ra tất cả các tổ hợp tên có thể được lựa chọn theo thứ tự từ điển.

Tức là các tên trong mỗi tổ hợp liệt kê theo thứ tự từ điển và các tổ hợp cũng được liệt kê theo thứ tự từ điển.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x[100];
int n, k;
vector<vector<string>> v;
vector<string> a;

void Try(int i){
    for(int j=x[i-1]+1; j<=(a.size()-k+i); j++){
        x[i] = j;
        if(i == k){
            vector<string> b;
            for(int c=1; c<=k; c++){
                b.push_back(a[x[c]-1]); //Coi tổ hợp x[c] chọn được là chỉ số của vector a. 
            }
            v.push_back(b);
        }
        else Try(i+1);
    }
}
int main(){
    cin >> n >> k;
    // Loại bỏ các từ trùng nhau:
    map<string, int> mp;
    for(int i=0; i<n; i++){
        string x; cin >> x;
        mp[x]++;
        if(mp[x] == 1) {
            a.push_back(x);
        }
    }
    sort(a.begin(), a.end()); // Sắp xếp các tên theo thứ tự từ điển.
    Try(1);
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}