#include<iostream>
using namespace std;

// Longest Subarray having sum of elements atmost ‘k’
// Given an array of integers, our goal is to find the
// length of largest subarray having sum of its elements
// atmost ‘k’ where k>0.


// Can it have negative elements?
// can budget be 0?
int maxLen(int a[], int n, int budget){
  int max_len = 0;
  int l = 0, r = -1, sum = 0;

  while(l != n && r != n-1){

    while(r < n-1){
      r++;
      sum += a[r];
      if(sum <= budget)
        max_len = max(r-l+1, max_len);
      else
        break;
    }

    while(l <= r){
      sum -= a[l];
      l++;
      if(sum <= budget)
        break;
    }
  }


  return max_len;
}

// IMP CODE FOR 2 POINTERS
int maxLen1(int a[], int n, int budget){
  int max_len = 0;
  // subarray from l to r-1
  int l = 0, r = 0, sum = 0;

  while(!(l == n && r == n)){

    while(r < n){
      sum += a[r];
      r++;

      if(sum <= budget)
        max_len = max(r-l, max_len);
      else
        break;

    }

    while(l < r){
      sum -= a[l];
      l++;
      if(sum <= budget)
        break;
    }
  }


  return max_len;
}

int maxLen2(int a[], int n, int budget){
  int max_len = 0;
  // subarray from l to r-1
  int l = 0, j,r = 0, sum = 0;

  for(int i=l;i<n;i++){
    for(j = r;j<n;j++){
        sum += a[j];
        if(sum > budget)
          break;
    }
    r = j;
    max_len = max(max_len, r - l);
    while(sum > budget){
      sum -= a[l];
      l++;
    }
    i = l;
  }


  return max_len;
}


int max_sum_subarray_k(int a[], int n, int budget){
  int l = 0 , r = 0 , sum = 0;
  int max_sum = 0;

  for(int j=0;j<n;j++){
    sum += a[j];
    while(sum > budget){
      sum -= a[l];
      l++;
    }
    max_sum = max(max_sum, sum);
  }
  return max_sum;
}

int main(){

  int n, a[10001],k;
  cin >> n >> k;
  for(int i=0;i<n;i++)
    cin >> a[i];

    // cout << maxLen2(a, n, k) << endl;
    cout << max_sum_subarray_k(a, n, k) << endl;

  return 0;
}
