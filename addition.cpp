#include<iostream>
using namespace std;
#include<string>

int main()
{
    string a,b;
    int i, n,m,carry=0,x,y;
    cin>>a>>b;
    // scanf("%s%s",a,b);
    n = a.size();
    m = b.size();
    int maxm = max(n,m);
    int p = n,q = m;
    string sum;
    // cout << maxm;

    while(p>0 && q>0){
      x = a[p-1]-48;
      y = b[q-1]-48;
       cout<<x << " <- x , y -> "<<y<<endl;
      int add = x+y + carry;
      carry = add/10;
      add = add%10;
      sum[maxm--] = add+48;
       cout << sum[maxm+1] << endl;
      p--,q--;
    }
     cout << p<< " p - q "<<q;


     if(p==0 && q!=0){

       sum[q-1] = carry + b[q-1] + 48;
       while(q>0){
        sum[q-1] = b[q-1];
        q--;
      }
     }
     else if(q==0 && p!=0){
     sum[p-1] = carry + a[p-1] + 48;
     while(p>0){
      sum[p-1] = a[p-1];
      p--;
    }
   }
    cout << sum<<endl;

  return 0;
}
