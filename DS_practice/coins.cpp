#include<iostream>
using namespace std;
// #include<bits/stdc++.h>
#include "/Users/yahnit/Documents/stdc++.h"


int getLowerBound(int a[], int n, int ele){
	int l = 0, r = n-1;
	int ans = n;

	while(l <= r){
		int mid = (l+r) >> 1;

		if(a[mid] < ele){
			l = mid + 1;
		}
		else{
			r = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

void getChange(int n, int cur[]){
    while(n > cur[9]){
      cout << cur[9] << " ";
      n-= cur[9];
    }
    while(n > 0){
        // int lwr_bound = getLowerBound(cur, 10, n);
        int lwr_bound = lower_bound(cur, cur + 10, n) - cur;

        if(cur[lwr_bound] > n)
          lwr_bound--;

        cout << cur[lwr_bound] << " ";
        n -= cur[lwr_bound];
    }
    cout << endl;
    return;
}

int main()
 {
     int t;
     cin >> t;
     int cur[10] =  { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
     while(t--){
         int n;
         cin >> n;
         getChange(n, cur);
        //  cout << ans << endl;
     }

	return 0;
}
