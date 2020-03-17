#include<bits/stdc++.h>
using namespace std;
const int N =2e5+5;
const long long M = (long long)1e9+7;
#define     ll      long long
#define     ull     unsigned long long
int Int() {
    int x;
    scanf("%d",&x);
    return x;
}
ll Long() {
    ll x;
    scanf("%lld",&x);
    return x;
}
void Char(char* ch) {
    scanf("%s",ch);
}
template<typename t>inline t abs(t a) {
    if(a>=0)
        return a;
    return -a;
}
template<typename T> inline T modpow(T b, T p, T Mod) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
            res %= Mod ;
        }
        b *= b;
        b %= Mod;
        p >>= 1;
    }
    return res ;
}
 
template<typename T> inline T ModInv(T b, T Mod) {
    return modpow(b, Mod - 2, Mod );
}
 
template<typename T> inline T pwr(T b, T p) {
    T res  = 1;
    while(p) {
        if(p&1) {
            res *= b ;
        }
        b *= b;
        p >>= 1;
    }
    return res ;
}
 
template<typename T> inline T gcd(T a, T b) {
    if(b==0)
        return a;
    return gcd(b, a%b);
}
 
template <typename T> inline void Int(T &n) {
    n = 0;
    int f = 1;
    register int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        n = (n << 3) + (n << 1) + ch - '0';
    n = n * f;
}
template<typename T, typename U> inline void Int(T &a, U &b) {
    Int(a);
    Int(b);
}
template<typename T, typename U, typename W> inline void Int(T &a, U &b, W &c) {
    Int(a,b);
    Int(c);
}
template<typename T, typename U, typename W,typename X> inline void Int(T &a, U &b, W &c, X &d) {
    Int(a,b,c);
    Int(d);
}
vector<int> Unique(vector<int> v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    return v;
}
///error///
#define error(args...) {vector<string>_v=split(#args,',');err(_v.begin(),args);cout<<endl;}
vector<string> split(const string &s,char c) {
    vector<string>v;
    stringstream ss(s);
    string x;
    while(getline(ss,x,c))
        v.emplace_back(x);
    return move(v);
}
 
void err(vector<string>::iterator it) {}
template<typename T,typename... Args>
void err(vector<string>::iterator it,T a,Args...args) {
    cout<<it->substr((*it)[0]==' ',it->length())<< " = " << a << " ";
    err(++it,args...);
}
///This DEBUGGER-tool need c++11///
#define     Int         Int()
#define     Long        Long()
#define     pii         pair<int,int>
#define     ff          first
#define     ss          second
#define		pb			push_back
#define     all(x)      x.begin(),x.end()
#define     mem(a)      memset(a,0,sizeof a)
#define     memn(a)     memset(a,-1,sizeof a)
 
struct BIT {
    ll res[N] ;
    BIT() {
        for(int i = 0 ; i <= N  ; i++)
            res[i] = 0 ;
    }
 
    void upd(int i, int v) {
        while(i <= N ) {
            res[i] += 1LL*v ;
            i += (i & -i) ;
        }
    }
 
    ll query(int i) {
        ll s = 0 ;
        while(i) {
            s += res[i] ;
            i -= (i & -i) ;
        }
        return s ;
    }
} bit;
 
std::vector<int> g[N],v(N);
int id[N], sz[N], tmr ;
 
void dfs(int s , int p = - 1){
	tmr++;
	id[s] = tmr ;
	sz[s] = 1 ;
	bit.upd(tmr,v[s]);
	for(int i = 0 ; i < (int)g[s].size() ; i++){
		int u = g[s][i] ;
		if(u == p)continue;
		dfs(u,s);
		sz[s] += sz[u] ;
	}
}
 
 
int main() {
    int n = Int , q = Int ;
    for(int i = 1 ; i <= n ; i++){
    	v[i] = Int ;
    }
    for(int i = 1 ; i < n ; i++){
    	int l = Int, r = Int ;
    	g[l].pb(r);
    	g[r].pb(l);
    }
    dfs(1);
    while(q--){
    	int f = Int ;
    	if(f == 1){
    		int s = Int, x = Int ;
    		bit.upd(id[s],-1*v[s]);
    		bit.upd(id[s],x);
    		v[s] = x ;
    	}
    	else{
    		int node = Int ;
    		ll sum = bit.query(id[node] + sz[node] - 1) - bit.query(id[node] - 1);
    		printf("%lld\n",sum);
    	}
    }
    return 0;
}
