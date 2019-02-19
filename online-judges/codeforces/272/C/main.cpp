/**
 * Problem: C. Dima and Staircase
 * Judge: CodeForces
 * Date: 02/18/2019
 * URL: http://codeforces.com/contest/272/problem/C
 * Tags: Data structures (Interval tree with lazy propagation)
 */
 
#include <bits/stdc++.h>
using namespace std;

int a[ 100005 ];
long long int tree[ 20 * 100005 ];
long long int lazy[ 20 * 100005 ];
int n, L, R;

int l_node(int node) {
  return node*2 + 1;
}
int r_node(int node) {
  return node*2 + 2;
}

long long build(int l, int r, int node) {
  if (l == r) {
    tree[ node ] = a[ l ];
    return tree[ node ];
  }
  if (l > r) return 0;
  int mid = (r + l) / 2;
  long long sl = build(l, mid, l_node(node));
  long long sr = build(mid+1, r, r_node(node));
  return tree[ node ] = max(sl, sr);
}

long long query(int l, int r, int node) {
  if (l>r || l > R || r < L){ 
    return 0;
  }
  if (lazy[ node ]) {
    tree[node] = lazy[ node ];
    if (l != r) {
      lazy[ l_node(node) ] = lazy[ node ];
      lazy[ r_node(node) ] = lazy[ node ];
    }
    lazy[ node ] = 0;
  }
  if (l >= L && r <= R) {
    return tree[ node ];
  }
  int mid = (r + l)/2; 
  long long sl = query(l, mid, l_node(node));
  long long sr = query(mid+1, r, r_node(node));
  return max(sl, sr);
}
long long query(int l, int r) {
  L = l;
  R = r;
  return query(0, n-1, 0);
}

long long update(int l, int r, int node, long long val) {
  if (lazy[ node ]) {
    tree[ node ] = max(tree[node], lazy[ node ]);
    if (l != r) {
      lazy[ l_node(node) ] = max(lazy[ l_node(node) ], lazy[ node ]);
      lazy[ r_node(node) ] = max(lazy[ r_node(node) ], lazy[ node ]);
    }
    lazy[ node ] = 0;
  }
  if (l > r || l > R || r < L) {
    return tree[node];
  }
  if (l >= L && r <= R) {
    tree[ node ] = max(val, tree[node]);
    if (l != r) {
      lazy[ l_node(node) ] = max(lazy[ l_node(node) ], val);
      lazy[ r_node(node) ] = max(lazy[ r_node(node) ], val);
    }
    return tree[ node ];
  }
  int mid = (l + r)/2; 
  long long sl = update(l, mid, l_node(node), val); 
  long long sr = update(mid+1, r, r_node(node), val);
  return tree[ node ] = max(sl, sr);
}
long long update(int l, int r, long long val) {
  L = l;
  R = r;
  update(0, n-1, 0, val);
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[ i ];
  }
  tree[ 0 ] = build(0, n-1, 0);
  int k;
  cin >> k;
  for (int i = 0; i < k; ++i) {
    long long w, h;
    cin >> w >> h;
    long long r = query(0, w -1);
    update(0, w-1, r+h);
    cout << r << '\n';
    
  }
  return 0;
}
