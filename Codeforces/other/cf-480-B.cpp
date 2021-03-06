#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int T,n,m,k;

int main()
{
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    vector<string> v(4, string(n, '.'));
    if (k%2 == 0){
        rep(i,0,k/2){
            v[1][i + 1] = v[2][i + 1] = '#';
        }
    }
    else{
        v[1][n / 2] = '#';
        rep(i,0,k/2){
            rep(j,0,k/2){
                int x = 1 + j % 2;
                int y = j / 2 + 1;
                v[x][y] = v[x][n - y - 1] = '#';
            }
        }
    }
    cout << "YES" << endl;
    rep(i,0,4){
        cout << v[i] << endl;
    }

    return 0;
}