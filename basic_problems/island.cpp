#include<iostream>
using namespace std;

int main(){
   int mat[100][100];
  int i,n,m,j;
     cin >> n>> m;
    // scanf("%d%d",&n,&m);

  for(i=0;i<n;i++)
    for(j=0;j<m;j++)
      cin >> mat[i][j];

  int count = -1;

  for(i=0;i<n;i++)
    for(j=0;j<m;j++){
      if( j>=1 && mat[i][j-1]<0)
        mat[i][j] = mat[i][j-1];
      else if(j<m-1 && mat[i][j+1]<0)
        mat[i][j] = mat[i][j-1];
      else if(i>=1  && mat[i-1][j]<0)
        mat[i][j] = mat[i][j-1];
      else if(i<n-1 && mat[i+1][j]<0)
        mat[i][j] = mat[i][j-1];
      else{
        mat[i][j] = count;
        count--;
      }

    }
  cout << -count << endl;

  return 0;
}
