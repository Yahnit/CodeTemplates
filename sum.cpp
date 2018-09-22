#include<iostream>
using namespace std;
#include<string>

int main()
{
  string a,b, sum;
  cin >> a >> b;
  int len_a, len_b;
  len_a = a.size();
  len_b = b.size();
  int len_sum = max(len_a,len_b)+1;
  int carry = 0;
int x,y;

  while(len_a > 0 || len_b > 0){
    // int x = a[len_a-1] ?  a[len_a-1] - '0' : 0;
    // int y = b[len_b-1] ?  b[len_b-1] - '0' : 0;

    if(len_a>0)
      x = a[len_a-1] - '0';
    else
    x = 0;

    if(len_b>0)
      y = b[len_b-1] - '0';
    else
      y = 0;

    // int addn = a[len_a-1] - '0' + b[len_b-1] - '0' + carry;
    int addn = x+y+carry;
    sum[len_sum-1] = addn%10 + '0';
    carry = addn/10;
    len_a--,len_b--,len_sum--;
  }

  sum[0] = carry + '0';
  for(int i=0;i<max(a.size(),b.size()) + 1;i++)
    cout << sum[i];

      return 0;
}
