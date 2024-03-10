
#include<bits/stdc++.h>
using namespace std;
int a[100], used[100], n;
void in(){
  for(int i=1; i<=n; i++) cout << (char)(a[i]+64);
  cout << endl;
}
void check(){
    if(n<5){
        if((char)(a[1] + 64) == 'A' || (char)(a[n] + 64) == 'A'){
          in();
        }
    }
     else {
        char x1 = (char)(a[1] + 64), x2 = (char)(a[n] + 64);
        if(x1 == 'A' && x2 == 'E') in();
        else if(x1 == 'E' && x2 == 'A') in();
        else {
          for(int i=1; i<=n-1; i++){
            if((char)(a[i] + 64) == 'A' && (char)(a[i+1] + 64) == 'E') {
              in();
              break;
            }
            else if((char)(a[i] + 64) == 'E' && (char)(a[i+1] + 64) == 'A'){
               in();
               break;
            }
          }
        }
    }
}
void Try(int i){
    for(int j=1; j<=n; j++){
      if(used[j] == 0){
        used[j] = 1;
        a[i] = j;
        if(i == n){
           check();
        }
        else Try(i+1);
        used[j] = 0;
      }
    }
}
int main(){ 
    char c;
    cin >> c;
    n = (int)c - 64;  
    Try(1);
}