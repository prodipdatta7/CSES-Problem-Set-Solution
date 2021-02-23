/**
     *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
     *
     *  Prodip Datta
     *  Dept. Of Computer Science & Engineering
     *  Session: 2014-15
     *	email: prodipdatta7@gmail.com
     *  Bangabandhu Sheikh Mujibur Rahman Science & Technology University, Gopalganj-8100.
     *
     *  created : Monday 22-February, 2021  08:37:03 PM
**/

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <bitset>
#include <assert.h>
#include <new>
#include <sstream>
#include <time.h>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")

using namespace std ;
using namespace __gnu_pbds ;

#define     ll          long long
#define     ld          long double
#define     ull         unsigned long long
#define     pii         pair< int, int >
#define     pll         pair< ll, ll >
#define     vi          vector< int >
#define     vll         vector< ll >
#define     vvi         vector< vector< int > >
#define     vvii         vector< vector< pii > >
#define     debug(x)    cerr << #x << " = " << x << '\n' ;
#define     rep(i,b,e)  for(__typeof(e) i = (b) ; i != (e + 1) - 2 * ((b) > (e))  ; i += 1 - 2 * ((b) > (e)))
#define     all(x)      x.begin() , x.end()
#define     rall(x)     x.rbegin() , x.rend()
#define     sz(x)       (int)x.size()
#define     ff          first
#define     ss          second
#define     pb          push_back
#define     eb          emplace_back
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
#define     fread       freopen("input.txt","r",stdin)
#define     fwrite      freopen("output.txt","w",stdout)
#define     TN          typename
#define     FastIO      ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;

typedef tree <pii, null_type, less< pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree <pii, null_type, less_equal< pii >, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;

/*
Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag).
        lower_bound() works as upper_bound() and vice-versa.
        Be careful to use.
        i) find_by_order(k) : kth smallest element counting from 0 .
        ii) order_of_key(k) : number of elements strictly smaller than k.
*/

/*###############-> Input Section <-###############*/

template <TN T> inline void Int(T &a) {
	bool minus = false; a = 0; char ch = getchar();
	while (true) { if (ch == '-' or (ch >= '0' && ch <= '9')) break; ch = getchar(); }
	if (ch == '-') minus = true; else a = ch - '0';
	while (true) { ch = getchar(); if (ch < '0' || ch > '9') break; a = a * 10 + (ch - '0'); }
	if (minus)a *= -1 ;
}
template < TN T, TN T1 > inline void Int(T &a, T1 &b) {Int(a), Int(b) ;}
template < TN T, TN T1, TN T2 > inline void Int(T &a, T1 &b, T2 &c) {Int(a, b), Int(c) ;}
template < TN T, TN T1, TN T2, TN T3 > inline void Int(T &a, T1 &b, T2 &c, T3 &d) {Int(a, b), Int(c, d) ;}
template < TN T, TN T1, TN T2, TN T3, TN T4> inline void Int(T &a, T1 &b, T2 &c, T3 &d, T4 &e) {Int(a, b), Int(c, d, e) ;}
template<typename T, typename U> inline void cmin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void cmax(T &x, U y) { if (x < y) x = y; }

/*###############-> Debugger <-###############*/

#ifndef ONLINE_JUDGE
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<TN T, TN... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ' ;
	err(++it, args...);
}
#else
#define error(args...)
#endif

template<class ValueType>
bool unstable_remove(
        typename std::vector<ValueType>& container,
        typename std::vector<ValueType>::iterator it
) {
	auto lastEl = container.end() - 1;
	if (it != lastEl) {
		*it = std::move(*lastEl);
	}
	container.pop_back();
}

/******************************************
#Rows are numbered from top to bottom.
#Columns are numbered from left to right.
Moves : L, U, R, D, LU, RU, RD, LD.
******************************************/
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1} ;
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1} ;

/*###############-> Constraints <-###############*/

const int N          = (int)2e5 + 5 ;
const int maxN       = (int)5e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
const double EPS     = (double)1e-9 ;
const double PI      = (double)acos(-1.0) ;


inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}

/*...... ! Code starts from here ! ......*/

int T[maxN], L[maxN], R[maxN], root[maxN] ;
int version ;

void build(int i, int b, int e) {
	if (b == e) {
		T[i] = 0 ;
		return ;
	}
	int mid = b + e >> 1 ;
	L[i] = ++version ;
	R[i] = ++version ;
	build(i << 1, b, mid) ;
	build(i << 1 | 1, mid + 1, e) ;
}

int update(int i, int b, int e, int pos) {
	if (pos < b or pos > e)return i ;
	int cur = ++version ;
	if (b == e) {
		T[cur] = T[i] + 1 ;
		return cur ;
	}
	int mid = b + e >> 1 ;
	L[cur] = update(L[i], b, mid, pos) ;
	R[cur] = update(R[i], mid + 1, e, pos) ;
	T[cur] = T[L[cur]] + T[R[cur]] ;
	return cur ;
}


int countNotSmaller(int i, int b, int e, int k) {
	if (e <= k)return 0 ;
	if (b > k)return T[i] ;
	int mid = b + e >> 1 ;
	return countNotSmaller(L[i], b, mid, k) + countNotSmaller(R[i], mid + 1, e, k) ;
}


int main() {
#ifndef ONLINE_JUDGE
	clock_t tStart = clock();
	//freopen("input.txt", "r", stdin) ;
	//freopen("output.txt", "w", stdout) ;
#endif
	int test = 1 , tc = 0 ;
	// Int(test) ;
	while (test--) {
		int n, q ; Int(n, q) ;
		vector < int > a(n + 1) ;
		for (int i = 1 ; i <= n ; ++i) {
			Int(a[i]) ;
		}
		vector < ll > suffixSum(n + 5, 0), suffixResult(n + 5, 0) ;
		stack < int > helper ;
		vector < int > nextNotSmaller(n + 5, n + 1) ;
		for (int i = n ; i >= 1 ; --i) {
			suffixSum[i] += suffixSum[i + 1] + a[i] ;
			if (helper.empty()) {
				helper.push(i) ;
				suffixResult[i] = suffixResult[i + 1] ;
			}
			else {
				while (!helper.empty() and a[helper.top()] < a[i]) {
					helper.pop() ;
				}
				if (!helper.empty()) {
					nextNotSmaller[i] = helper.top() ;
					suffixResult[i] = 1LL * (helper.top() - i) * a[i] - (suffixSum[i] - suffixSum[helper.top()]) + suffixResult[helper.top()] ;
				}
				else {
					suffixResult[i] = 1LL * (n + 1 - i) * a[i] - suffixSum[i] ;
				}
				helper.push(i) ;
			}
		}
		// for(int i = 1 ; i <= n ; ++i){
		// 	error(i, a[i], suffixSum[i], nextNotSmaller[i])
		// }
		// values = nextNotSmaller;
		root[0] = 0 ;
		build(0, 0, n + 1) ;
		for (int i = 1 ; i <= n ; ++i) {
			int v = nextNotSmaller[i] ;
			// error(v, i)
			root[i] = update(root[i - 1], 0, n + 1, v) ;
		}
		while (q--) {
			int L, R ; Int(L, R) ;
			int l = L, r = R, pos = R + 1 ;
			int extra = countNotSmaller(root[L - 1], 0, n + 1, R) ;
			// error(extra)
			while (l <= r) {
				int mid = l + r >> 1 ;
				int greaterValues = countNotSmaller(root[mid], 0, n + 1, R) ;
				// error(L, mid, greaterValues)
				if (greaterValues - extra > 0) {
					pos = mid ;
					r = mid - 1 ;
				}
				else l = mid + 1 ;
			}
			ll operations = 1LL * (R - pos + 1) * a[pos] - (suffixSum[pos] - suffixSum[R + 1]) + suffixResult[L] - suffixResult[pos] ;
			printf("%lld\n", operations);
		}
	}

#ifndef ONLINE_JUDGE
	fprintf(stderr, "\nRuntime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
	return 0 ;
}
