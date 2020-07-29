/**
 *  “Experience is the name everyone gives to their mistakes.” – Oscar Wilde
 *
 *  author  :   prodipdatta7
 *  created :   Monday 16-March, 2020  11:05:43 PM
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
#define     pii         pair<int,int>
#define     pll         pair<ll,ll>
#define     vi          vector<int>
#define     vll         vector<ll>
#define     vvi         vector<vector<int>>
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
 
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
 
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
 
/*###############-> Debugger <-###############*/
 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {cout << endl ;}
template<TN T, TN... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << ' ' ;
    err(++it, args...);
}
 
/******************************************
#Rows are numbered from top to bottom.
#Columns are numbered from left to right.
Moves : L, U, R, D, LU, RU, RD, LD.
******************************************/
int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1} ;
int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1} ;
 
/*###############-> Constraints <-###############*/
 
const int N          = (int)1e3 + 5 ;
const int maxN       = (int)1e6 + 6 ;
const ll  Mod        = (ll)1e9 + 7 ;
const int inf        = (int)2e9 ;
const ll  Inf        = (ll)1e18 ;
const int mod        = (int)1e9 + 7 ;
 
 
inline int add(int a, int b, int mod) {a += b ; return a >= mod ? a - mod : a ;}
inline int sub(int a, int b, int mod) {a -= b ; return a < 0 ? a + mod : a ;}
inline int mul(int a, int b, int mod) {return (ll)a * b % mod ;}
 
/*...... ! Code starts from here ! ......*/
 
 
int vis[N][N], n, m ;
string s[N] ;
int par[N][N], d[N][N] ;
 
bool valid(int x, int y){
    return x >= 0 and x < n and y >= 0 and y < m ;
}
 
void get(int &x, int &y, string &s, int tp){
    if(tp == 0)x += dx[2], y += dy[2], s += 'L' ;
    else if(tp == 1)x += dx[3], y += dy[3], s += 'U' ;
    else if(tp == 2)x += dx[0], y += dy[0], s += 'R' ;
    else x += dx[1], y += dy[1], s += 'D' ;
}
 
bool bfs(int x, int y){
    queue < pii > q ;
    vis[x][y] = 1 ;
    q.push({x, y}) ;
    string path = "" ;
    while(!q.empty()){
        auto p = q.front() ;
        q.pop() ;
        for(int i = 0 ; i < 4 ; ++i){
            int u = p.ff + dx[i], v = p.ss + dy[i] ;
            if(valid(u, v) and !vis[u][v] and s[u][v] != '#'){
                d[u][v] = 1 + d[p.ff][p.ss] ;
                par[u][v] = i ;
                if(s[u][v] == 'B'){
                    puts("YES") ;
                    cout << d[u][v] << '\n' ;
                    while(s[u][v] != 'A'){
                        get(u, v, path, par[u][v]) ;
                    }
                    reverse(all(path)) ;
                    cout << path << '\n' ;
                    exit(0) ;
                }
                vis[u][v] = 1 ;
                q.push({u, v}) ;
            }
        }
    }
}
 
int main() {
    // ios_base::sync_with_stdio(false) ;
    // cin.tie(NULL) ; cout.tie(NULL) ;
    int test = 1 , tc = 0 ;
    //Int(test) ;
    while (test--) {
        Int(n, m) ;
        int x = -1, y = -1 ;
        for(int i = 0 ; i < n ; ++i){
            cin >> s[i] ;
            if(~x)continue ;
            for(int j = 0 ;  j < m ; ++j){
                if(s[i][j] == 'A'){
                    x = i, y = j ;
                    break ;
                }
            }
        }
        bfs(x, y) ;
        puts("NO") ;
    }
    return 0 ;
}
