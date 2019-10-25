#include<iostream>
using namespace std;
#include<list>

list <int> queue;
list <int> adj[1001];


void bfs(int node, bool visited[]){
  visited[node] = true;
  queue.push_back(node);

  while(!queue.empty()){
    int top = queue.front();
    queue.pop_front();

    for(auto i = adj[top].begin(); i!= adj[top].end();i++){
      if(!visited[*i]){
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
  return;
}

int binary_search(int a[], low, high, ele){

  while(low <= high){
    int mid = (high+low) >> 1;
    if(a[mid] == a)
      return 1;
    else if(a[mid] < a)
      low = mid+1;
    else
      high = mid-1;
  }
return 0;
}

int upper_bound(int a[], int low, int high, int ele){
  int res = high+1;

  while(low <= high){
    int mid = (high+low)>>1;

    if(a[mid]<=ele)
      low = mid+1;
    else{
      res = mid;
      high = mid-1;
    }
  }
return res;
}

void dfs(int node){
  visited[node] = true;

  for(auto i=adj[node]).begin();i!=adj[node].end();++i)
    if(!visited[*i])
      dfs(*i)
return;
}

Node* LCA(Node* root, int x, int y){
  if (root == NULL)
    return NULL;

  if(root->val == x || root->val == y)
    return root;

    left_lca = LCA(root->left, x, y);
    right_lca = LCA(root->right, x, y);

    if (left_lca && right_lca)
      return root;

  return (left_lca!=NULL)?left_lca:right_lca;
}

Node * insert(Node* root, int val){
  if(root == NULL)
    return createNode(val);

  if(val < root->val)
    root->left = insert(root->left, val);
  else
    root->right = insert(root->right, val);

  return root;
}

Node* search(Node* root, int val){
    if(root == NULL)
      return NULL;
    if(root->val == val)
      return root;
    if(val < root->val)
      Node* search_node = search(root->left, val);
    else
      Node* search_node = search(root->right, val);

    return search_node;
}

Node* find_nearest_leaf(Node* root, int level){
  if(root == NULL)
    return level;

    int left_tree = find_nearest_leaf(root->left, near+1);
    int right_tree = find_nearest_leaf(root->right, near+1);

    return min(left_tree, right_tree);
}

void heap_insert(int heap[], int max, int ele){
  while(max >= 1){
    int parent = (max - 1) >> 1;

    if(ele <= heap[parent]){
      heap[ind] = ele;
      return;
    }

    if(heap[parent] < ele){
      heap[max] = heap[parent];
      max = parent;
    }

  }
  heap[0] = ele;
  return;
}

int heapify(int heap[], int n, int i){
  int big = i, left = 2*i+1, right = 2*i+2;

  if(left < n && heap[left] > heap[big])
    big = left;
  if(right < n && heap[right] > heap[big])
    big = right;

  int temp = heap[i];
  heap[i] = heap[big];
  heap[big] = temp;

  if(big!=i)
    heapify(heap, n, big)
  return 0;
}

int gcd(int a, int b){
    if(b==0)
      return a;

    return gcd(b, a%b);
}

void rotate(int a[], int d, int n){
  for(i=0;i<gcd(n,d);i++){
    int temp = a[i];
    int ind = i;

    while(1){
      a[ind] = a[ind+d];
      ind = (ind+d)%n;
      if(ind == i)
        break;
    }
    a[(ind-d)%n] = temp;
  }
return;
}

int pivot(int a[], int n){
  int mid;
  int low = 0, high = n-1;

  while(low<=high){
    int mid = (high+low)>>1;

    if(a[mid-1] > a[mid] && a[mid] < a[mid+1])
      return mid;

    if(a[low] > a[mid])
      high = mid;

    if (a[mid] > a[high])
      low = mid;
  }
return -1;
}

int check_pair_sum(int a[], int n, int sum){
  map <int ,int> mp;
  for(i=;0;i<n;i++){
    mp[a[i]] = 1;

    if(mp[sum-a[i]] == 1)
      return 1;
  }
return 0;
}

int max_palindrome_subseq(int dp[][10000], int str, int low, int high){
  if(dp[low][high] != -1)
    return dp[low][high];

  if(low > high)
    return -1;

  if(low == high)
    return 1;

  if(str[low] == str[high]){
    dp[low+1][high-1] = max_palindrome_subseq(dp, str, low+1, high-1);
    dp[low][high] = 2 + dp[low+1][high-1];
  }

  dp[low][high-1] = max_palindrome_subseq(dp, str, low, high-1);
  dp[low+1][high] = max_palindrome_subseq(dp, str, low+1, high);

  dp[low][high] = max(dp[low][high-1], dp[low+1][high]);

return dp[low][high];
}

int max_palindrome_substring(int dp[][10000], int str, int low, int high){
  if(dp[low][high] != -1)
    return dp[low][high];

  if(low > high)
    return -1;

  if(low == high)
    return 1;

  if(low + 1 == high && str[low] == str[high])
    return 1;

  if(str[low] == str[high]){
    dp[low+1][high-1] = max_palindrome_substring(dp, str, low+1, high-1);
    return dp[low+1][high-1];
  }

  dp[low+1][high] = max_palindrome_substring(dp, str, low+1, high);
  dp[low][high-1] = max_palindrome_substring(dp, str, low, high-1);

  return 0;
}

int LCS(int dp[][10000], int s1, int s2, int m, int n){
  if(dp[low][high] != -1)
    return dp[low][high];

  if(m <= 0 || n <= 0)
    return 0;

  if(s1[m-1] == s2[n-1]){
    dp[m-1][n-1] = LCS(dp, s1, s2, m-1, n-1);
    dp[m][n] = 1 + dp[m-1][n-1];
    return dp[m][n];
  }

  dp[m-1][n] = LCS(dp, s1, s2, m-1, n);
  dp[m][n-1] = LCS(dp, s1, s2, m, n-1);
  dp[m][n] = max(dp[m-1][n], dp[m][n-1]);

  return dp[m][n];
}
